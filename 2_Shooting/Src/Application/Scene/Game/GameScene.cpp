#include "GameScene.h"
#include "../SceneManager.h"


void GameScene::Init()
{
	M_Tex.Load("Texture/BackGround/Game/Space_BG (2 frames) (64 x 64).png");
}

void GameScene::Update()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::Result);
	}
}

void GameScene::Draw()
{
	KdShaderManager::GetInstance().m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 0,0,1280,720 }, 1.0f);
}

void GameScene::Release()
{

}
