#pragma once

//前方宣言
class C_Player;

class C_PlayerBullet
{
public:
	//コンストラクタ
	C_PlayerBullet() {}
	//デストラクタ
	~C_PlayerBullet () {}

	void Init();
	void Update();
	void Draw();
	void Shot();
	void Release();

	//弾との当たり判定
	//void PlayerBulletHit();

	Math::Vector2 GetPos(int i) { return M_BulletPos[i]; }
	float GetRadiusX() { return M_Radius.x * fabs(M_ScaleX); }
	float GetRadiusY() { return M_Radius.y * M_ScaleY; }
	static const int	GetBulletNum() { return BulletNum; }

	bool GetFlg(int i) { return M_BulletFlg[i]; }

	void SetOwner(C_Player* _owner) { M_Owner = _owner; }
private:
	//プレイヤー
	//std::shared_ptr<C_Player> M_Player = nullptr;
	

	static const int BulletNum = 30;
	
	KdTexture		M_Tex;
	Math::Matrix	M_ScaleMat;					// 拡大行列
	Math::Matrix	M_TransMat;					// 移動行列
	Math::Matrix	M_RotationMat;				// 回転行列
	Math::Matrix	M_BulletMat[BulletNum];
	Math::Vector2	M_BulletPos[BulletNum];		// 座標
	Math::Vector2	M_Move[BulletNum];			// 移動量
	Math::Vector2	M_Radius;					// 半径
	float			M_ScaleX;					// 横拡大率
	float			M_ScaleY;					// 縦拡大率
	
	bool			M_BulletFlg[BulletNum];		//フラグ

	int shotWait;		//発射待機時間

	C_Player* M_Owner = nullptr;
	
};