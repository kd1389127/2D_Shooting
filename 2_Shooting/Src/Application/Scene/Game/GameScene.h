#pragma once

#include "../Base/BaseScene.h"
//#include "Player/Player.h"

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
	KdTexture M_BackGroundTex;
	//KdTexture M_BackGround2Tex;

	//プレイヤー
	KdTexture	M_PlayerTex;
	//C_Player	M_Player;
	//C_Player* GetPlayer() { return &M_Player; }				// プレイヤー

	//背景
	long backX;

	bool keyFlg;
};