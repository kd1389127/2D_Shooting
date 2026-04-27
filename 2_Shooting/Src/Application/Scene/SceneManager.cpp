#include "SceneManager.h"
#include "Title/TitleScene.h"
#include "Game/GameScene.h"
#include "Base/BaseScene.h"

void SceneManager::PreUpdate()
{
	//シーン切替
	if (m_currentSceneType != m_nextSceneType)
	{
		ChangeScene(m_nextSceneType);
	}
}

void SceneManager::Update()
{
	//ポリモーフィズム
	m_currentScene->Update();
}

void SceneManager::Draw()
{
	//ポリモーフィズム
	m_currentScene->Draw();
}

void SceneManager::Init()
{
	ChangeScene(m_currentSceneType);
}

void SceneManager::Release()
{
}

void SceneManager::ChangeScene(SceneType _sceneType)
{
	switch (_sceneType)
	{
	case SceneType::Title:
		//アップキャスト
		m_currentScene = std::make_shared<TitleScene>();
		break;
	case SceneType::Game:
		//アップキャスト
		m_currentScene = std::make_shared<GameScene>();
		break;
	}

	m_currentSceneType = _sceneType;
}
