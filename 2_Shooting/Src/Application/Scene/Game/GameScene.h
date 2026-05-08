#pragma once

#include "../Base/BaseScene.h"

//前方宣言
class C_Player;
class C_Enemy;
class C_PlayerBullet;
class C_BossBullet;
class C_Hit;

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

	void Hit();

	

	C_Player& GetPlayer() {	return *M_Player;}
	C_Enemy& GetEnemy() { return *M_Enemy; }
	C_PlayerBullet& GetPlayerBullet() { return *M_PlayerBullet; }
	C_BossBullet& GetBossBullet() { return *M_BossBullet; }


private:
	Math::Matrix	M_BackGroundMat1;
	Math::Matrix	M_BackGroundMat2;
	KdTexture M_BackGroundTex;

	//プレイヤー
	std::shared_ptr<C_Player> M_Player = nullptr;
	std::shared_ptr<C_PlayerBullet> M_PlayerBullet = nullptr;
	//エネミー
	std::shared_ptr<C_Enemy> M_Enemy = nullptr;
	std::shared_ptr<C_BossBullet> M_BossBullet = nullptr;
	//当たり判定
	std::shared_ptr<C_Hit> M_Hit = nullptr;

	//背景
	float backX = 0;

	bool keyFlg;

};