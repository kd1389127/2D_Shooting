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
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::Game);
	}
}

void TitleScene::Draw()
{
	KdShaderManager::GetInstance().m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 0,0,1280,720 }, 1.0f);
	/*Math::Color color = { 1.0f,1.0f,1.0f,m_alpha };
	KdShaderManager::GetInstance().m_spriteShader.DrawTex(&M_StartTex, 0, -200, nullptr, &color);*/
}

void TitleScene::Release()
{

}
