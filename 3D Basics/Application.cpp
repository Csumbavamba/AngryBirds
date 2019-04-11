#include "Application.h"

#include "Camera.h"
#include "ShaderLoader.h"
#include "Utility.h"
#include "Input.h" 
#include "AudioSound.h"
#include "AudioEngine.h"
#include "Physics2D.h"

// Scenes
#include "Scene.h"
#include "SceneManager.h"
#include "StartMenuScene.h"
#include "GameScene.h"
#include "Level1.h"
#include "Level2.h"

#pragma comment(lib, "Ws2_32.lib")

Application * Application::instance = NULL;

Application::Application()
{
	deltaTime = 0.0f;

	// Create Scenes
	startMenuScene = new StartMenuScene();
	startMenuScene->SetIsActiveScene(true);
	gameScene = new GameScene();
	level1 = new Level1();
	level2 = new Level2();
	
	// Push Scenes into the scene Holder
	scenes.push_back(startMenuScene);
	scenes.push_back(gameScene);
	scenes.push_back(level2); // TODO add level 1

	backgroundMusic = new AudioSound("Audio/AngryBirdsTheme.mp3", LOOPING);

	SceneManager::AddScenes(scenes);
}


Application::~Application()
{
	// Scenes
	for (Scene * scene : scenes)
	{
		delete scene;
		scene = NULL;
	}

	scenes.clear();

	delete backgroundMusic;
	backgroundMusic = NULL;

	// Static Deletes
	Physics2D::ShutDown();
	AudioEngine::Shutdown();
	SceneManager::ShutDown();
	ShaderLoader::ShutDown();
	Input::ShutDown();
	Utility::ShutDown();
}

Application * Application::GetInstance()
{
	if (instance == NULL)
	{
		instance = new Application();
	}
	return instance;;
}

void Application::PlayGame(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Angry Birds - by Tom and kinda Zsombi");

	glClearColor(1.0, 0.0, 0.0, 1.0); // Clear Window


	glewInit(); // ADD FUNCTIONS AFTER THIS

	//// Enable Culling
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK); 

	//// Enable Depth for Rendering -- See if that causes error
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// Blend between textures
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GetInstance()->Initialise();

	glutDisplayFunc(Render);
	glutIdleFunc(Update);

	// Input stuff
	glutKeyboardFunc(Input::KeyboardDown);
	glutKeyboardUpFunc(Input::KeyboardUp);
	glutSpecialFunc(Input::SpecialKeyboardDown);
	glutSpecialUpFunc(Input::SpecialKeyboardUp);
	glutMouseFunc(Input::MouseClick);
	glutMotionFunc(Input::MouseActiveMove);
	glutPassiveMotionFunc(Input::MousePassiveMove);

	glutCloseFunc(Application::ShutDownGame);
	glutMainLoop();

	return;
}

void Application::Initialise()
{
	// Create Programs
	program = ShaderLoader::GetInstance()->CreateProgram("VertexShader.vs", "FragmentShader.fs");

	// Deltatime calculation
	previousTimeStamp = (float)glutGet(GLUT_ELAPSED_TIME);

	// Initialize the Scenes
	for (Scene * scene : scenes)
	{
		scene->Initialise();
	}

	
	backgroundMusic->PlaySound();
	backgroundMusic->SetVolume(0.1f);
}

void Application::Render()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0); // clear red

	
	// Do rendering here - Render Current Scene
	SceneManager::GetActiveScene()->Render(GetInstance()->program);

	glBindVertexArray(0); // Unbind VAO
	glUseProgram(0);

	glutSwapBuffers();
}

void Application::Update()
{
	// Time Calculation
	float currentTime = (float)glutGet(GLUT_ELAPSED_TIME);
	GetInstance()->deltaTime = (currentTime - GetInstance()->previousTimeStamp) * 0.001f;
	GetInstance()->previousTimeStamp = currentTime;

	// Update Screen size
	Utility::Update();

	// Update the Audio Engine
	AudioEngine::Update();


	// Update the Current Scene
	SceneManager::GetActiveScene()->Update(GetInstance()->deltaTime);

	// Last function call
	glutPostRedisplay();
}

void Application::QuitGame()
{
	glutLeaveMainLoop();
}




void Application::ShutDownGame()
{
	delete instance;
	instance = NULL;
}

