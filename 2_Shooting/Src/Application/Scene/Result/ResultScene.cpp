#include "ResultScene.h"
#include "../SceneManager.h"
#include "Score/Score.h"

void ResultScene::Init()
{
	M_Score = std::make_shared<C_Score>();

	M_BackGroundTex.Load("Texture/BackGround/Result/Result1.png");
	M_HomeTex.Load("Texture/BackGround/Result/PushToEnter.png");

	M_ScaleX = 0.85f;
	M_ScaleY = 0.85f;

	//M_Score->Init();
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

	//M_Score->Update();
	M_BackGroundMat = Math::Matrix::CreateTranslation(0, 0, 0);

	M_ScaleMat = Math::Matrix::CreateScale(M_ScaleX, M_ScaleY, 1.0F);
	M_TransMat = Math::Matrix::CreateTranslation(0, -230, 0);
	M_HomeMat = M_ScaleMat * M_TransMat;	// 拡大×移動
}

void ResultScene::Draw()
{
	SHADER.m_spriteShader.SetMatrix(M_BackGroundMat);
	SHADER.m_spriteShader.DrawTex(&M_BackGroundTex, Math::Rectangle(0, 0, 1280, 720), 1.0F);

	SHADER.m_spriteShader.SetMatrix(M_HomeMat);
	SHADER.m_spriteShader.DrawTex(&M_HomeTex, Math::Rectangle(0, 0, 918, 81), m_alpha);

	//M_Score->Draw();
}

void ResultScene::Release()
{

}
