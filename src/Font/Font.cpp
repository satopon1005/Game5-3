#include "DxLib.h"
#include "Font.h"

int Font::m_font_handle[FontTypeMaxNum];

void Font::LoadFontHandle()
{
	for (int i = 0; i < FontTypeMaxNum; i++)
		m_font_handle[i] = CreateFontToHandle(FONT_HANDLE_PAYH[i], FONT_SIZE[i], FONT_THICK[i]);
}
void Font::DeleteFontHandle()
{
	for (int i = 0; i < FontTypeMaxNum; i++)
		DeleteFontToHandle(m_font_handle[i]);
}