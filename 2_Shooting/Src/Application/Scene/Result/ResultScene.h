#pragma once

#include "../Base/BaseScene.h"

class ResultScene : public BaseScene
{
public:
	//コンストラクタ
	ResultScene() { Init(); }
	//デストラクタ
	~ResultScene() {}

	void Init()			override;
	void Update()		override;
	void Draw()			override;
	void Release()		override;

private:

	KdTexture M_Tex;
	KdTexture M_StartTex;

	float m_alpha = 1.0f;
	float m_addAlpha = 0.01f;

	bool keyFlg;
};