#pragma once

#include "../Base/BaseScene.h"

//前方宣言
class C_Player;
class C_Enemy;

class GameScene : public BaseScene
{
public:
	//コンストラクタ
	GameScene() { Init(); }
	//デストラクタ
	~GameScene() {}

	void Init()			override;
	void Update()		override;
	void Draw()			override;
	void Release()		override;

private:
	Math::Matrix	M_BackGroundMat1;
	Math::Matrix	M_BackGroundMat2;
	KdTexture M_BackGroundTex;

	//プレイヤー
	std::shared_ptr<C_Player> M_Player = nullptr;
	std::shared_ptr<C_Enemy> M_Enemy = nullptr;

	//背景
	float backX = 0;

	bool keyFlg;
};