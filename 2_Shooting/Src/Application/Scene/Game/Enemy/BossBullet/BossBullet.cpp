#include"BossBullet.h"
#include"../Enemy.h"

void C_BossBullet::Init()
{
	M_Tex.Load("Texture/Bullet/BossBullet.png");
	M_EnemyTex.Load("Texture/Bullet/Enemy.png");
	for (int i = 0; i < BulletNum; ++i)
	{
		M_BulletPos[i] = { 0,0 };
		M_BulletUpPos[i] = { 0,0 };
		M_BulletDownPos[i] = { 0,0 };
		M_BulletFlg[i] = false;
		M_BulletUpFlg[i] = false;
		M_BulletDownFlg[i] = false;
		M_Radius = { 8.0f,8.0f };
	}

	for (int i = 0; i < EnemyNum; ++i)
	{
		M_EnemyFlg[i] = false;
		M_EnemyUpFlg[i] = false;
		M_EnemyDownFlg[i] = false;
		M_EnemyRadius = { 16.0f,16.0f };
	}

	for (int i = 0; i < LastBulletNum; ++i)
	{
		M_LastBulletFlg[i] = false;
		M_LastBulletUpFlg[i] = false;
		M_LastBulletDownFlg[i] = false;
		M_LastRadius = { 5.0f,5.0 };
	}

	M_ScaleX = 1.5F;
	M_ScaleY = 1.5F;

	M_EnemyScaleX = 1.0F;
	M_EnemyScaleY = 1.0F;

	M_LastScaleX = 1.5F;
	M_LastScaleY = 1.5F;

	//敵の弾の発射待機時間
	M_ShotWait = 0;
	M_ShotTime = 300;
	M_EnemyShotTime = 300;
	M_LastShotTime = 100;

	state = 0;

	AnimCnt = 0;
}

void C_BossBullet::Update()
{
	for (int i = 0; i < BulletNum; ++i)
	{
		if (M_BulletPos[i].x <= -800) {M_BulletFlg[i] = false;}
		if (M_BulletUpPos[i].x <= -800) { M_BulletUpFlg[i] = false; }
		if (M_BulletDownPos[i].x <= -800) { M_BulletDownFlg[i] = false; }

		M_ScaleMat = Math::Matrix::CreateScale(M_ScaleX, M_ScaleY, 1.0F);
		M_TransMat = Math::Matrix::CreateTranslation(M_BulletPos[i].x, M_BulletPos[i].y, 0);
		M_BulletMat[i] = M_ScaleMat * M_TransMat;	// 拡大×移動

		M_ScaleMat = Math::Matrix::CreateScale(M_ScaleX, M_ScaleY, 1.0F);
		M_TransMat = Math::Matrix::CreateTranslation(M_BulletUpPos[i].x, M_BulletUpPos[i].y, 0);
		M_BulletUpMat[i] = M_ScaleMat * M_TransMat;	// 拡大×移動

		M_ScaleMat = Math::Matrix::CreateScale(M_ScaleX, M_ScaleY, 1.0F);
		M_TransMat = Math::Matrix::CreateTranslation(M_BulletDownPos[i].x, M_BulletDownPos[i].y, 0);
		M_BulletDownMat[i] = M_ScaleMat * M_TransMat;	// 拡大×移動
	}

	for (int i = 0; i < EnemyNum; ++i)
	{
		if (M_BulletPos[i].y <= -400) { M_EnemyFlg[i] = false; }
		if (M_BulletUpPos[i].y <= -400) { M_EnemyUpFlg[i] = false; }
		if (M_BulletDownPos[i].y <= -400) { M_EnemyDownFlg[i] = false; }

		M_ScaleMat = Math::Matrix::CreateScale(M_EnemyScaleX, M_EnemyScaleY, 1.0F);
		M_TransMat = Math::Matrix::CreateTranslation(M_BulletPos[i].x, M_BulletPos[i].y, 0);
		M_EnemyMat[i] = M_ScaleMat * M_TransMat;	// 拡大×移動

		M_ScaleMat = Math::Matrix::CreateScale(M_EnemyScaleX, M_EnemyScaleY, 1.0F);
		M_TransMat = Math::Matrix::CreateTranslation(M_BulletUpPos[i].x, M_BulletUpPos[i].y, 0);
		M_EnemyUpMat[i] = M_ScaleMat * M_TransMat;	// 拡大×移動

		M_ScaleMat = Math::Matrix::CreateScale(M_EnemyScaleX, M_EnemyScaleY, 1.0F);
		M_TransMat = Math::Matrix::CreateTranslation(M_BulletDownPos[i].x, M_BulletDownPos[i].y, 0);
		M_EnemyDownMat[i] = M_ScaleMat * M_TransMat;	// 拡大×移動
	}

	for (int i = 0; i < LastBulletNum; ++i)
	{
		if (M_BulletPos[i].x <= -800) { M_LastBulletFlg[i] = false; }
		if (M_BulletUpPos[i].x <= -800) { M_LastBulletUpFlg[i] = false; }
		if (M_BulletDownPos[i].x <= -800) { M_LastBulletDownFlg[i] = false; }

		M_ScaleMat = Math::Matrix::CreateScale(M_LastScaleX, M_LastScaleY, 1.0F);
		M_TransMat = Math::Matrix::CreateTranslation(M_BulletPos[i].x, M_BulletPos[i].y, 0);
		M_LastBulletMat[i] = M_ScaleMat * M_TransMat;	// 拡大×移動

		M_ScaleMat = Math::Matrix::CreateScale(M_LastScaleX, M_LastScaleY, 1.0F);
		M_TransMat = Math::Matrix::CreateTranslation(M_BulletUpPos[i].x, M_BulletUpPos[i].y, 0);
		M_LastBulletUpMat[i] = M_ScaleMat * M_TransMat;	// 拡大×移動

		M_ScaleMat = Math::Matrix::CreateScale(M_LastScaleX, M_LastScaleY, 1.0F);
		M_TransMat = Math::Matrix::CreateTranslation(M_BulletDownPos[i].x, M_BulletDownPos[i].y, 0);
		M_LastBulletDownMat[i] = M_ScaleMat * M_TransMat;	// 拡大×移動
	}

	AnimCnt += 0.1f;  //アニメーションを次のコマへ進める

	//終了チェック
	if (AnimCnt > 4)
	{
		AnimCnt = 0;
	}
}

