#include "TitleScene.h"

#include "../SceneManager.h"

void TitleScene::Init()
{
	M_Tex.Load("Texture/BackGround/Title/neko.png");
	//m_starttex.Load("Asset/Textures/start.png");
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
}

void TitleScene::Draw()
{
	KdShaderManager::GetInstance().m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 0,0,1280,720 }, 1.0f);
	/*Math::Color color = { 1.0f,1.0f,1.0f,m_alpha };
	KdShaderManager::GetInstance().m_spriteShader.DrawTex(&M_StartTex, 0, -200, nullptr, &color);*/

	if (GAMESTARTFlg == 0)
	{
		//SceneManager::Instance().Draw();
		/*SHADER.m_spriteShader.SetMatrix(GAMESTARTMat);
		SHADER.m_spriteShader.DrawTex(&GAMESTARTTex, Math::Rectangle{ 0,0,48,8 }, 1.0f);*/

		/*SHADER.m_spriteShader.DrawString(-150, -100, "Enter:スタート", Math::Vector4(1, 1, 1, 1));
		SHADER.m_spriteShader.DrawString(-150, -150, "WASD:移動", Math::Vector4(1, 1, 1, 1));
		SHADER.m_spriteShader.DrawString(-150, -200, "SPACE:弾を発射", Math::Vector4(1, 1, 1, 1));
		SHADER.m_spriteShader.DrawString(-150, -250, "R:コンテニュー", Math::Vector4(1, 1, 1, 1));*/

	}
}

void TitleScene::Release()
{

}
