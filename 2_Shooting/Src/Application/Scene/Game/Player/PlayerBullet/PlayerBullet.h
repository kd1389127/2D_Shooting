#pragma once

class C_PlayerBullet
{
public:
	//コンストラクタ
	C_PlayerBullet() { Init(); }
	//デストラクタ
	~C_PlayerBullet () {}

	void Init();
	void Update();
	void Draw();
	void Release();

	Math::Vector2 GetPos(int i) { return M_Pos[i]; }
private:
	static const int BulletNum = 30;
	
	KdTexture		M_BulletTex;
	Math::Matrix	M_ScaleMat;					// 拡大行列
	Math::Matrix	M_TransMat;					// 移動行列
	Math::Matrix	M_RotationMat;				// 回転行列
	Math::Matrix	M_BulletMat[BulletNum];
	Math::Vector2	M_Pos[BulletNum];			// 座標
	bool			M_BulletFlg[BulletNum];		//フラグ

	int shotWait;		//発射待機時間
};