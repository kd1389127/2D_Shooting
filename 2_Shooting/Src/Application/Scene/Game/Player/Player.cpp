#include "Player.h"
#include"PlayerBullet/PlayerBullet.h"

C_Player::C_Player()
{

}

C_Player::~C_Player()
{

}

void C_Player::Init()
{
	M_PlayerBullet = std::make_shared<C_PlayerBullet>();

	M_Hp = 6;
	M_MaxHp = 6;
	M_Pos = { -450,0 };
	M_Radius = { 8.0f,8.0f };
	M_Alive = true;
	M_ScaleX = 2.5F;
	M_ScaleY = 2.5F;
	M_HpScaleX = 2.5F;
	M_HpScaleY = 2.5F;
	M_PlayerTex.Load("Texture/Player/Playership/Player_ship.png");
	M_PlayerHpTex.Load("Texture/Player/HP/Player_life_icon.png");

	M_PlayerBullet->Init();
	M_PlayerBullet->SetOwner(this);
}

void C_Player::Update()
{
	if (!M_Alive)return;

	Action();

	// 座標確定処理
	M_Pos += M_Move;

	M_PlayerBullet->Update();

	// 無敵時間のカウントダウン
	const float delta = 1.0f / 60.0f;
	if (M_IsInvincible) 
	{
		M_InvincibleTime -= delta;
		if (M_InvincibleTime <= 0.0f) {
			M_IsInvincible = false;
			M_InvincibleTime = 0.0f;
		}
	}

	m_alpha += m_addAlpha;

	M_ScaleMat = Math::Matrix::CreateScale(M_ScaleX, M_ScaleY, 1.0F);
	M_TransMat = Math::Matrix::CreateTranslation(M_Pos.x, M_Pos.y, 0);
	M_RotationMat = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(270)); //回転行列
	M_PlayerMat = M_ScaleMat * M_RotationMat *M_TransMat;	// 拡大×回転×移動

	M_ScaleMat = Math::Matrix::CreateScale(M_HpScaleX, M_HpScaleY, 1.0F);
	M_TransMat = Math::Matrix::CreateTranslation(-600, 310, 0);
	M_PlayerHp6Mat = M_ScaleMat * M_TransMat;	// 拡大×回転×移動

	M_ScaleMat = Math::Matrix::CreateScale(M_HpScaleX, M_HpScaleY, 1.0F);
	M_TransMat = Math::Matrix::CreateTranslation(-570, 310, 0);
	M_PlayerHp5Mat = M_ScaleMat * M_TransMat;	// 拡大×回転×移動

	M_ScaleMat = Math::Matrix::CreateScale(M_HpScaleX, M_HpScaleY, 1.0F);
	M_TransMat = Math::Matrix::CreateTranslation(-540, 310, 0);
	M_PlayerHp4Mat = M_ScaleMat * M_TransMat;	// 拡大×回転×移動

	M_ScaleMat = Math::Matrix::CreateScale(M_HpScaleX, M_HpScaleY, 1.0F);
	M_TransMat = Math::Matrix::CreateTranslation(-510, 310, 0);
	M_PlayerHp3Mat = M_ScaleMat * M_TransMat;	// 拡大×回転×移動

	M_ScaleMat = Math::Matrix::CreateScale(M_HpScaleX, M_HpScaleY, 1.0F);
	M_TransMat = Math::Matrix::CreateTranslation(-480, 310, 0);
	M_PlayerHp2Mat = M_ScaleMat * M_TransMat;	// 拡大×回転×移動

	M_ScaleMat = Math::Matrix::CreateScale(M_HpScaleX, M_HpScaleY, 1.0F);
	M_TransMat = Math::Matrix::CreateTranslation(-450, 310, 0);
	M_PlayerHp1Mat = M_ScaleMat * M_TransMat;	// 拡大×回転×移動
}

void C_Player::Draw()
{
	if (!M_Alive)return;

	SHADER.m_spriteShader.SetMatrix(M_PlayerMat);
	SHADER.m_spriteShader.DrawTex(&M_PlayerTex, Math::Rectangle{ 16,0,16,16 },m_alpha);

	if (M_Hp >= 6)
	{
		SHADER.m_spriteShader.SetMatrix(M_PlayerHp1Mat);
		SHADER.m_spriteShader.DrawTex(&M_PlayerHpTex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
	}
	if (M_Hp >= 5)
	{
		SHADER.m_spriteShader.SetMatrix(M_PlayerHp2Mat);
		SHADER.m_spriteShader.DrawTex(&M_PlayerHpTex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
	}
	if (M_Hp >= 4)
	{
		SHADER.m_spriteShader.SetMatrix(M_PlayerHp3Mat);
		SHADER.m_spriteShader.DrawTex(&M_PlayerHpTex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
	}
	if (M_Hp >= 3)
	{
		SHADER.m_spriteShader.SetMatrix(M_PlayerHp4Mat);
		SHADER.m_spriteShader.DrawTex(&M_PlayerHpTex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
	}
	if (M_Hp >= 2)
	{
		SHADER.m_spriteShader.SetMatrix(M_PlayerHp5Mat);
		SHADER.m_spriteShader.DrawTex(&M_PlayerHpTex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
	}
	if (M_Hp >= 1)
	{
		SHADER.m_spriteShader.SetMatrix(M_PlayerHp6Mat);
		SHADER.m_spriteShader.DrawTex(&M_PlayerHpTex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
	}

	// 無敵中は点滅（5フレームごとに描画スキップ）
	if (M_IsInvincible)
	{
		static int blinkFrame = 0;
		blinkFrame++;
		if ((blinkFrame / 10) % 2 == 0)
		{
			// 描画スキップ
			if (m_alpha > 1.0f)
			{
				m_alpha = 1.0f;
				m_addAlpha *= -4;
			}
			else if (m_alpha < 0.0f)
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

	M_PlayerBullet->Draw();

}

void C_Player::Action()
{
	if (!M_Alive)return;

	M_Move = { 0,0 };

	//自機の移動処理
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		M_Move.y += 6;
	}

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		M_Move.x -= 7;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		M_Move.y -= 6;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		M_Move.x += 7;
	}

	//スペースキーで弾発射
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		M_PlayerBullet->Shot();
	}

	//両端の判定
	if (M_Pos.x > 640 - M_Radius.x)
	{
		M_Pos.x = 640 - M_Radius.x;
	}
	if (M_Pos.x < -640 + M_Radius.x)
	{
		M_Pos.x = -640 + M_Radius.x;
	}
	//下端判定
	if (M_Pos.y < -360 + M_Radius.y)
	{
		M_Pos.y = -360 + M_Radius.y;
	}
	if (M_Pos.y > 360 - M_Radius.y)
	{
		M_Pos.y = 360 - M_Radius.y;
	}

}

void C_Player::TakeDamage(int dmg)
{
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