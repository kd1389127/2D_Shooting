#include"BossBullet.h"
#include"../Enemy.h"

void C_BossBullet::Init()
{
	M_Tex.Load("Texture/Bullet/BossBullet.png");
	for (int i = 0; i < BulletNum; ++i)
	{
		M_BulletPos[i] = { 0,0 };
		M_BulletFlg[i] = false;
	}
	M_Radius = { 8.0f,8.0f };
	M_ScaleX = 1.5F;
	M_ScaleY = 1.5F;
	//自機の弾の発射待機時間
	M_ShotWait = 0;
	M_ShotTime = 300;
}

void C_BossBullet::Update()
{
	for (int i = 0; i < BulletNum; ++i)
	{
		M_BulletPos[i].x -= 10;

		if (M_BulletPos[i].x > 640)
		{
			M_BulletFlg[i] = false;
		}
		//待機時間が0の場合
		if (M_ShotWait <= 0 && M_ShotTime >= 0)
		{
			if (M_BulletFlg[i] == false)	//弾が未発射の場合
			{
				M_BulletFlg[i] = true;	//発射状態に

				//弾の座標を自機の座標にセット
				M_BulletPos[i] = M_Owner->GetPos();

				M_ShotWait = 15;		//待機時間15フレーム

				break;	//1発「発射状態」にしたので弾の繰り返しを抜ける
			}
		}
	}

	//弾の発射待機時間
	M_ShotWait--;
	if (M_ShotWait <= 0)
	{
		M_ShotWait = 0;
	}
	
	//後隙
	M_ShotTime--;
	if (M_ShotTime <= -300)
	{
		M_ShotTime = 300;
	}

	for (int i = 0; i < BulletNum; ++i)
	{
		M_ScaleMat = Math::Matrix::CreateScale(M_ScaleX, M_ScaleY, 1.0F);
		M_TransMat = Math::Matrix::CreateTranslation(M_BulletPos[i].x, M_BulletPos[i].y, 0);
		M_RotationMat = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(270)); //回転行列
		M_BulletMat[i] = M_ScaleMat * M_RotationMat * M_TransMat;	// 拡大×回転×移動
	}
}

void C_BossBullet::Draw()
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

void C_BossBullet::Release()
{
	M_Tex.Release();
}
