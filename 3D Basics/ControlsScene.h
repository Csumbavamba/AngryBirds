#pragma once
#include "Scene.h"

class UI_Button;
class UI_Image;
class UI_Text;
class AudioSound;

class ControlsScene :
	public Scene
{
public:
	ControlsScene();
	virtual ~ControlsScene();

	virtual void Initialise() override;
	virtual void Render(GLuint program) override;
	virtual void Update(float deltaTime) override;

private:
	UI_Button * backButton = NULL;
	UI_Image * backgroundImage = NULL;
	UI_Text * buttonDescription = NULL;
	AudioSound * clickSound = NULL;

	UI_Text * textsOnScreen[13];

	UI_Text * attackDefense = NULL;
	UI_Text * highAttack = NULL;
	UI_Text * midAttack = NULL;
	UI_Text * lowAttack = NULL;

	// Player One - Attack/Defend - QAZ
	UI_Text * playerOne = NULL;
	UI_Text * high1 = NULL;
	UI_Text * mid1 = NULL;
	UI_Text * low1 = NULL;
	
	// Player Two - Attack/Defend - MKO
	UI_Text * playerTwo = NULL;
	UI_Text * high2 = NULL;
	UI_Text * mid2 = NULL;
	UI_Text * low2 = NULL;

};

