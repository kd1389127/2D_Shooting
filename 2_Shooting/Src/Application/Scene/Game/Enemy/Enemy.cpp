#include "Enemy.h"
#include "BossBullet/BossBullet.h"

void C_Enemy::Init()
{
	M_BossBullet = std::make_shared<C_BossBullet>();
	
	M_Tex.Load("Texture/Boss/SpaceShip_Boss.png");
	
	if (M_ChangeFlg == true)
	{
		M_Tex.Load("Texture/Boss/SpaceShip_BossLast.png");
	}

	M_EnemyTex.Load("Texture/Bullet/Enemy.png");
	M_Pos = { 450,0 };
	M_UpPos = { 450,M_Pos.y + 130 };
	M_DownPos = { 450,M_Pos.y - 130 };
	M_Move = { 0,0 };
	M_Alive = true;
	M_ScaleX = 3.5F;
	M_ScaleY = 3.5F;
	M_Radius = { 47.0f,47.0f };
	M_Angle = 0;
	M_Hp = 50;
	M_ChangeFlg = false;
	
	for (int i = 0; i < EnemyNum; ++i)
	{
		M_EnemyPos[i] = { 450,200 };
		M_EnemyFlg[i] = false;
		M_EnemyScaleX = 1.5F;
		M_EnemyScaleY = 1.5F;
	}
	M_EnemyWait = 0;

	M_State = 0;

	M_Wait0 = 550;
	M_Wait1 = 550;
	M_Wait2 = 550;

	M_WaitFlg0 = false;
	M_WaitFlg1 = false;
	M_WaitFlg2 = false;

	M_BossBullet->Init();
	M_BossBullet->SetOwner(this);
}

void C_Enemy::Update()
{
	if (!M_Alive)return;

	// 座標確定処理
	M_Pos += M_Move;

	for (int i = 0; i < EnemyNum; ++i)
	{
		if (M_EnemyFlg[i] == true)
		{
			M_EnemyPos[i] += M_EnemyMove;
		}
	}

	Action();
	M_BossBullet->Update();

	//毎フレーム0.5度ずつ回転
	M_Angle += 0.5f;

	//360度以上になったら-360にする
	if (M_Angle >= 360)
	{
		M_Angle -= 360;
	}

	if (M_State == 0)
	{
		M_WaitFlg0 = true;
		M_WaitFlg1 = false;
		M_WaitFlg2 = false;
	}
	else if (M_State == 1)
	{
		M_WaitFlg0 = false;
		M_WaitFlg1 = true;
		M_WaitFlg2 = false;
	}
	else if (M_State == 2)
	{
		M_WaitFlg0 = false;
		M_WaitFlg1 = false;
		M_WaitFlg2 = true;
	}

	if (M_Hp <= 10)
	{
		M_ChangeFlg = true;
	}

	m_alpha += m_addAlpha;

	// 無敵時間のカウントダウン
	const float delta = 5.0f / 60.0f;
	if (M_IsInvincible)
	{
		M_InvincibleTime -= delta;
		if (M_InvincibleTime <= 0.0f) {
			M_IsInvincible = false;
			M_InvincibleTime = 0.0f;
		}
	}
	
	M_ScaleMat = Math::Matrix::CreateScale(M_ScaleX, M_ScaleY, 1.0F);
	M_RotationMat = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(M_Angle)); //回転行列
	M_TransMat = Math::Matrix::CreateTranslation(M_Pos.x, M_Pos.y, 0);
	M_Mat = M_ScaleMat * M_RotationMat * M_TransMat;	// 拡大×回転×移動

	for (int i = 0; i < EnemyNum; ++i)
	{
		if (M_EnemyFlg[i] == true)
		{
			M_ScaleMat = Math::Matrix::CreateScale(M_EnemyScaleX, M_EnemyScaleY, 1.0F);
			M_TransMat = Math::Matrix::CreateTranslation(M_EnemyPos[i].x, M_EnemyPos[i].y, 0);
			M_EnemyMat[i] = M_ScaleMat * M_TransMat;	// 拡大×回転×移動
		}
	}
}

