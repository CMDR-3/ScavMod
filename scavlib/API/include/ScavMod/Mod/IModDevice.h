#pragma once

namespace ScavMod
{
	class IModDevice
	{
	public:
		virtual ~IModDevice() = default;
		
		/* Called when the modloader first sets up your mod */
		/* WARNING: Game may not be fully initalized at this point! */
		virtual void OnInit() = 0;

		/* Called when the renderer *starts* rendering the frame */
		/* (You can call ImGui stuff in here and it will render) */
		virtual void OnRenderUpdate() = 0;
	};
}