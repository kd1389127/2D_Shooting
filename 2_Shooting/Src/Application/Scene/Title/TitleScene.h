#pragma once

#include "../Base/BaseScene.h"

class TitleScene : public BaseScene
{
public:
	//コンストラクタ
	TitleScene() { Init(); }
	//デストラクタ
	~TitleScene() {}

	void Init()			override;
	void Update()		override;
	void Draw()			override;
	void Release()		override;

private:

	KdTexture M_Tex;
	KdTexture M_StartTex;

	float m_alpha = 1.0f;
	float m_addAlpha = 0.01f;

	int GAMESTARTFlg;
	bool keyFlg;
};