#pragma once

class RenderPath3D;

class wiGUI;
class wiWindow;
class wiLabel;
class wiCheckBox;
class wiSlider;
class wiButton;

class PostprocessWindow
{
public:
	PostprocessWindow(wiGUI* gui, RenderPath3D* component);
	~PostprocessWindow();

	wiGUI* GUI;
	RenderPath3D* component;

	wiWindow*	ppWindow;
	wiCheckBox* lensFlareCheckBox;
	wiCheckBox* lightShaftsCheckBox;
	wiCheckBox* ssaoCheckBox;
	wiCheckBox* ssrCheckBox;
	wiCheckBox* sssCheckBox;
	wiCheckBox* eyeAdaptionCheckBox;
	wiCheckBox* motionBlurCheckBox;
	wiCheckBox* depthOfFieldCheckBox;
	wiSlider*	depthOfFieldFocusSlider;
	wiSlider*	depthOfFieldStrengthSlider;
	wiCheckBox* bloomCheckBox;
	wiCheckBox* fxaaCheckBox;
	wiCheckBox* stereogramCheckBox;
	wiCheckBox* colorGradingCheckBox;
	wiButton*	colorGradingButton;
	wiCheckBox* sharpenFilterCheckBox;
	wiSlider*	sharpenFilterAmountSlider;


};

