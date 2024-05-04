#pragma once

#define KEY_BUF_LEN	(256)
#define MOUSE_BUF_LEN	(3)

class Input
{
private:
	static char currentKeyBuf[KEY_BUF_LEN];
	static char preKeyBuf[KEY_BUF_LEN];

	// マウス関連変数
	static int mouse_pos_x, mouse_pos_y;
	static int currentMouseBuf[MOUSE_BUF_LEN];
	static int preMouseBuf[MOUSE_BUF_LEN];

public:
	static void InitInput();

	static void StepInput();

	//キーボード
	static bool IsKeyPush(int key_code);
	static bool IsKeyKeep(int key_code);
	static bool IsKeyRelease(int key_code);
	static bool IsKeyDown(int key_code);

	static bool IsKeyPushInArea(int key_code, float rect_x, float rect_y, float rect_w, float rect_h);

	//マウス
	static int CheckMouse(int mouse_code);
	static int ChangeMouseCode(int mouse_code);

	static bool IsMousePush(int mouse_code);
	static bool IsMouseKeep(int mouse_code);
	static bool IsMouseRelease(int mouse_code);
	static bool IsMouseDown(int mouse_code);

	static bool IsMousePushInArea(int mouse_code, float rect_x, float rect_y, float rect_w, float rect_h);

	static char GetCurrentKey(int index) { return currentKeyBuf[index]; }
	static char GetPreKey(int index) { return preKeyBuf[index]; }

	static int GetMousePosX() { return mouse_pos_x; }
	static int GetMousePosY() { return mouse_pos_y; }
};