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

	void SetAlive(bool A_Alive) { M_Alive = A_Alive; }

	Math::Vector2 GetPos() { return M_Pos; }
	Math::Vector2 GetFuturePos() { return M_Pos + M_Move; }
	float GetRadiusX() { return M_Radius.x * fabs(M_ScaleX); }
	float GetRadiusY() { return M_Radius.y * M_ScaleY; }
	int GetHP() const { return M_Hp; }
	void TakeDamage(int dmg);
	bool IsDead() const { return M_Hp <= 0; }
	bool GetAlive() { return M_Alive; }
	bool GetDamageFlg() { return M_DamageFlg; }
	std::shared_ptr<C_BossBullet> GetBossBullet() { return M_BossBullet; }

private:
	//弾
	std::shared_ptr<C_BossBullet> M_BossBullet = nullptr;

	KdTexture		M_Tex;		
	Math::Matrix	M_ScaleMat;		// 拡大行列
	Math::Matrix	M_TransMat;		// 移動行列
	Math::Matrix	M_RotationMat;	// 回転行列
	Math::Matrix	M_Mat;			// 合成行列

	Math::Vector2	M_Pos;			// 座標
	Math::Vector2	M_Move;			// 移動量
	Math::Vector2	M_Radius;		// 半径
	float			M_ScaleX;		// 横拡大率
	float			M_ScaleY;		// 縦拡大率
	int				M_Hp;			// HP
	int				M_MaxHp;		// MaxHp
	bool			M_Alive;		// 生存フラグ
	float			M_Angle;		//角度

	bool M_DamageFlg = false;		//ダメージフラグ

	// スクロール
	float	M_ScrollX;

};