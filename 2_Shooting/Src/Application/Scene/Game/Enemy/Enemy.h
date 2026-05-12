#pragma once

//前方宣言
class C_BossBullet;

class C_Enemy
{
public:
	//コンストラクタ
	C_Enemy(){}
	//デストラクタ
	~C_Enemy(){}

	void Init();
	void Update();
	void Draw();
	void Action();
	void TakeDamage(int dmg);

	void SetAlive(bool A_Alive) { M_Alive = A_Alive; }

	Math::Vector2 GetPos() { return M_Pos; }
	Math::Vector2 GetUpPos() { return M_UpPos; }
	Math::Vector2 GetDownPos() { return M_DownPos; }
	float GetRadiusX() { return M_Radius.x * fabs(M_ScaleX); }
	float GetRadiusY() { return M_Radius.y * M_ScaleY; }
	int GetHP() const { return M_Hp; }
	bool IsDead() const { return M_Hp <= 0; }
	bool GetAlive() { return M_Alive; }
	bool GetDamageFlg() { return M_DamageFlg; }
	std::shared_ptr<C_BossBullet> GetBossBullet() { return M_BossBullet; }

private:
	//弾
	std::shared_ptr<C_BossBullet> M_BossBullet = nullptr;

	KdTexture		M_Tex;		
	KdTexture		M_LastTex;		
	Math::Matrix	M_ScaleMat;		// 拡大行列
	Math::Matrix	M_TransMat;		// 移動行列
	Math::Matrix	M_RotationMat;	// 回転行列
	Math::Matrix	M_Mat;			// 合成行列

	Math::Vector2	M_Pos;			// 座標
	Math::Vector2	M_UpPos;		// 上座標
	Math::Vector2	M_DownPos;		// 下座標
	Math::Vector2	M_Move;			// 移動量
	Math::Vector2	M_Radius;		// 半径
	float			M_ScaleX;		// 横拡大率
	float			M_ScaleY;		// 縦拡大率
	int				M_Hp;			// HP
	int				M_MaxHp;		// MaxHp
	bool			M_Alive;		// 生存フラグ
	float			M_Angle;		//角度

	//演出
	KdTexture		M_EnemyTex;
	static const int EnemyNum = 30;
	Math::Matrix	M_EnemyMat[EnemyNum];
	Math::Vector2	M_EnemyPos[EnemyNum];		// 座標
	Math::Vector2	M_EnemyMove;				// 移動量
	float			M_EnemyScaleX;				// 横拡大率
	float			M_EnemyScaleY;				// 縦拡大率
	bool			M_EnemyFlg[EnemyNum];		//フラグ
	int				M_EnemyWait;


	bool M_DamageFlg = false;		//ダメージフラグ

	bool  M_IsInvincible;			//一定期間の無敵フラグ
	float M_InvincibleTime;			//無敵の時間

	float m_alpha = 1.0f;
	float m_addAlpha = 0.01f;

	int M_State;		//現在の状態

	int M_Wait0;
	int M_Wait1;
	int M_Wait2;

	bool M_WaitFlg0;
	bool M_WaitFlg1;
	bool M_WaitFlg2;

	bool M_ChangeFlg;	//画像変化

public:
	bool IsInvincible() const { return M_IsInvincible; }
};