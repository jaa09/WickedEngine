#pragma once 
#include "CommonInclude.h"
#include "wiGraphicsDevice.h"
#include "wiColor.h"


// Do not alter order because it is bound to lua manually
enum wiFontAlign
{
	WIFALIGN_LEFT,
	// same as mid
	WIFALIGN_CENTER,
	// same as center
	WIFALIGN_MID,
	WIFALIGN_RIGHT,
	WIFALIGN_TOP,
	WIFALIGN_BOTTOM,
	WIFALIGN_COUNT,
};

struct wiFontProps
{
	int size;
	int spacingX, spacingY;
	int posX, posY;
	wiFontAlign h_align, v_align;
	wiColor color;
	wiColor shadowColor;

	wiFontProps(int posX = 0, int posY = 0, int size = -1, wiFontAlign h_align = WIFALIGN_LEFT, wiFontAlign v_align = WIFALIGN_TOP
		, int spacingX = 0, int spacingY = 0, const wiColor& color = wiColor(255, 255, 255, 255), const wiColor& shadowColor = wiColor(0,0,0,0))
		:posX(posX), posY(posY), size(size), h_align(h_align), v_align(v_align), spacingX(spacingX), spacingY(spacingY), color(color), shadowColor(shadowColor)
	{}
};

class wiFont
{
public:
	static void Initialize();
	static void CleanUp();

	static void LoadShaders();
	static void BindPersistentState(GRAPHICSTHREAD threadID);

	std::wstring text;
	wiFontProps props;
	int style;

	wiFont(const std::string& text = "", wiFontProps props = wiFontProps(), int style = 0);
	wiFont(const std::wstring& text, wiFontProps props = wiFontProps(), int style = 0);
	~wiFont();

	
	void Draw(GRAPHICSTHREAD threadID);


	int textWidth();
	int textHeight();

	// Create a font. Returns fontStyleID that is reusable. If font already exists, just return its ID
	static int AddFontStyle(const std::string& fontName, int height = 16);
	// Returns the style ID that is reusable. If font not found, returns -1
	static int GetFontStyle(const std::string& fontName, int height = 16);

	void SetText(const std::string& text);
	void SetText(const std::wstring& text);
	std::wstring GetText();
	std::string GetTextA();

	static std::string& GetFontPath();
};
