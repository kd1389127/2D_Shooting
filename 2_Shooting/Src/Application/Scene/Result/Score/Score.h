#pragma once

class C_Player;

class C_Score
{
public:
	C_Score() {}
	~C_Score() {}

	void Init();
	void Update();
	void Draw();

private:
	//プレイヤー
	std::shared_ptr<C_Player> M_Player = nullptr;
	
	KdTexture		M_ScoreTex;
	Math::Matrix	M_ScoreMat;

	float m_alpha = 1.0f;
	float m_addAlpha = 0.01f;

	//計算
	int Hp;
	int score;
	int gokei;
};