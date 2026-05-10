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

	KdTexture M_BackGroundTex;
	KdTexture M_StartTex;

	Math::Matrix	M_ScaleMat;		// 拡大行列
	Math::Matrix	M_TransMat;		// 移動行列
	Math::Matrix	M_BackGroundMat;
	Math::Matrix	M_StartMat;

	float m_alpha = 1.0f;
	float m_addAlpha = 0.01f;

	float			M_ScaleX;		// 横拡大率
	float			M_ScaleY;		// 縦拡大率

	int GAMESTARTFlg;
	bool keyFlg;
};