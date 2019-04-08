#pragma once

// Vertices and Textures
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

#include <vector>
#include <thread>
#include <string>

class ShaderLoader;
class Scene;
class StartMenuScene;
class GameScene;
class AudioSound;
class Level1;



class Application
{
public:
	static Application * GetInstance();

	static void PlayGame(int argc, char **argv);
	void Initialise();
	static void Render();
	static void Update();
	
	static void QuitGame();
	

	float deltaTime;

private:

	// Singleton
	Application();
	~Application();
	Application(const Application& copy) {};
	Application& operator= (const Application& move) {};

	static void ShutDownGame();

	static Application * instance;
	

	GLuint program;
	
	// For deltatime
	float previousTimeStamp;

	Scene * startMenuScene = NULL;
	Scene * gameScene = NULL;
	Scene * level1 = NULL;
	

	std::vector<Scene*> scenes;

	AudioSound * backgroundMusic = NULL;

};

