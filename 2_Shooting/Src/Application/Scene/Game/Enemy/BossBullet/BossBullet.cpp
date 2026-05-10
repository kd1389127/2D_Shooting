#include"BossBullet.h"
#include"../Enemy.h"

void C_BossBullet::Init()
{
	M_Tex.Load("Texture/Bullet/BossBullet.png");
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
	M_ScaleX = 1.5F;
	M_ScaleY = 1.5F;
	//自機の弾の発射待機時間
	M_ShotWait = 0;
	M_ShotTime = 300;
	M_ShotTime1 = 300;

	state = 0;
}

void C_BossBullet::Update()
{
	Action();

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
		if (M_BulletUpFlg[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(M_BulletUpMat[i]);
			SHADER.m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
		}
		if (M_BulletDownFlg[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(M_BulletDownMat[i]);
			SHADER.m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
		}
	}
}

void C_BossBullet::Action()
{
	switch (state)
	{
	case 0:
		for (int i = 0; i < BulletNum; ++i)
		{
			M_BulletPos[i].x -= 10;
			M_BulletUpPos[i].x -= 10;
			M_BulletDownPos[i].x -= 10;

			if (M_BulletPos[i].x > 640)
			{
				M_BulletFlg[i] = false;
			}
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


		break;

	case 1:
		for (int i = 0; i < BulletNum; ++i)
		{
			if (M_BulletPos[i].y == -150) {M_BulletPos[i].x -= Rnd() * 10 + 1; M_BulletPos[i].y += 5; }
			if (M_BulletUpPos[i].y == 0) { M_BulletUpPos[i].x -= Rnd() * 10 + 1; M_BulletUpPos[i].y += 5; }
			if (M_BulletDownPos[i].y == 150) { M_BulletDownPos[i].x -= Rnd() * 10 + 1; M_BulletDownPos[i].y -= 5; }

			if (M_BulletPos[i].x <= -250) { M_BulletPos[i].y += 10; }
			if (M_BulletDownPos[i].x <= -250) { M_BulletDownPos[i].y -= 10; }

			M_BulletPos[i].x -= 5;
			M_BulletPos[i].y -= 5;
			M_BulletUpPos[i].x -= 5;
			M_BulletUpPos[i].y -= 5;
			M_BulletDownPos[i].x -= 5;
			M_BulletDownPos[i].y += 5;

			//待機時間が0の場合
			if (M_ShotWait <= 0 && M_ShotTime1 >= 0)
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
		break;
		
	case 2:

		break;

	case 3:

		break;

	default:
		break;
	}

	//動きの再抽選
	//if (state == 1 || state == 2 || state == 3)state = 0;
	
	//else if (state == 0)state = Rnd() * 3 + 1;

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
		if (state == 0)state = 1;
		M_ShotTime = 300;
	}
	M_ShotTime1--;
	if (M_ShotTime1 <= -300)
	{
		if (state == 1)state = 0;
		M_ShotTime = 300;
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