void C_BossBullet::Draw()
{
	for (int i = 0; i < BulletNum; ++i)
	{
		if (M_BulletFlg[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(M_BulletMat[i]);
			SHADER.m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ (int)AnimCnt * 16,0,16,16 }, 1.0f);
		}
		if (M_BulletUpFlg[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(M_BulletUpMat[i]);
			SHADER.m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ (int)AnimCnt * 16,0,16,16 }, 1.0f);
		}
		if (M_BulletDownFlg[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(M_BulletDownMat[i]);
			SHADER.m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ (int)AnimCnt * 16,0,16,16 }, 1.0f);
		}
	}

	for (int i = 0; i < EnemyNum; ++i)
	{
		if (M_EnemyFlg[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(M_EnemyMat[i]);
			SHADER.m_spriteShader.DrawTex(&M_EnemyTex, Math::Rectangle{ 0,0,32,32 }, 1.0f);
		}
		if (M_EnemyUpFlg[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(M_EnemyUpMat[i]);
			SHADER.m_spriteShader.DrawTex(&M_EnemyTex, Math::Rectangle{ 0,0,32,32 }, 1.0f);
		}
		if (M_EnemyDownFlg[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(M_EnemyDownMat[i]);
			SHADER.m_spriteShader.DrawTex(&M_EnemyTex, Math::Rectangle{ 0,0,32,32 }, 1.0f);
		}
	}

	for (int i = 0; i < LastBulletNum; ++i)
	{
		if (M_LastBulletFlg[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(M_LastBulletMat[i]);
			SHADER.m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
		}
		if (M_LastBulletUpFlg[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(M_LastBulletUpMat[i]);
			SHADER.m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
		}
		if (M_LastBulletDownFlg[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(M_LastBulletDownMat[i]);
			SHADER.m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
		}
	}
}

void C_BossBullet::BossAction0()
{
	for (int i = 0; i < EnemyNum; ++i)
	{
		if (M_EnemyFlg[i] == true) { M_EnemyFlg[i] = false; }
		if (M_EnemyUpFlg[i] == true) { M_EnemyUpFlg[i] = false; }
		if (M_EnemyDownFlg[i] == true) { M_EnemyDownFlg[i] = false; }
	}

	for (int i = 0; i < LastBulletNum; ++i)
	{
		if (M_LastBulletFlg[i] == true) { M_LastBulletFlg[i] = false; }
		if (M_LastBulletUpFlg[i] == true) { M_LastBulletUpFlg[i] = false; }
		if (M_LastBulletDownFlg[i] == true) { M_LastBulletDownFlg[i] = false; }
	}

	for (int i = 0; i < BulletNum; ++i)
	{
		M_BulletPos[i].x -= 7.5;
		M_BulletUpPos[i].x -= 7.5;
		M_BulletDownPos[i].x -= 7.5;

		//待機時間が0の場合
		if (M_ShotWait <= 0 && M_ShotTime >= 0)
		{
			if (M_BulletFlg[i] == false && M_BulletUpFlg[i] == false && M_BulletDownFlg[i] == false)	//弾が未発射の場合
			{
				//弾の座標を自機の座標にセット
				M_BulletPos[i] = M_Owner->GetPos();
				M_BulletUpPos[i] = M_Owner->GetUpPos();
				M_BulletDownPos[i] = M_Owner->GetDownPos();

				M_BulletFlg[i] = true;	//発射状態に
				M_BulletUpFlg[i] = true;	//発射状態に
				M_BulletDownFlg[i] = true;	//発射状態に

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
	
}

void C_BossBullet::BossAction1()
{
	for (int i = 0; i < EnemyNum; ++i)
	{
		if (M_EnemyFlg[i] == true) { M_EnemyFlg[i] = false; }
		if (M_EnemyUpFlg[i] == true) { M_EnemyUpFlg[i] = false; }
		if (M_EnemyDownFlg[i] == true) { M_EnemyDownFlg[i] = false; }
	}

	for (int i = 0; i < LastBulletNum; ++i)
	{
		if (M_LastBulletFlg[i] == true) { M_LastBulletFlg[i] = false; }
		if (M_LastBulletUpFlg[i] == true) { M_LastBulletUpFlg[i] = false; }
		if (M_LastBulletDownFlg[i] == true) { M_LastBulletDownFlg[i] = false; }
	}

	for (int i = 0; i < BulletNum; ++i)
	{
		if (M_BulletPos[i].y == -150) { M_BulletPos[i].x -= Rnd() * 10 + 1; M_BulletPos[i].y += 5; }
		if (M_BulletUpPos[i].y == 0) { M_BulletUpPos[i].x -= Rnd() * 10 + 1; M_BulletUpPos[i].y += 5; }
		if (M_BulletDownPos[i].y == 150) { M_BulletDownPos[i].x -= Rnd() * 10 + 1; M_BulletDownPos[i].y -= 5; }

		if (M_BulletPos[i].x <= -250) { M_BulletPos[i].y += 10; }
		if (M_BulletDownPos[i].x <= -250) { M_BulletDownPos[i].y -= 10; }

		M_BulletPos[i].x -= 6;
		M_BulletPos[i].y -= 5;
		M_BulletUpPos[i].x -= 6;
		M_BulletUpPos[i].y -= 5;
		M_BulletDownPos[i].x -= 6;
		M_BulletDownPos[i].y += 5;

		//待機時間が0の場合
		if (M_ShotWait <= 0 && M_ShotTime >= 0)
		{
			if (M_BulletFlg[i] == false && M_BulletUpFlg[i] == false && M_BulletDownFlg[i] == false)	//弾が未発射の場合
			{
				M_BulletFlg[i] = true;	//発射状態に
				M_BulletUpFlg[i] = true;	//発射状態に
				M_BulletDownFlg[i] = true;	//発射状態に

				//弾の座標を自機の座標にセット
				M_BulletPos[i] = M_Owner->GetPos();
				M_BulletUpPos[i] = M_Owner->GetUpPos();
				M_BulletDownPos[i] = M_Owner->GetDownPos();

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

}

void C_BossBullet::BossAction2()
{
	for (int i = 0; i < BulletNum; ++i)
	{
		if (M_BulletFlg[i] == true) { M_BulletFlg[i] = false; }
		if (M_BulletUpFlg[i] == true) { M_BulletUpFlg[i] = false; }
		if (M_BulletDownFlg[i] == true) { M_BulletDownFlg[i] = false; }
	}

	for (int i = 0; i < LastBulletNum; ++i)
	{
		if (M_LastBulletFlg[i] == true) { M_LastBulletFlg[i] = false; }
		if (M_LastBulletUpFlg[i] == true) { M_LastBulletUpFlg[i] = false; }
		if (M_LastBulletDownFlg[i] == true) { M_LastBulletDownFlg[i] = false; }
	}

	for (int i = 0; i < EnemyNum; ++i)
	{
		M_BulletPos[i].y -= 5;
		M_BulletUpPos[i].y -= 5;
		M_BulletDownPos[i].y -= 5;

		//待機時間が0の場合
		if (M_ShotWait <= 0 && M_EnemyShotTime >= 0)
		{
			if (M_EnemyFlg[i] == false && M_EnemyUpFlg[i] == false && M_EnemyDownFlg[i] == false)	//弾が未発射の場合
			{

				//弾の座標を自機の座標にセット
				M_BulletPos[i].x = Rnd() * 150;
				M_BulletPos[i].y = 360;
				M_BulletUpPos[i].x = Rnd() * 100 - 250;
				M_BulletUpPos[i].y = 360;
				M_BulletDownPos[i].x = Rnd() * -300 - 250;
				M_BulletDownPos[i].y = 360;

				M_EnemyFlg[i] = true;	//発射状態に
				M_EnemyUpFlg[i] = true;	//発射状態に
				M_EnemyDownFlg[i] = true;	//発射状態に

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
	M_EnemyShotTime--;
	if (M_EnemyShotTime <= -300)
	{
		M_EnemyShotTime = 300;
	}
}

void C_BossBullet::BossAction3()
{
	for (int i = 0; i < BulletNum; ++i)
	{
		if (M_BulletFlg[i] == true) { M_BulletFlg[i] = false; }
		if (M_BulletUpFlg[i] == true) { M_BulletUpFlg[i] = false; }
		if (M_BulletDownFlg[i] == true) { M_BulletDownFlg[i] = false; }
	}
	for (int i = 0; i < EnemyNum; ++i)
	{
		if (M_EnemyFlg[i] == true) { M_EnemyFlg[i] = false; }
		if (M_EnemyUpFlg[i] == true) { M_EnemyUpFlg[i] = false; }
		if (M_EnemyDownFlg[i] == true) { M_EnemyDownFlg[i] = false; }
	}

	for (int i = 0; i < LastBulletNum; ++i)
	{
		M_BulletPos[i].x -= 2;
		M_BulletUpPos[i].x -= 2;
		M_BulletDownPos[i].x -= 2;

		M_BulletPos[i].y = Rnd() * 201 - 100;
		M_BulletUpPos[i].y = Rnd() * 350 + 1;
		M_BulletDownPos[i].y = Rnd() * 351 - 350;

		M_LastScaleX = 10;
		M_LastScaleY = 10;

		//待機時間が0の場合
		if (M_ShotWait <= 0 && M_LastShotTime >= 0)
		{
			if (M_LastBulletFlg[i] == false && M_LastBulletUpFlg[i] == false && M_LastBulletDownFlg[i] == false)	//弾が未発射の場合
			{
				//弾の座標を自機の座標にセット
				M_BulletPos[i] = M_Owner->GetPos();
				M_BulletUpPos[i] = M_Owner->GetUpPos();
				M_BulletDownPos[i] = M_Owner->GetDownPos();

				M_LastBulletFlg[i] = true;		//発射状態に
				M_LastBulletUpFlg[i] = true;	//発射状態に
				M_LastBulletDownFlg[i] = true;	//発射状態に

				M_ShotWait = 10;		//待機時間10フレーム

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
	M_LastShotTime--;
	if (M_LastShotTime <= -100)
	{
		M_LastShotTime = 100;
	}
}

void C_BossBullet::Release()
{
	M_Tex.Release();
}

float C_BossBullet::Rnd()
{
	return rand() / (float)RAND_MAX;
}
