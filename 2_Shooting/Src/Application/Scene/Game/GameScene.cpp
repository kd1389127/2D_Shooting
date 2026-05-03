#include "GameScene.h"
#include "../SceneManager.h"

void GameScene::Init()
{
	M_BackGroundTex.Load("Texture/BackGround/Game/Space_BG (2 frames) (64 x 64).png");
	//M_BackGround2Tex.Load("Texture/BackGround/Game/Space_BG (2 frames) (64 x 64).png");
}

void GameScene::Update()
{
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
	if (backX < -1280)
	{
		backX = 0;
	}
}

void GameScene::Draw()
{
	KdShaderManager::GetInstance().m_spriteShader.DrawTex(&M_BackGroundTex, Math::Rectangle{ backX,0,1280,720 }, 1.0f);
	KdShaderManager::GetInstance().m_spriteShader.DrawTex(&M_BackGroundTex, Math::Rectangle{ backX + 1280,0,1280,720 }, 1.0f);
}

void GameScene::Release()
{

}
