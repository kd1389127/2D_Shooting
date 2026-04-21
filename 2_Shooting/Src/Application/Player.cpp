#include "Player.h"

C_Player::C_Player()
{

}

C_Player::~C_Player()
{

}

void C_Player::Init()
{
	M_Pos = { 0,0 };
	M_Move = { 0,0 };
	M_Alive = true;
	M_ScaleX = 1.0F;
	M_ScaleY = 1.0F;
}

void C_Player::Update()
{
	if (!M_Alive)return;

	// 座標確定処理
	M_Pos += M_Move;

	//M_ScrollX = M_Pos.x;

	M_ScaleMat = Math::Matrix::CreateScale(M_ScaleX, M_ScaleY, 1.0F);
	M_TransMat = Math::Matrix::CreateTranslation(M_Pos.x - M_ScrollX, M_Pos.y, 0);
	M_Mat = M_ScaleMat * M_TransMat;	// 拡大×回転×移動

}

void C_Player::Draw()
{
	if (!M_Alive)return;

	//if (playerFlg == 1)
	{
		SHADER.m_spriteShader.SetMatrix(M_Mat);
		SHADER.m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 16,0,16,16 }, 1.0f);
	}
}

void C_Player::Action()
{
	if (!M_Alive)return;

	//自機の移動処理
	if ((GetAsyncKeyState('W') & 0x8000)&& GetAsyncKeyState(VK_UP)&0x8000)
	{
		M_Move.y += 6;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		M_Move.x -= 7;
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		M_Move.y -= 6;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		M_Move.x += 7;
	}

	//両端の判定
	if (M_Move.x > 640 - 24)
	{
		M_Move.x = 640 - 24;
	}
	if (M_Move.x < -640 + 24)
	{
		M_Move.x = -640 + 24;
	}
	//下端判定
	if (M_Move.y < -360 + 24)
	{
		M_Move.y = -360 + 24;
	}

}
