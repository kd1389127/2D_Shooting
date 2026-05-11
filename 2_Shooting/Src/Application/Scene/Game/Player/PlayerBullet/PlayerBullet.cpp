#include"PlayerBullet.h"
#include"../Player.h"

void C_PlayerBullet::Init()
{
	M_Tex.Load("Texture/Bullet/Player_beam (16 x 16).png");
	for (int i = 0; i < BulletNum; ++i)
	{
		M_BulletPos[i] = { 0,0 };
		M_BulletFlg[i] = false;
	}
	M_Radius = { 8.0f,8.0f };
	M_ScaleX = 1.5F;
	M_ScaleY = 1.5F;
	//自機の弾の発射待機時間
	shotWait = 0;
}

void C_PlayerBullet::Update()
{
	for (int i = 0; i < BulletNum; ++i)
	{
		M_BulletPos[i].x += 20;
		

		if (M_BulletPos[i].x > 640)
		{
			M_BulletFlg[i] = false;
		}

	}
	
	//弾の発射待機時間(これはfor文に入れない)
	shotWait--;
	if (shotWait <= 0)
	{
		shotWait = 0;
	}

	for (int i = 0; i < BulletNum; ++i)
	{
		M_ScaleMat = Math::Matrix::CreateScale(M_ScaleX, M_ScaleY, 1.0F);
		M_TransMat = Math::Matrix::CreateTranslation(M_BulletPos[i].x, M_BulletPos[i].y, 0);
		M_RotationMat = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(270)); //回転行列
		M_BulletMat[i] = M_ScaleMat * M_RotationMat * M_TransMat;	// 拡大×回転×移動
	}
	
}

void C_PlayerBullet::Draw()
{
	for (int i = 0; i < BulletNum; ++i)
	{
		if (M_BulletFlg[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(M_BulletMat[i]);
			SHADER.m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
		}
	}
}

void C_PlayerBullet::Shot()
{
	//待機時間が0の場合
	if (shotWait == 0)
	{
		for (int i = 0; i < BulletNum; ++i)
		{
			if (M_BulletFlg[i] == false)	//弾が未発射の場合
			{
				M_BulletFlg[i] = true;	//発射状態に

				//弾の座標を自機の座標にセット
				M_BulletPos[i] = M_Owner->GetPos();

				shotWait = 10;		//待機時間10フレーム

				break;	//1発「発射状態」にしたので弾の繰り返しを抜ける
			}
		}
	}

	
}

void C_PlayerBullet::Release()
{
	M_Tex.Release();
}