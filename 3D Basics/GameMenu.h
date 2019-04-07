#pragma once
#include "GameObject.h"

class UI_Button;
class UI_Image;
class Camera;
class AudioSound;

class GameMenu :
	public GameObject
{
public:
	GameMenu(Camera * mainCamera);
	virtual ~GameMenu();
	
	virtual void Render(GLuint program) override;
	void Update(float deltaTime);
	void Reset();

	void ProcessKeyboardNavigation();
	void ProcessKeyboardClicks();
	void ChangeSelectedButton(int change);
	void ActOnMenuChoice();
	void ClickButton();

private:

	virtual void Initialise() override {};

	UI_Button * buttons[2];
	int buttonSelected;
	
	UI_Button * startButton = NULL;
	UI_Button * quitButton = NULL;

	AudioSound * clickSound = NULL;
	AudioSound * swapSound = NULL;
	UI_Image * backgroundImage = NULL;

};

