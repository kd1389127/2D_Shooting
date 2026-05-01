#include "ResultScene.h"
#include "../SceneManager.h"


void ResultScene::Init()
{
	M_Tex.Load("Texture/BackGround/Result/Result.png");
}

void ResultScene::Update()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (keyFlg == false)
		{
			SceneManager::Instance().SetNextScene(SceneManager::SceneType::Title);
		}
		keyFlg = true;
	}
	else
	{
		keyFlg = false;
	}
}

void ResultScene::Draw()
{
	KdShaderManager::GetInstance().m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 0,0,1280,720 }, 1.0f);
}

void ResultScene::Release()
{

}
