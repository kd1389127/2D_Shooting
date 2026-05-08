#include "Hit.h"
#include "../GameScene.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
#include "../Player/PlayerBullet/PlayerBullet.h"
#include "../Enemy/BossBullet/BossBullet.h"

void C_Hit::BossHit()
{
	C_Player &M_Player = M_Owner->GetPlayer();
	C_Enemy &M_Enemy = M_Owner->GetEnemy();

	if (M_Enemy.GetAlive() == false) return;

	const float x = M_Player.GetPos().x - M_Enemy.GetPos().x;
	const float y = M_Player.GetPos().y - M_Enemy.GetPos().y;
	const float z = sqrt(x * x + y * y);

	const float Sum = M_Enemy.GetRadiusX() + M_Player.GetRadiusX();
	if (z < Sum)
	{
		M_Player.SetAlive(false);
	}
}

void C_Hit::PlayerBulletHit()
{
	C_PlayerBullet& M_PlayerBullet = M_Owner->GetPlayerBullet();
	C_Enemy& M_Enemy = M_Owner->GetEnemy();

	if (M_Enemy.GetAlive() == false) return;

	for (int i = 0; i < M_PlayerBullet.GetBulletNum(); ++i)
	{
		float x = M_PlayerBullet.GetPos(i).x - M_Enemy.GetPos().x;
		float y = M_PlayerBullet.GetPos(i).y - M_Enemy.GetPos().y;
		float z = sqrt(x * x + y * y);
		float Sum =M_PlayerBullet.GetRadiusX() + M_Enemy.GetRadiusX();
		if (z < Sum)
		{
			M_Enemy.SetAlive(false);
			break;
		}
	}
}

void C_Hit::BossBulletHit()
{
	C_Player& M_Player = M_Owner->GetPlayer();
	C_BossBullet& M_BossBullet = M_Owner->GetBossBullet();

	if (M_Player.GetAlive() == false) return;

	for (int i = 0; i < M_BossBullet.GetBulletNum(); ++i)
	{
		float x = M_Player.GetPos().x - M_BossBullet.GetPos(i).x;
		float y = M_Player.GetPos().y - M_BossBullet.GetPos(i).y;
		float z = sqrt(x * x + y * y);
		float Sum = M_Player.GetRadiusX() + M_BossBullet.GetRadiusX();
		if (z < Sum)
		{
			M_Player.SetAlive(false);
			break;
		}
	}
}
