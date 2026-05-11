#pragma once

//前方宣言
class C_Enemy;

class C_BossBullet
{
public:
	//コンストラクタ
	C_BossBullet() {}
	//デストラクタ
	~C_BossBullet() {}

	void Init();
	void Update();
	void Draw();
	void BossAction0();
	void BossAction1();
	void BossAction2();
	void BossAction3();
	void BossAction4();
	void Release();

	void SetFlg(int i, bool A_Flg) { M_BulletFlg[i] = A_Flg; }
	void SetUpFlg(int i, bool A_Flg) { M_BulletUpFlg[i] = A_Flg; }
	void SetDownFlg(int i, bool A_Flg) { M_BulletDownFlg[i] = A_Flg; }

	void SetEnemyFlg(int i, bool A_Flg) { M_EnemyFlg[i] = A_Flg; }
	void SetEnemyUpFlg(int i, bool A_Flg) { M_EnemyUpFlg[i] = A_Flg; }
	void SetEnemyDownFlg(int i, bool A_Flg) { M_EnemyDownFlg[i] = A_Flg; }

	void SetLastFlg(int i, bool A_Flg) { M_LastBulletFlg[i] = A_Flg; }
	void SetLastUpFlg(int i, bool A_Flg) { M_LastBulletUpFlg[i] = A_Flg; }
	void SetLastDownFlg(int i, bool A_Flg) { M_LastBulletDownFlg[i] = A_Flg; }

	Math::Vector2 GetPos(int i) { return M_BulletPos[i]; }
	Math::Vector2 GetUpPos(int i) { return M_BulletUpPos[i]; }
	Math::Vector2 GetDownPos(int i) { return M_BulletDownPos[i]; }
	float GetRadiusX() { return M_Radius.x * fabs(M_ScaleX); }
	float GetRadiusY() { return M_Radius.y * M_ScaleY; }
	float GetEnemyRadiusX() { return M_EnemyRadius.x * fabs(M_EnemyScaleX); }
	float GetEnemyRadiusY() { return M_EnemyRadius.y * M_EnemyScaleY; }
	static const int	GetBulletNum() { return BulletNum; }
	static const int	GetEnemyNum() { return EnemyNum; }
	static const int	GetLastBulletNum() { return LastBulletNum; }
	void SetOwner(C_Enemy* _owner) { M_Owner = _owner; }
	float Rnd();
private:

	static const int BulletNum = 100;
	static const int EnemyNum = 150;
	static const int LastBulletNum = 5;

	KdTexture		M_Tex;
	KdTexture		M_EnemyTex;
	Math::Matrix	M_ScaleMat;					// 拡大行列
	Math::Matrix	M_TransMat;					// 移動行列
	Math::Matrix	M_RotationMat;				// 回転行列
	Math::Matrix	M_BulletMat[BulletNum];
	Math::Matrix	M_BulletUpMat[BulletNum];
	Math::Matrix	M_BulletDownMat[BulletNum];

	Math::Matrix	M_EnemyMat[EnemyNum];
	Math::Matrix	M_EnemyUpMat[EnemyNum];
	Math::Matrix	M_EnemyDownMat[EnemyNum];

	Math::Matrix	M_LastBulletMat[LastBulletNum];
	Math::Matrix	M_LastBulletUpMat[LastBulletNum];
	Math::Matrix	M_LastBulletDownMat[LastBulletNum];

	Math::Vector2	M_BulletPos[BulletNum];		// 座標
	Math::Vector2	M_BulletUpPos[BulletNum];	// 上座標
	Math::Vector2	M_BulletDownPos[BulletNum];	// 下座標
	Math::Vector2	M_Move[BulletNum];			// 移動量
	Math::Vector2	M_Radius;					// 半径
	Math::Vector2	M_EnemyRadius;				// 半径
	float			M_ScaleX;					// 横拡大率
	float			M_ScaleY;					// 縦拡大率

	float			M_EnemyScaleX;				// 横拡大率
	float			M_EnemyScaleY;				// 縦拡大率

	float			M_LastScaleX;				// 横拡大率
	float			M_LastScaleY;				// 縦拡大率

	bool			M_BulletFlg[BulletNum];		//フラグ
	bool			M_BulletUpFlg[BulletNum];	//Upフラグ
	bool			M_BulletDownFlg[BulletNum];	//Downフラグ

	bool			M_EnemyFlg[EnemyNum];		//フラグ
	bool			M_EnemyUpFlg[EnemyNum];		//Upフラグ
	bool			M_EnemyDownFlg[EnemyNum];	//Downフラグ

	bool			M_LastBulletFlg[LastBulletNum];		//フラグ
	bool			M_LastBulletUpFlg[LastBulletNum];	//Upフラグ
	bool			M_LastBulletDownFlg[LastBulletNum];	//Downフラグ

	int M_ShotWait;		//発射待機時間
	int M_ShotTime;		//後隙
	//int M_ShotTime1;	//後隙

	int state;		//現在の状態

	C_Enemy* M_Owner = nullptr;
};