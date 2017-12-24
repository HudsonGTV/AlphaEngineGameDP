#ifndef TEXT_H
#define TEXT_H

#include "GraphicsEngine.h"
#include "AEEngine.h"
#include "Math.h"

#define TEXT_LEFT 1
#define TEXT_RIGHT 0
#define TEXT_CENTER 2

typedef int TextAlign;

class Text {

private:
	std::string m_textString = "text.undefined.name";

	math::vec2 m_position = math::vec2(0.0f);

	TextAlign m_alignment = TEXT_LEFT;

	int m_fontSize = 30.0f;
	int m_totalWidth = 0;

	AEGfxVertexList *m_mesh;
	AEGfxTexture *m_texture;

public:
	Text(math::vec2 position, std::string textString = "text.undefined.name", int fontSize = 30);

	void Render();
	void Render(math::vec2 position);

	void SetText(std::string textString);
	void Text::SetTextAlignment(TextAlign alignment);

	std::string GetText() const;

};

#endif