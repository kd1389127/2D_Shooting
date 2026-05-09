#pragma once

#include "../Base/BaseScene.h"

class GameOverScene : public BaseScene
{
public:
	//コンストラクタ
	GameOverScene() { Init(); }
	//デストラクタ
	~GameOverScene() {}

	void Init()			override;
	void Update()		override;
	void Draw()			override;
	void Release()		override;

private:

	KdTexture M_BackGroundTex;
	KdTexture M_EnterTex;
	Math::Matrix	M_BackGroundMat;
	Math::Matrix	M_EnterMat;

	float m_alpha = 1.0f;
	float m_addAlpha = 0.01f;

	bool keyFlg;
};