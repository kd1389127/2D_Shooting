#include "ResultScene.h"
#include "../SceneManager.h"


void ResultScene::Init()
{
	M_BackGroundTex.Load("Texture/BackGround/Result/Result.png");
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
	M_BackGroundMat = Math::Matrix::CreateTranslation(0, 0, 0);
}

void ResultScene::Draw()
{
	SHADER.m_spriteShader.SetMatrix(M_BackGroundMat);
	SHADER.m_spriteShader.DrawTex(&M_BackGroundTex, Math::Rectangle(0, 0, 1280, 720), 1.0F);
}

void ResultScene::Release()
{

}
