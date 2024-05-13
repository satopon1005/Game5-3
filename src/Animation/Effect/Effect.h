#pragma once
#include "../Animation.h"

enum EffectType
{
	damage,

	EffectTypeMaxNum
};

class Effect :public Animation
{
private:
	VECTOR m_pos;
	bool m_isUse;

public:
	void Init();
	void Step();
	void Draw(int handle);

	void PlayEffect(VECTOR pos, int effect_type);
};