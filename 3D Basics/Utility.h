#pragma once
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

#include <WS2tcpip.h>
#include <iostream>
#include <string>
#include <strstream>
#include "Dependencies\glm\glm.hpp"

#define VALIDATE(a) if (!a) return (false)

enum GameMode
{
	GAMEMODE_2D,
	GAMEMODE_3D
};


class Utility
{
private:

	static Utility * instance;

	int screenWidth = 1024;
	int screenHeight = 768;
	GameMode gameMode = GAMEMODE_2D;

public:
	static Utility * GetInstance()
	{
		if (instance == NULL)
		{
			instance = new Utility();
		}
		return instance;
	}

	static int GetScreenWidth();
	static int GetScreenHeight();
	static glm::vec2 GetScreenSize();
	static GameMode GetGameMode();

	static void Update();
	static void ShutDown();

	template<typename T>
	static void Print(const T& value)
	{
		std::strstream theStream;
		theStream << value << std::ends;

		std::cout << theStream.str() << std::endl;
	}

	
	template<typename T>
	static std::string ToString(const T& value)
	{
		std::strstream theStream;
		theStream << value << std::ends;
		return (theStream.str());
	}
};
