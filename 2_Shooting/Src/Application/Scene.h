#pragma once
#include "Player/Player.h"

class Scene
{
private:

	//プレイヤー
	KdTexture	M_PlayerTex;
	C_Player	M_Player;
	C_Player* GetPlayer() { return &M_Player; }				// プレイヤー

	KdTexture backTex;
	KdTexture enemyTex;
	KdTexture bulletTex;
	KdTexture expTex;
	KdTexture TbossTex;
	KdTexture RbossTex;
	KdTexture T_bulletTex;
	KdTexture R_bulletTex;
	KdTexture GAMEOVERTex;
	KdTexture GAMECLEARTex;
	KdTexture LifeTex;
	KdTexture GAMESTARTTex;
	
	int stage;

	

	//敵
	static const int enemyNum = 30;	//敵の数(書き換え不可能)

	Math::Matrix enemyMat[enemyNum];
	float enemyX[enemyNum];
	float enemyY[enemyNum];
	int enemyFlg[enemyNum];
	float enemySize[enemyNum];
	float enemyRadius[enemyNum];
	float enemyAnimCnt[enemyNum];
	int   cnt;

	//弾
	static const int bulletNum = 30;

	Math::Matrix bulletMat[bulletNum];
	float bulletX[bulletNum];
	float bulletY[bulletNum];
	int bulletFlg[bulletNum];

	int shotWait;		//発射待機時間

	//中ボスの弾
	static const int T_bulletNum = 50;

	Math::Matrix T_bulletMat[T_bulletNum];
	float T_bulletX[T_bulletNum];
	float T_bulletY[T_bulletNum];
	int   T_bulletFlg[T_bulletNum];
	float T_bulletSize[T_bulletNum];
	float T_bulletRadius[T_bulletNum];
	float T_bulletAnimCnt[T_bulletNum];

	int T_shotWait;     //発射待機時間

	//ラスボスの弾
	static const int R_bulletNum = 50;

	//直線
	Math::Matrix R_bulletMat[R_bulletNum];
	float R_bulletX[R_bulletNum];
	float R_bulletY[R_bulletNum];
	int   R_bulletFlg[R_bulletNum];
	float R_bulletSize[R_bulletNum];
	float R_bulletRadius[R_bulletNum];
	float R_bulletAnimCnt[R_bulletNum];

	int R_shotWait;     //発射待機時間

	//右斜め
	Math::Matrix RR_bulletMat[R_bulletNum];
	float RR_bulletX[R_bulletNum];
	float RR_bulletY[R_bulletNum];
	int   RR_bulletFlg[R_bulletNum];
	float RR_bulletSize[R_bulletNum];
	float RR_bulletRadius[R_bulletNum];
	float RR_bulletAnimCnt[R_bulletNum];

	int RR_shotWait;     //発射待機時間

	//左斜め
	Math::Matrix RL_bulletMat[R_bulletNum];
	float RL_bulletX[R_bulletNum];
	float RL_bulletY[R_bulletNum];
	int   RL_bulletFlg[R_bulletNum];
	float RL_bulletSize[R_bulletNum];
	float RL_bulletRadius[R_bulletNum];
	float RL_bulletAnimCnt[R_bulletNum];
	
	int RL_shotWait;     //発射待機時間

	//爆発
	static const int expNum = 100;

	Math::Matrix expMat[expNum];
	float	expX[expNum];
	float	expY[expNum];
	int		expFlg[expNum];
	float	expAnimCnt[expNum];	//アニメーション用
	float   expSize[expNum];

	//中ボス
	static const int TbossNum = 10;

	Math::Matrix TbossMat;
	float TbossX;
	float TbossY;
	int   TbossFlg;
	float TbossAnimCnt[TbossNum];
	float TbossSize;
	float TbossRadius;
	int   TbossHp;
	int   shottime;

	//ラスボス
	static const int RbossNum = 10;

	Math::Matrix RbossMat;
	float RbossX;
	float RbossY;
	int   RbossFlg;
	float RbossAnimCnt[RbossNum];
	float RbossSize;
	float RbossRadius;
	int   RbossHp;
	int   Rshottime;

	//ゲームオーバー
	Math::Matrix GAMEOVERMat;
	float GAMEOVERX;
	float GAMEOVERY;
	int   GAMEOVERFlg;
	float GAMEOVERSize;

	//ゲームクリア
	Math::Matrix GAMECLEARMat;
	float GAMECLEARX;
	float GAMECLEARY;
	int   GAMECLEARFlg;
	float GAMECLEARSize;

	//自機ライフ
	Math::Matrix Life1Mat;
	Math::Matrix Life2Mat;
	Math::Matrix Life3Mat;
	float Life1X;
	float Life1Y;
	float Life2X;
	float Life3X;
	float Life1Size;
	float Life2Size;
	float Life3Size;

	//ゲームスタート
	Math::Matrix GAMESTARTMat;
	float GAMESTARTX;
	float GAMESTARTY;
	float GAMESTARTSize;
	int GAMESTARTFlg;

public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理の前の更新処理
	void PreUpdate();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

	void Action();

	// GUI処理
	void ImGuiUpdate();

	//リセット
	void RESET();

	//爆発
	void Explosion(float X, float Y);

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
