#include "GameScene.h"
#include "../SceneManager.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Hit/Hit.h"

void GameScene::Init()
{
	M_Player = std::make_shared<C_Player>();
	M_Enemy = std::make_shared<C_Enemy>();
	M_Hit = std::make_shared<C_Hit>();

	M_BackGroundTex.Load("Texture/BackGround/Game/Game.png");
	M_Enemy->Init();
	M_Player->Init();
	M_Hit->SetOwner(this);
}

void GameScene::Update()
{
	M_Enemy->Update();

	M_Player->Update();

	Hit();
	
	if (M_Enemy->GetAlive() == false)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::Result);
	}

	if (M_Player->GetAlive() == false)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::GameOver);
	}

	//デバックキー
	if (GetAsyncKeyState('T') & 0x8000)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::Title);
	}
	if (GetAsyncKeyState('R') & 0x8000)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::Result);
	}
	if (GetAsyncKeyState('G') & 0x8000)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::GameOver);
	}

	//背景スクロール
	backX += 4;
	if (backX > 1280)
	{
		backX = 0;
	}

	M_BackGroundMat1 = Math::Matrix::CreateTranslation(backX, 0, 0);
	M_BackGroundMat2 = Math::Matrix::CreateTranslation(backX - 1280,0, 0);
}

void GameScene::Draw()
{
	//背景
	SHADER.m_spriteShader.SetMatrix(M_BackGroundMat1);
	SHADER.m_spriteShader.DrawTex(&M_BackGroundTex, Math::Rectangle(0, 0, 1280, 720), 1.0F);
	SHADER.m_spriteShader.SetMatrix(M_BackGroundMat2);
	SHADER.m_spriteShader.DrawTex(&M_BackGroundTex, Math::Rectangle{ 0,0,1280,720 }, 1.0F);
	
	//エネミー
	M_Enemy->Draw();

	//プレイヤー
	M_Player->Draw();

	//Bossの体力
	char Hp[200];

	sprintf_s(Hp, sizeof(Hp), "BOSS HP : %d", M_Enemy->GetHP());

	SHADER.m_spriteShader.DrawString(340, -310, Hp, Math::Vector4(1.0f, 1.0f, 1.0f, 1));
}

void GameScene::Release()
{

}

void GameScene::Hit()
{
	M_Hit->BossHit();
	M_Hit->PlayerBulletHit();
	M_Hit->BossBulletHit();
	M_Hit->EnemyHit();
	M_Hit->LastBossBulletHit();
}
