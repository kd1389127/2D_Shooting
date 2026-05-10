#pragma once

//前方宣言
class C_PlayerBullet;

class C_Player
{
public:
	//コンストラクタ
	C_Player();

	//デストラクタ
	~C_Player();

	void Init();
	void Update();
	void Draw();
	void Action();
	
	void SetAlive(bool A_Alive) { M_Alive = A_Alive; }

	Math::Vector2 GetPos() { return M_Pos; }
	float GetRadiusX() { return M_Radius.x * fabs(M_ScaleX); }
	float GetRadiusY() { return M_Radius.y * M_ScaleY; }
	int GetHP() const { return M_Hp; }
	void TakeDamage(int dmg);
	bool IsDead() const { return M_Hp <= 0; }
	bool GetAlive() { return M_Alive; }
	bool GetDamageFlg() { return M_DamageFlg; }
	std::shared_ptr<C_PlayerBullet> GetPlayerBullet() { return M_PlayerBullet; }

private:
	//弾
	std::shared_ptr<C_PlayerBullet> M_PlayerBullet = nullptr;

	KdTexture		M_PlayerTex;
	KdTexture		M_PlayerHpTex;
	KdTexture		M_PlayerBoostTex;

	Math::Matrix	M_ScaleMat;		// 拡大行列
	Math::Matrix	M_TransMat;		// 移動行列
	Math::Matrix	M_RotationMat;	// 回転行列
	Math::Matrix	M_PlayerMat;	// 合成行列

	Math::Matrix	M_PlayerHp6Mat;	// Hp行列
	Math::Matrix	M_PlayerHp5Mat;	// Hp行列
	Math::Matrix	M_PlayerHp4Mat;	// Hp行列
	Math::Matrix	M_PlayerHp3Mat;	// Hp行列
	Math::Matrix	M_PlayerHp2Mat;	// Hp行列
	Math::Matrix	M_PlayerHp1Mat;	// Hp行列
	
	Math::Matrix	M_PlayerBoostMat; //Boost行列	

	Math::Vector2	M_Pos;			// 座標
	Math::Vector2	M_Move;			// 移動量
	Math::Vector2	M_Radius;		// 半径
	float			M_ScaleX;		// 横拡大率
	float			M_ScaleY;		// 縦拡大率
	int				M_Hp;			// HP
	int				M_MaxHp;		// MaxHp
	bool			M_Alive;		// 生存フラグ

	float			M_HpScaleX;		// 横拡大率
	float			M_HpScaleY;		// 縦拡大率

	float			M_BoostScaleX;		// 横拡大率
	float			M_BoostScaleY;		// 縦拡大率

	bool  M_IsInvincible;			//一定期間の無敵フラグ
	float M_InvincibleTime;			//無敵の時間

	bool M_DamageFlg = false;		//ダメージフラグ

	// スクロール
	float	M_ScrollX;

	int shotWait;		//発射待機時間

	bool shotFlg;
	bool keyFlg;

	float AnimCnt;

	float m_alpha = 1.0f;
	float m_addAlpha = 0.01f;

public:
	bool IsInvincible() const { return M_IsInvincible; }

};
