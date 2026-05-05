#include "TitleScene.h"

#include "../SceneManager.h"

void TitleScene::Init()
{
	M_BackGroundTex.Load("Texture/BackGround/Title/neko.png");
}

void TitleScene::Update()
{
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

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		if (keyFlg == false)
		{
			SceneManager::Instance().SetNextScene(SceneManager::SceneType::Game);
			keyFlg = true;
		}
	}
	else
	{
		keyFlg = false;
	}
	M_BackGroundMat = Math::Matrix::CreateTranslation(0, 0, 0);
}

void TitleScene::Draw()
{
	SHADER.m_spriteShader.SetMatrix(M_BackGroundMat);
	SHADER.m_spriteShader.DrawTex(&M_BackGroundTex, Math::Rectangle(0, 0, 1280, 720), 1.0F);
}

void TitleScene::Release()
{

}
