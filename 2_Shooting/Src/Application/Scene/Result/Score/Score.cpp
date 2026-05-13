#include "Score.h"
#include "../../Game/Player/Player.h"

void C_Score::Init()
{
	M_Player = std::make_shared<C_Player>();

	M_ScoreTex.Load("Texture/BackGround/Result/100.png");
	Hp = M_Player->GetHP();
	score = 10;
	gokei = 0;
}

void C_Score::Update()
{
	//計算
	gokei = Hp * score;

	m_alpha += m_addAlpha;

	if (m_alpha > 1.0f)
	{
		m_alpha = 1.0f;
		m_addAlpha *= -1;
	}
	else if (m_alpha < 0.0f)
	{
		m_alpha = 0.0f;
		m_addAlpha *= -1;
	}

	M_ScoreMat = Math::Matrix::CreateTranslation(-430, 0, 0);
}

void C_Score::Draw()
{
	if (gokei >= 60)
	{
		SHADER.m_spriteShader.SetMatrix(M_ScoreMat);
		SHADER.m_spriteShader.DrawTex(&M_ScoreTex, Math::Rectangle(0, 0, 241, 82), m_alpha);
	}
}
