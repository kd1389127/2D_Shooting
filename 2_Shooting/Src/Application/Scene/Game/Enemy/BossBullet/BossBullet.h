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
	void Action();
	void Release();

	void SetFlg(int i, bool A_Flg) { M_BulletFlg[i] = A_Flg; }
	void SetUpFlg(int i, bool A_Flg) { M_BulletUpFlg[i] = A_Flg; }
	void SetDownFlg(int i, bool A_Flg) { M_BulletDownFlg[i] = A_Flg; }

	Math::Vector2 GetPos(int i) { return M_BulletPos[i]; }
	Math::Vector2 GetUpPos(int i) { return M_BulletUpPos[i]; }
	Math::Vector2 GetDownPos(int i) { return M_BulletDownPos[i]; }
	float GetRadiusX() { return M_Radius.x * fabs(M_ScaleX); }
	float GetRadiusY() { return M_Radius.y * M_ScaleY; }
	static const int	GetBulletNum() { return BulletNum; }
	void SetOwner(C_Enemy* _owner) { M_Owner = _owner; }
	float Rnd();
private:
	//プレイヤー
	//std::shared_ptr<C_Player> M_Player = nullptr;


	static const int BulletNum = 100;

	KdTexture		M_Tex;
	Math::Matrix	M_ScaleMat;					// 拡大行列
	Math::Matrix	M_TransMat;					// 移動行列
	Math::Matrix	M_RotationMat;				// 回転行列
	Math::Matrix	M_BulletMat[BulletNum];
	Math::Matrix	M_BulletUpMat[BulletNum];
	Math::Matrix	M_BulletDownMat[BulletNum];

	Math::Vector2	M_BulletPos[BulletNum];		// 座標
	Math::Vector2	M_BulletUpPos[BulletNum];	// 上座標
	Math::Vector2	M_BulletDownPos[BulletNum];	// 下座標
	Math::Vector2	M_Move[BulletNum];			// 移動量
	Math::Vector2	M_Radius;					// 半径
	float			M_ScaleX;					// 横拡大率
	float			M_ScaleY;					// 縦拡大率

	bool			M_BulletFlg[BulletNum];		//フラグ
	bool			M_BulletUpFlg[BulletNum];	//Upフラグ
	bool			M_BulletDownFlg[BulletNum];	//Downフラグ

	int M_ShotWait;		//発射待機時間
	int M_ShotTime;		//後隙
	int M_ShotTime1;		//後隙

	int state;		//現在の状態

	C_Enemy* M_Owner = nullptr;
};