#pragma once

#ifdef _WIN32
	#define SVEXPORT __declspec(dllexport)
#else
	#error "_WIN32 NOT DEFINED. ScavMod ONLY supports Windows at the moment!"
#endif /* _WIN32 */

#include "..\ScavMod\Mixin\Mixin.h"
#include "..\ScavMod\Logger.h"
#include "..\ScavMod\Mod\IModDevice.h"

#include "..\Ogre.h"