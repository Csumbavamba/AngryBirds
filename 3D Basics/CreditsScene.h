#pragma once
#include "Scene.h"

class UI_Button;
class UI_Image;
class AudioSound;
class UI_Text;

class CreditsScene :
	public Scene
{
public:
	CreditsScene();
	virtual ~CreditsScene();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime) override;

private:
	UI_Button * backButton = NULL;
	UI_Text * buttonDescription = NULL;
	UI_Image * backgroundImage = NULL;
	AudioSound * clickSound = NULL;

	UI_Text * zsombi = NULL;
	UI_Text * louis = NULL;
	UI_Text * sunny = NULL;
	UI_Text * tom = NULL;

	UI_Text * textsOnScreen[5];
};

