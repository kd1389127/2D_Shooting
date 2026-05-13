#pragma once

#include "../Base/BaseScene.h"

class C_Score;

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
	//プレイヤー
	std::shared_ptr<C_Score> M_Score = nullptr;

	KdTexture M_BackGroundTex;
	KdTexture M_HomeTex;

	Math::Matrix	M_ScaleMat;		// 拡大行列
	Math::Matrix	M_TransMat;		// 移動行列
	Math::Matrix	M_BackGroundMat;
	Math::Matrix	M_HomeMat;

	float m_alpha = 1.0f;
	float m_addAlpha = 0.01f;

	float			M_ScaleX;		// 横拡大率
	float			M_ScaleY;		// 縦拡大率

	bool keyFlg;
};