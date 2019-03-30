#include "CreditsScene.h"

#include "UI_Button.h"
#include "UI_Image.h"
#include "UI_Text.h"
#include "Utility.h"
#include "AudioSound.h"
#include "Input.h"
#include "SceneManager.h"

#include "Utility.h"

CreditsScene::CreditsScene()
{
	backButton = new UI_Button("MAIN MENU", glm::vec2(
		0.0f, 
		-Utility::GetScreenHeight() / 2.0f + 100.0f));

	buttonDescription = new UI_Text("Press Enter to Return", glm::vec2(0.0f, -Utility::GetScreenHeight() / 2.0f + 50.0f));
	backgroundImage = new UI_Image(mainCamera, "Sprites/DwarfBackground.jpg", Utility::GetScreenSize());

	sunny = new UI_Text("Sunny Peebles", glm::vec2(0.0f, 150.0f));
	louis = new UI_Text("Louis Cresswell", glm::vec2(0.0f, 75.0f));
	zsombi = new UI_Text("Zsombor Pirok", glm::vec2(0.0f, 0.0f));
	tom = new UI_Text("Thomas Sheppard", glm::vec2(0.0f, -75.0f));

	textsOnScreen[0] = buttonDescription;
	textsOnScreen[1] = sunny;
	textsOnScreen[2] = louis;
	textsOnScreen[3] = zsombi;
	textsOnScreen[4] = tom;

	for (int i = 1; i < 5; i++)
	{
		textsOnScreen[i]->SetScale(.8f);
	}
	
	// Setup Audio
	clickSound = new AudioSound("Audio/Click.wav", DEFAULT);

	sceneName = "CreditsScene"; // TODO Create method to get this from file
}


CreditsScene::~CreditsScene()
{
	delete backButton;
	backButton = NULL;

	for (int i = 0; i < 5; i++)
	{
		delete textsOnScreen[i];
		textsOnScreen[i] = NULL;
	}

	delete backgroundImage;
	backgroundImage = NULL;

	delete clickSound;
	clickSound = NULL;
}

void CreditsScene::Initialise()
{
}

void CreditsScene::Render(GLuint program)
{
	backgroundImage->Render(NULL);
	backButton->Render(NULL);

	for (int i = 0; i < 5; i++)
	{
		textsOnScreen[i]->Render(NULL);
	}
}

void CreditsScene::Update(float deltaTime)
{
	// First call
	Scene::Update(deltaTime);

	backgroundImage->Update(deltaTime);
	backButton->Update(deltaTime);
	

	for (int i = 0; i < 5; i++)
	{
		textsOnScreen[i]->Update();
	}

	// Check when Enter is pressed
	if (Input::GetKeyState(13) == DOWN_FIRST)
	{
		// Switch Scene
		SceneManager::ChangeActiveScene("StartMenuScene");
	}

	backButton->AdjustButtonPosition();

}
