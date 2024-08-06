#include "..\include\ScavMod\Logger.h"

#include "iostream"

void ScavMod::Logger::Log(Ogre::String message)
{
	std::cout << "[LOG]: " << message << "\n";
}