void C_Enemy::Draw()
{
	if (!M_Alive)return;
	
	if (M_ChangeFlg == false || M_ChangeFlg == true)
	{
		SHADER.m_spriteShader.SetMatrix(M_Mat);
		SHADER.m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 0,0,110,110 }, m_alpha);
	}
	for (int i = 0; i < EnemyNum; ++i)
	{
		if (M_EnemyFlg[i] == true)
		{
			SHADER.m_spriteShader.SetMatrix(M_EnemyMat[i]);
			SHADER.m_spriteShader.DrawTex(&M_EnemyTex, Math::Rectangle{ 0,0,32,32 }, 1.0f);
		}
	}

	// 無敵中は点滅（5フレームごとに描画スキップ）
	if (M_IsInvincible)
	{
		static int blinkFrame = 0;
		blinkFrame++;
		if ((blinkFrame / 5) % 2 == 0)
		{
			// 描画スキップ
			if (m_alpha > 1.0f)
			{
				m_alpha = 1.0f;
				m_addAlpha *= -4;
			}

		}
	}
	else
	{
		m_alpha = 1.0f;
	}

	M_BossBullet->Draw();
}

void C_Enemy::Action()
{
	switch (M_State)
	{
	case 0:
		if (M_WaitFlg0 == true)
		{
			M_BossBullet->BossAction0();
			M_Wait0--;
			if (M_Wait0 < 0)
			{
				M_Wait0 = 0;
			}
			if (M_Wait0 == 0)
			{
				if (M_State == 0) 
				{
					M_State = 1;
					M_Pos.y = 0;
				}
				
			}
		}
		break;

	case 1:
		if (M_WaitFlg1 == true)
		{
			M_BossBullet->BossAction1();
			M_Wait1--;
			if (M_Wait1 < 0)
			{
				M_Wait1 = 0;
			}

			if (M_Wait1 < 450)
			{
				M_EnemyMove.y = 5.0f;
				for (int i = 0; i < EnemyNum; ++i)
				{
					if (M_EnemyWait <= 0)
					{
						if (M_EnemyFlg[i] == false)
						{
							M_EnemyFlg[i] = true;
							M_EnemyWait = 10;		//待機時間10フレーム
						}
					}
				}

				//敵の発射待機時間
				M_EnemyWait--;
				if (M_EnemyWait <= 0)
				{
					M_EnemyWait = 0;
				}
			}

			if (M_Wait1 == 0)
			{
				if (M_State == 1)
				{ 
					M_State = 2; 
					M_Pos.y = 0;
				}
			}
		}
		break;

	case 2:
		if (M_WaitFlg2 == true)
		{
			M_BossBullet->BossAction2();
			for (int i = 0; i < EnemyNum; ++i)
			{
				M_EnemyFlg[i] = false;
			}

			M_Wait2--;
			if (M_Wait2 < 0)
			{
				M_Wait2 = 0;
			}
			if (M_Wait2 == 0)
			{
				if (M_State == 2) 
				{
					//M_State = 0; 
					M_Pos.y = 0;
					M_Wait0 = 550;
				}
			}
		}
		break;

	case 3:
		M_BossBullet->BossAction3();
		break;

	default:
		break;
	}
	
	if (M_Hp == 10)
	{
		M_State = 3;

	}

}

void C_Enemy::TakeDamage(int dmg)
{
	if (!M_Alive)return;

	if (M_IsInvincible || !M_Alive)
	{
		M_DamageFlg = false;
		return;
	}

	M_Hp -= dmg;
	M_DamageFlg = true;
	if (M_Hp < 0) M_Hp = 0;

	if (M_Hp <= 0)
	{
		M_Alive = false;
		return;
	}

	// 無敵状態にする
	M_IsInvincible = true;
	M_InvincibleTime = 1.0f; // 1秒間無敵

}