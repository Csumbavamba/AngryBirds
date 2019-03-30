#include "ControlsScene.h"

#include "UI_Button.h"
#include "UI_Image.h"
#include "UI_Text.h"
#include "Utility.h"
#include "AudioSound.h"
#include "Input.h"
#include "SceneManager.h"

ControlsScene::ControlsScene()
{
	
	// Create Texts on the screen
	buttonDescription = new UI_Text("Press Enter to Return", glm::vec2(0.0f, -Utility::GetScreenHeight() / 2.0f + 50.0f));

	// Attack text
	attackDefense = new UI_Text("Attack / Defense", glm::vec2(-350.0f, Utility::GetScreenHeight() / 2.0f - 150.0f));
	highAttack = new UI_Text("High", glm::vec2(-350.0f, Utility::GetScreenHeight() / 2.0f - 250.0f));
	midAttack = new UI_Text("Mid", glm::vec2(-350.0f, Utility::GetScreenHeight() / 2.0f - 300.0f));
	lowAttack = new UI_Text("Low", glm::vec2(-350.0f, Utility::GetScreenHeight() / 2.0f - 350.0f));

	//// Player 1
	playerOne = new UI_Text("Player One", glm::vec2(0.0f, Utility::GetScreenHeight() / 2.0f -150.0f));
	high1 = new UI_Text("Q", glm::vec2(0.0f, Utility::GetScreenHeight() / 2.0f - 250.0f));
	mid1 = new UI_Text("A", glm::vec2(0.0f, Utility::GetScreenHeight() / 2.0f - 300.0f));
	low1 = new UI_Text("Z", glm::vec2(0.0f, Utility::GetScreenHeight() / 2.0f - 350.0f));

	//// Player 2
	playerTwo = new UI_Text("Player Two", glm::vec2(350.0f, Utility::GetScreenHeight() / 2.0f - 150.0f));
	high2 = new UI_Text("O", glm::vec2(350.0f, Utility::GetScreenHeight() / 2.0f - 250.0f));
	mid2 = new UI_Text("K", glm::vec2(350.0f, Utility::GetScreenHeight() / 2.0f - 300.0f));
	low2 = new UI_Text("M", glm::vec2(350.0f, Utility::GetScreenHeight() / 2.0f - 350.0f));

	textsOnScreen[0] = buttonDescription;
	textsOnScreen[1] = attackDefense;
	textsOnScreen[2] = highAttack;
	textsOnScreen[3] = midAttack;
	textsOnScreen[4] = lowAttack;

	// Player 1
	textsOnScreen[5] = playerOne;
	textsOnScreen[6] = high1;
	textsOnScreen[7] = mid1;
	textsOnScreen[8] = low1;

	// Player 2
	textsOnScreen[9] = playerTwo;
	textsOnScreen[10] = high2;
	textsOnScreen[11] = mid2;
	textsOnScreen[12] = low2;


	// Create the button
	backButton = new UI_Button("MAIN MENU", glm::vec2(
		0.0f,
		-Utility::GetScreenHeight() / 2.0f + 100.0f));

	// Create the background image
	backgroundImage = new UI_Image(mainCamera, "Sprites/background.jpg", Utility::GetScreenSize());

	// Setup Audio
	clickSound = new AudioSound("Audio/Click.wav", DEFAULT);

	sceneName = "ControlsScene"; // TODO Create method to get this from file
}


ControlsScene::~ControlsScene()
{
	delete backButton;
	backButton = NULL;

	delete backgroundImage;
	backgroundImage = NULL;

	for (int i = 0; i < 13; i++)
	{
		delete textsOnScreen[i];
		textsOnScreen[i] = NULL;
	}


	delete clickSound;
	clickSound = NULL;
}

void ControlsScene::Initialise()
{

}

void ControlsScene::Render(GLuint program)
{
	backgroundImage->Render(NULL);
	backButton->Render(NULL);
	buttonDescription->Render(NULL);

	for (int i = 0; i < 13; i++)
	{
		textsOnScreen[i]->Render(NULL);
	}

}

void ControlsScene::Update(float deltaTime)
{
	// First call
	Scene::Update(deltaTime);

	backgroundImage->Update(deltaTime);
	backButton->Update(deltaTime);

	for (int i = 0; i < 13; i++)
	{
		textsOnScreen[i]->Update();
	}

	// Check when Enter is pressed
	if (Input::GetKeyState(13) == DOWN_FIRST)
	{
		// Switch Scene
		SceneManager::ChangeActiveScene("StartMenuScene");
	}
}
