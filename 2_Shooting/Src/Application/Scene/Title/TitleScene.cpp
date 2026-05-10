#include "TitleScene.h"

#include "../SceneManager.h"

void TitleScene::Init()
{
	M_ScaleX = 0.85f;
	M_ScaleY = 0.85f;

	M_BackGroundTex.Load("Texture/BackGround/Title/Title.png");
	M_StartTex.Load("Texture/BackGround/Title/PushToEnter.png");
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

	M_ScaleMat = Math::Matrix::CreateScale(M_ScaleX, M_ScaleY, 1.0F);
	M_TransMat = Math::Matrix::CreateTranslation(0,-150, 0);
	M_StartMat = M_ScaleMat * M_TransMat;	// 拡大×移動
}

void TitleScene::Draw()
{
	SHADER.m_spriteShader.SetMatrix(M_BackGroundMat);
	SHADER.m_spriteShader.DrawTex(&M_BackGroundTex, Math::Rectangle(0, 0, 1280, 720), 1.0F);

	SHADER.m_spriteShader.SetMatrix(M_StartMat);
	SHADER.m_spriteShader.DrawTex(&M_StartTex, Math::Rectangle(0, 0, 918, 81), m_alpha);
}

void TitleScene::Release()
{

}
