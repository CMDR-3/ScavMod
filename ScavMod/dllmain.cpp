#include "pch.h"

#include "iostream"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_dx9.h>
#include <imgui/imgui_impl_win32.h>

#include "ScavMod/ScavMod.h"

#pragma comment(lib, "scavlib.lib")

#include "sstream"
#include <vector>

#include "filesystem"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef long(__stdcall* EndScene)(LPDIRECT3DDEVICE9);
static EndScene oEndScene = NULL;

typedef int(__stdcall* setCursorPos_T)(int, int);
static setCursorPos_T osetCursorPos = NULL;

WNDPROC oWndProc;
static HWND window = NULL;

HMODULE mod = 0;
std::vector<ScavMod::IModDevice> Mods;

void InitImGui(LPDIRECT3DDEVICE9 pDevice)
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX9_Init(pDevice);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam)
{
	DWORD wndProcId;
	GetWindowThreadProcessId(handle, &wndProcId);

	if (GetCurrentProcessId() != wndProcId)
		return TRUE; // skip to next window

	window = handle;
	return FALSE; // window found abort search
}

HWND GetProcessWindow()
{
	window = NULL;
	EnumWindows(EnumWindowsCallback, NULL);
	return window;
}

bool init = false;
long __stdcall hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	if (!init)
	{
		InitImGui(pDevice);
		init = true;
	}

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImGui::ShowDemoWindow();

	for (auto mod : Mods)
		mod.OnRenderUpdate();

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

	return oEndScene(pDevice);
}

void Start()
{
	static bool firstStart = false;

	if (!firstStart) {
		firstStart = true;

		bool attached = false;
		while (!attached)
		{
		    if (kiero::init(kiero::RenderType::D3D9) == kiero::Status::Success)
		    {
		        kiero::bind(42, (void**)&oEndScene, hkEndScene);
		        do
		            window = GetProcessWindow();
		        while (window == NULL);
		        oWndProc = (WNDPROC)SetWindowLongPtr(window, GWL_WNDPROC, (LONG_PTR)WndProc);
		        attached = true;
		    }
		}
	
	} /* first start */
}

std::string GetModulePath(HMODULE hModule) {
	char path[MAX_PATH];
	if (GetModuleFileNameA(0, path, MAX_PATH) == 0) {
		return "";
	}
	return std::string(path);
}

typedef ScavMod::IModDevice* (*CreateMod)();

void LoadMod(std::filesystem::path ModPath)
{
	HMODULE mod = LoadLibraryA(ModPath.string().c_str());

	if (mod)
	{
		CreateMod loadMod = reinterpret_cast<CreateMod>(GetProcAddress(mod, "LoadMod"));

		ScavMod::IModDevice* modDev = loadMod();

		ScavMod::Logger::Log("Loaded mod " + ModPath.relative_path().string() + "!");

		modDev->OnInit();
	}
	else
	{
		ScavMod::Logger::Log("FAILED to load " + ModPath.string() + "! Skipping...");
		return;
	}
}

void LoadMods()
{
	ScavMod::Logger::Log("Loading mods...");
	ScavMod::Logger::Log("Getting path...");

	std::string path = GetModulePath(mod);
	ScavMod::Logger::Log("Got path!\n"+path);

	std::filesystem::path execPath(path);
	execPath = execPath.parent_path();

	std::filesystem::path modsPath(execPath.string() + "\\Mods\\");

	for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(modsPath))
	{
		if (dirEntry.is_regular_file())
		{
			ScavMod::Logger::Log("Loading mod " + dirEntry.path().relative_path().string() + "...");
			LoadMod(dirEntry);
		}
	}
}

void CreateThread(void* Func)
{
	HANDLE thread = CreateThread(
		nullptr,
		0,
		reinterpret_cast<LPTHREAD_START_ROUTINE>(Func),
		mod,
		0,
		nullptr
	);

	if (thread)
		CloseHandle(thread);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	MH_Initialize();

	DisableThreadLibraryCalls(hModule);

	mod = hModule;

	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);
	std::cout << "Console Created!" << std::endl;

	CreateThread(LoadMods);

	return TRUE;
}

