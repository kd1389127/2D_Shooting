#include"PlayerBullet.h"

void C_PlayerBullet::Init()
{
	M_BulletTex.Load("Texture/Bullet/Player_beam (16 x 16).png");
	for (int i = 0; i < BulletNum; ++i)
	{
		M_Pos[i] = { 0,0 };
		M_BulletFlg[i] = false;
	}
	//自機の弾の発射待機時間
	shotWait = 0;
}

void C_PlayerBullet::Update()
{
	for (int i = 0; i < BulletNum; ++i)
	{
		if (M_BulletFlg[i] == 0)	//弾が未発射の場合
		{
			M_BulletFlg[i] = 1;	//発射状態に

			//弾の座標を自機の座標にセット
			/*M_Pos[i].x = ;
			M_Pos[i].y = ;*/

			shotWait = 10;		//待機時間10フレーム

			break;	//1発「発射状態」にしたので弾の繰り返しを抜ける
		}
	}
}

void C_PlayerBullet::Draw()
{
	for (int i = 0; i < BulletNum; ++i)
	{
		if (M_BulletFlg[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(M_BulletMat[i]);
			SHADER.m_spriteShader.DrawTex(&M_BulletTex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
		}
	}
}

void C_PlayerBullet::Release()
{
	M_BulletTex.Release();
}
