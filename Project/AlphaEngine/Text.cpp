#include "Text.h"

Text::Text(math::vec2 position, std::string textString, int fontSize) {

	m_textString = textString;
	m_fontSize = fontSize;
	//m_totalWidth = static_cast<int>(m_textString.length() * m_fontSize - m_fontSize * m_textString.length() / 12);
	m_totalWidth = static_cast<int>(11 * m_textString.length() * m_fontSize / 12);

	Graphics::CreateMesh(&m_mesh, &m_texture, "font/letter.png", TEXT_ASCII_COUNT, math::vec2(static_cast<float>(m_fontSize)));

}

void Text::Render() {
	if(m_alignment != TEXT_LEFT) {
		Graphics::DrawText(math::vec2(m_position.x - m_totalWidth / m_alignment, m_position.y), m_textString, &m_mesh, &m_texture, m_fontSize, m_opacity);
	} else {
		Graphics::DrawText(m_position, m_textString, &m_mesh, &m_texture, m_fontSize, m_opacity);
	}
}

void Text::Render(math::vec2 position) {
	m_position = position;
	if(m_alignment != TEXT_LEFT) {
		Graphics::DrawText(math::vec2(m_position.x - m_totalWidth / m_alignment, m_position.y), m_textString, &m_mesh, &m_texture, m_fontSize, m_opacity);
	} else {
		Graphics::DrawText(m_position, m_textString, &m_mesh, &m_texture, m_fontSize, m_opacity);
	}
}

void Text::SetText(std::string textString) {
	m_textString = textString;
	m_totalWidth = static_cast<int>(11 * m_textString.length() * m_fontSize / 12);
}

void Text::SetTextAlignment(TextAlign alignment) {
	m_alignment = alignment;
}

void Text::SetOpacity(float opacity) {
	m_opacity = opacity;
}

std::string Text::GetText() const {
	return m_textString;
}
