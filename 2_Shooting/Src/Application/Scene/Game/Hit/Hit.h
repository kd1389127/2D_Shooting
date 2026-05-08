#pragma once

// 前方宣言
class GameScene;
class C_Player;
class C_Enemy;
class C_PlayerBullet;
class C_BossBullet;

class C_Hit
{
public:
	C_Hit() { M_Owner = nullptr; }
	~C_Hit() {}

	//敵との当たり判定
	void BossHit();

	//弾との当たり判定
	void PlayerBulletHit();

	//敵との攻撃判定
	void BossBulletHit();

	void SetOwner(GameScene* _owner) { M_Owner = _owner; }

private:
	GameScene* M_Owner;
	

};