#include "Enemy.h"
#include "BossBullet/BossBullet.h"

void C_Enemy::Init()
{
	M_BossBullet = std::make_shared<C_BossBullet>();

	M_Pos = { 450,0 };
	M_UpPos = { 450,130 };
	M_DownPos = { 450,-130 };
	M_Alive = true;
	M_ScaleX = 3.5F;
	M_ScaleY = 3.5F;
	M_Radius = { 55.0f,55.0f };
	M_Angle = 0;
	M_Hp = 20;
	M_Tex.Load("Texture/Boss/SpaceShip_Boss.png");

	M_BossBullet->Init();
	M_BossBullet->SetOwner(this);
}

void C_Enemy::Update()
{
	if (!M_Alive)return;

	// 座標確定処理
	M_Pos += M_Move;
	
	M_BossBullet->Update();

	//毎フレーム0.5度ずつ回転
	M_Angle += 0.5f;

	//360度以上になったら-360にする
	if (M_Angle >= 360)
	{
		M_Angle -= 360;
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

}

void C_Enemy::Draw()
{
	if (!M_Alive)return;
	SHADER.m_spriteShader.SetMatrix(M_Mat);
	SHADER.m_spriteShader.DrawTex(&M_Tex, Math::Rectangle{ 0,0,110,110 }, m_alpha);

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