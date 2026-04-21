#pragma once

class C_Player
{
public:
	//コンストラクタ
	C_Player(){}

	//デストラクタ
	~C_Player(){}

	void Init();
	void Update();
	void Draw();
	void Action();
	
	void SetAlive(bool A_Alive) { M_Alive = A_Alive; }

	Math::Vector2 GetPos() { return M_Pos; }
	Math::Vector2 GetFuturePos() { return M_Pos + M_Move; }
	float GetRadiusX() { return 32.0F; }
	float GetRadiusY() { return 64.0F; }

private:
	KdTexture M_Tex;

	Math::Matrix	M_ScaleMat;		// 拡大行列
	Math::Matrix	M_TransMat;		// 移動行列
	Math::Matrix	M_Mat;			// 合成行列
	
	Math::Vector2	M_Pos;			// 座標
	Math::Vector2	M_Move;			// 移動量
	float			M_ScaleX;		// 横拡大率
	float			M_ScaleY;		// 縦拡大率
	bool			M_Alive;		// 生存フラグ

	// スクロール
	float	M_ScrollX;
};
