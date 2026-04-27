#pragma once

#include "../Base/BaseScene.h"

class GameScene : public BaseScene
{
public:
	//コンストラクタ
	GameScene() { Init(); }
	//デストラクタ
	~GameScene() {}

	void Init()			override;
	void Update()		override;
	void Draw()			override;
	void Release()		override;

private:
	KdTexture M_Tex;

};