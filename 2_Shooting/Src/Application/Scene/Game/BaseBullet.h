#pragma once

//全てのシーンの親クラス（基底クラス）

class C_BaseBullet
{
public:
	//コンストラクタ
	C_BaseBullet() {}
	//デストラクタ
	virtual ~C_BaseBullet() {}

	virtual void Init();
	virtual void Update() = 0;
	virtual void Draw();
	virtual void Release();

private:

};