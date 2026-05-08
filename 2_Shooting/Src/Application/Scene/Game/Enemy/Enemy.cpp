#include "Enemy.h"
#include "BossBullet/BossBullet.h"

void C_Enemy::Init()
{
	M_BossBullet = std::make_shared<C_BossBullet>();

	M_Pos = { 450,0 };
	M_Alive = true;
	M_ScaleX = 4.5F;
	M_ScaleY = 4.5F;
	M_Radius = { 32.0f,32.0f };
	M_Tex.Load("Texture/Boss/FlameDemon Evolved.png");

	M_BossBullet->Init();
	M_BossBullet->SetOwner(this);
}

void C_Enemy::Update()
{
	if (!M_Alive)return;

	// 座標確定処理
	M_Pos += M_Move;
	
	M_BossBullet->Update();

	M_ScaleMat = Math::Matrix::CreateScale(M_ScaleX, M_ScaleY, 1.0F);
	M_TransMat = Math::Matrix::CreateTranslation(M_Pos.x, M_Pos.y, 0);
	M_Mat = M_ScaleMat * M_TransMat;	// 拡大×回転×移動

}

void C_Enemy::Draw()
{
	if (!M_Alive)return;
	SHADER.m_spriteShader.SetMatrix(M_Mat);
	SHADER.m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 0,0,64,64 }, 1.0f);

	M_BossBullet->Draw();
}

void C_Enemy::TakeDamage(int dmg)
{
	if (!M_Alive)return;

}