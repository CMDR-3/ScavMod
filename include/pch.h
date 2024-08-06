// would be the precompiled headers file but I'm too lazy to edit every imgui file to support it :))

#ifndef PCH_H
#define PCH_H

#include "framework.h"
#include "MinHook.h"
#include "d3d9.h"
#include "d3dx9.h"
#include "kiero.h"

#pragma comment(lib, "minhook.x32.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#endif //PCH_H
