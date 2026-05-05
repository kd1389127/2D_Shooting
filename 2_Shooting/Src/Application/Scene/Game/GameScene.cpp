#include "GameScene.h"
#include "../SceneManager.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"

void GameScene::Init()
{
	M_Player = std::make_shared<C_Player>();
	M_Enemy = std::make_shared<C_Enemy>();
	M_BackGroundTex.Load("Texture/BackGround/Game/Space_BG (2 frames) (64 x 64).png");
	M_Player->Init();
	M_Enemy->Init();
}

void GameScene::Update()
{
	M_Player->Update();
	M_Enemy->Update();
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (keyFlg == false)
		{
			SceneManager::Instance().SetNextScene(SceneManager::SceneType::Result);
			keyFlg = true;
		}
	}
	else
	{
		keyFlg = false;
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
	
	//プレイヤー
	M_Player->Draw();

	//エネミー
	M_Enemy->Draw();
}

void GameScene::Release()
{

}
