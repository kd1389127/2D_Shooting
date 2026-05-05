#include "Player.h"

C_Player::C_Player()
{

}

C_Player::~C_Player()
{

}

void C_Player::Init()
{
	M_Hp = 6;
	M_MaxHp = 6;
	M_Pos = { -450,0 };
	M_Alive = true;
	M_ScaleX = 2.5F;
	M_ScaleY = 2.5F;
	M_Tex.Load("Texture/Player/Playership/Player_ship.png");
}

void C_Player::Update()
{
	if (!M_Alive)return;

	Action();

	// 座標確定処理
	M_Pos += M_Move;

	//M_ScrollX = M_Pos.x;

	//// 無敵時間のカウントダウン
	//const float delta = 1.0f / 60.0f;
	//if (M_IsInvincible) {
	//	M_InvincibleTime -= delta;
	//	if (M_InvincibleTime <= 0.0f) {
	//		M_IsInvincible = false;
	//		M_InvincibleTime = 0.0f;
	//	}
	//}

	//// 無敵中は点滅（5フレームごとに描画スキップ）
	//if (M_IsInvincible) {
	//	static int blinkFrame = 0;
	//	blinkFrame++;
	//	if ((blinkFrame / 5) % 2 == 0) {
	//		// 描画スキップ
	//		return;
	//	}
	//}

	M_ScaleMat = Math::Matrix::CreateScale(M_ScaleX, M_ScaleY, 1.0F);
	M_TransMat = Math::Matrix::CreateTranslation(M_Pos.x, M_Pos.y, 0);
	M_RotationMat = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(270)); //回転行列
	M_Mat = M_ScaleMat * M_RotationMat *M_TransMat;	// 拡大×回転×移動

}

void C_Player::Draw()
{
	if (!M_Alive)return;

	SHADER.m_spriteShader.SetMatrix(M_Mat);
	SHADER.m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 16,0,16,16 }, 1.0f);

}

void C_Player::Action()
{
	if (!M_Alive)return;

	M_Move = { 0,0 };

	//自機の移動処理
	if (GetAsyncKeyState(VK_UP)&0x8000)
	{
		M_Move.y += 6;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		M_Move.x -= 7;
	}

	if(GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		M_Move.y -= 6;
	}

	if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
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
	if (M_Pos.y < -360)
	{
		M_Pos.y = -360 -;
	}

}

void C_Player::TakeDamage(int dmg)
{
	if (M_IsInvincible || !M_Alive)
	{
		M_DamageFlg = false;
		return;
	}

	M_Hp -= dmg;
	M_DamageFlg = true;
	if (M_Hp < 0) M_Hp = 0;

	if (M_Hp <= 0)
	{
		M_Alive = false;
		return;
	}

	// 無敵状態にする
	M_IsInvincible = true;
	M_InvincibleTime = 1.0f; // 1秒間無敵
}