#pragma once

namespace ScavMod
{
	enum MixinType
	{
		REPLACE,
		FOOTER,
		HEADER
	};

	class Mixin
	{
	public:
		/*
		target: The pointer in memory to the function you are targeting
		rerouted: The pointer in memory to the hooked version of the function
		type: The type of the mixin to be used in error checking and crashlogs (Make sure to set it properly!!)
		*/
		Mixin(void* target, void* rerouted, MixinType type);
	private:
		
	};
}