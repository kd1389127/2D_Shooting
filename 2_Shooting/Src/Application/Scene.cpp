//#include "main.h"
//#include "Scene.h"
////#include "Scene/SceneManager.h"
//
//void Scene::Draw()
//{
//
//	if (GAMESTARTFlg == 0)
//	{
//		//SceneManager::Instance().Draw();
//		/*SHADER.m_spriteShader.SetMatrix(GAMESTARTMat);
//		SHADER.m_spriteShader.DrawTex(&GAMESTARTTex, Math::Rectangle{ 0,0,48,8 }, 1.0f);*/
//
//		SHADER.m_spriteShader.DrawString(-150, -100, "Enter:スタート", Math::Vector4(1, 1, 1, 1));
//		SHADER.m_spriteShader.DrawString(-150, -150, "WASD:移動", Math::Vector4(1, 1, 1, 1));
//		SHADER.m_spriteShader.DrawString(-150, -200, "SPACE:弾を発射", Math::Vector4(1, 1, 1, 1));
//		SHADER.m_spriteShader.DrawString(-150, -250, "R:コンテニュー", Math::Vector4(1, 1, 1, 1));
//
//	}
//
//
//	if (GAMESTARTFlg == 1)
//	{
//		//自機の描画
//		M_Player.Draw();
//
//		//敵
//		for (int e = 0;e < enemyNum;e++)
//		{
//			if (enemyFlg[e] == 1)
//			{
//				SHADER.m_spriteShader.SetMatrix(enemyMat[e]);
//				if (stage == 1)
//				{
//					SHADER.m_spriteShader.DrawTex(&enemyTex, Math::Rectangle{ (int)enemyAnimCnt[e] * 16,0,16,16 }, 1.0f);
//				}
//				else if (stage == 2)
//				{
//					SHADER.m_spriteShader.DrawTex(&TbossTex, Math::Rectangle{ (int)enemyAnimCnt[e] * 16,0,16,16 }, 1.0f);
//				}
//			}
//		}
//
//		//弾
//		for (int bu = 0; bu < bulletNum; bu++)
//		{
//			if (bulletFlg[bu] == 1)
//			{
//				SHADER.m_spriteShader.SetMatrix(bulletMat[bu]);
//				SHADER.m_spriteShader.DrawTex(&bulletTex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
//			}
//		}
//
//		//中ボスの弾
//		for (int Tbu = 0;Tbu < T_bulletNum;Tbu++)
//		{
//			if (T_bulletFlg[Tbu] == 1)
//			{
//				SHADER.m_spriteShader.SetMatrix(T_bulletMat[Tbu]);
//				SHADER.m_spriteShader.DrawTex(&T_bulletTex, Math::Rectangle{ (int)T_bulletAnimCnt[Tbu] * 16,0,16,16 }, 1.0f);
//			}
//		}
//
//		//ラスボスの弾
//		for (int Rbu = 0;Rbu < R_bulletNum;Rbu++)
//		{
//			//直線
//			if (R_bulletFlg[Rbu] == 1)
//			{
//				SHADER.m_spriteShader.SetMatrix(R_bulletMat[Rbu]);
//				SHADER.m_spriteShader.DrawTex(&R_bulletTex, Math::Rectangle{ (int)R_bulletAnimCnt[Rbu] * 16,0,16,16 }, 1.0f);
//			}
//
//			//右斜め
//			if (RR_bulletFlg[Rbu] == 1)
//			{
//				SHADER.m_spriteShader.SetMatrix(RR_bulletMat[Rbu]);
//				SHADER.m_spriteShader.DrawTex(&R_bulletTex, Math::Rectangle{ (int)R_bulletAnimCnt[Rbu] * 16,0,16,16 }, 1.0f);
//			}
//
//			//左斜め
//			if (RL_bulletFlg[Rbu] == 1)
//			{
//				SHADER.m_spriteShader.SetMatrix(RL_bulletMat[Rbu]);
//				SHADER.m_spriteShader.DrawTex(&R_bulletTex, Math::Rectangle{ (int)R_bulletAnimCnt[Rbu] * 16,0,16,16 }, 1.0f);
//			}
//		}
//
//		//爆発
//		for (int ex = 0; ex < expNum; ex++)
//		{
//			if (expFlg[ex] == 1)
//			{
//				SHADER.m_spriteShader.SetMatrix(expMat[ex]);
//				SHADER.m_spriteShader.DrawTex(&expTex, Math::Rectangle{ (int)expAnimCnt[ex] * 16,0,16,16 }, 1.0f);
//			}
//		}
//
//		//中ボス
//		for (int Tb = 0;Tb < TbossNum;Tb++)
//		{
//			if (TbossFlg == 1)
//			{
//				SHADER.m_spriteShader.SetMatrix(TbossMat);
//				SHADER.m_spriteShader.DrawTex(&TbossTex, Math::Rectangle{ (int)TbossAnimCnt[Tb] * 16,0,16,16 }, 1.0f);
//			}
//		}
//
//		//ラスボス
//		for (int Rb = 0;Rb < RbossNum;Rb++)
//		{
//			if (RbossFlg == 1)
//			{
//				SHADER.m_spriteShader.SetMatrix(RbossMat);
//				SHADER.m_spriteShader.DrawTex(&RbossTex, Math::Rectangle{ (int)RbossAnimCnt[Rb] * 16,0,16,16 }, 1.0f);
//			}
//		}
//
//		//ゲームオーバー
//		if (GAMEOVERFlg == 1)
//		{
//			SHADER.m_spriteShader.SetMatrix(GAMEOVERMat);
//			SHADER.m_spriteShader.DrawTex(&GAMEOVERTex, Math::Rectangle{ 0,0,72,8 }, 1.0f);
//		}
//
//		//ゲームクリア
//		if (GAMECLEARFlg == 1)
//		{
//			SHADER.m_spriteShader.SetMatrix(GAMECLEARMat);
//			SHADER.m_spriteShader.DrawTex(&GAMECLEARTex, Math::Rectangle{ 0,0,88,8 }, 1.0f);
//		}
//
//		//自機のライフ
//		/*if (playerHp >= 3)
//		{
//			SHADER.m_spriteShader.SetMatrix(Life3Mat);
//			SHADER.m_spriteShader.DrawTex(&LifeTex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
//		}
//		if (playerHp >= 2)
//		{
//			SHADER.m_spriteShader.SetMatrix(Life2Mat);
//			SHADER.m_spriteShader.DrawTex(&LifeTex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
//		}
//		if (playerHp >= 1)
//		{
//			SHADER.m_spriteShader.SetMatrix(Life1Mat);
//			SHADER.m_spriteShader.DrawTex(&LifeTex, Math::Rectangle{ 0,0,16,16 }, 1.0f);
//		}*/
//	}
//}
//
//void Scene::Action()
//{
//	if (GAMESTARTFlg == 1)
//	{
//		//M_Player.Action();
//	}
//}
//
//void Scene::PreUpdate()
//{
//	//SceneManager::Instance().PreUpdate();
//}
//
//void Scene::Update()
//{
//	//SceneManager::Instance().Update();
//
//	/*if (GAMESTARTFlg == 0)
//	{
//		
//
//		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
//		{
//			GAMESTARTFlg = 1;
//		}
//	}
//
//	if (GAMESTARTFlg == 1)*/
//	{
//		//ステージ２に切り替え
//		if (GetAsyncKeyState('2') & 0x8000)
//		{
//			stage = 2;
//		}
//
//		M_Player.Update();
//		M_Player.Action();
//
//			//スペースキーで弾発射
//			if (GetAsyncKeyState(VK_SPACE) & 0x8000)
//			{
//				//待機時間が0の場合
//				if (shotWait == 0)
//				{
//					for (int bu = 0; bu < bulletNum; bu++)
//					{
//						if (bulletFlg[bu] == 0)	//弾が未発射の場合
//						{
//							bulletFlg[bu] = 1;	//発射状態に
//
//							//弾の座標を自機の座標にセット
//							bulletX[bu] = M_Player.GetPos().x;
//							bulletY[bu] = M_Player.GetPos().y;
//
//							shotWait = 10;		//待機時間10フレーム
//
//							break;	//1発「発射状態」にしたので弾の繰り返しを抜ける
//						}
//					}
//				}
//			}
//
//		}
//
//		//敵
//		for (int e = 0;e < 30;e++)
//		{
//			if (enemyFlg[e] == 1)
//			{
//				enemyY[e] -= 4;
//
//				//敵が下端に到達したら上がって再出現
//				if (enemyY[e] < -360 - 24)
//				{
//					enemyY[e] = rand() % (720 + 1 - 48) + (360 - 24);
//				}
//
//				//if (playerFlg == 1)
//				{
//					//自機との当たり判定
//					float a = enemyX[e] - M_Player.GetPos().x;  //底辺(X座標の差)
//					float b = enemyY[e] - M_Player.GetPos().y;  //高さ(Y座標の差)
//					float c = sqrt(a * a + b * b);  //斜辺(sqrt→ルート)
//
//					if (c < M_Player.GetRadiusX() + enemyRadius[e])
//					{
//						//敵を倒す
//						enemyFlg[e] = 0;
//
//						//自機のHPを減らす
//						//playerHp -= 1;
//
//						//爆発発生
//						Explosion(M_Player.GetPos().x, M_Player.GetPos().y);
//
//						cnt++;
//					}
//				}
//
//			}
//		}
//
//		//自機の弾発射後の処理
//		for (int bu = 0; bu < bulletNum; bu++)
//		{
//			if (bulletFlg[bu] == 1)
//			{
//				bulletY[bu] += 20;
//
//				//弾が画面から出たら未発射状態に戻す
//				if (bulletY[bu] > 360 + 8)
//				{
//					bulletFlg[bu] = 0;
//				}
//
//				//敵と弾の当たり判定
//				for (int e = 0; e < enemyNum; e++)
//				{
//					if (enemyFlg[e] == 1)	//敵が生きていたら
//					{
//						float a = enemyX[e] - bulletX[bu];	//底辺
//						float b = enemyY[e] - bulletY[bu];	//高さ
//						float c = sqrt(a * a + b * b);	//斜辺
//
//						if (c < enemyRadius[e] + 8)	//衝突していたら
//						{
//							//敵倒す
//							enemyFlg[e] = 0;
//
//							//弾消す
//							bulletFlg[bu] = 0;
//
//							//爆発発生！
//							Explosion(enemyX[e], enemyY[e]);
//
//							//倒した敵を数える
//							cnt++;
//
//							break;	//弾が未発射状態になったので敵の繰り返しを抜ける
//						}
//					}
//				}
//
//				//中ボスと弾の当たり判定
//				if (TbossFlg == 1)
//				{
//					//距離判定
//					float a = TbossX - bulletX[bu];  //底辺
//					float b = TbossY - bulletY[bu];  //高さ
//					float c = sqrt(a * a + b * b);  //斜辺
//
//					if (c < TbossRadius + 8)
//					{
//						//中ボスHPを-1
//						TbossHp -= 1;
//
//						//弾の座標に爆発発生
//						Explosion(bulletX[bu], bulletY[bu]);
//
//						//弾を未発射状態に
//						bulletFlg[bu] = 0;
//
//					}
//				}
//
//				//ラスボスと弾の当たり判定
//				if (RbossFlg == 1)
//				{
//					//距離判定
//					float a = RbossX - bulletX[bu];  //底辺
//					float b = RbossY - bulletY[bu];  //高さ
//					float c = sqrt(a * a + b * b);  //斜辺
//
//					if (c < RbossRadius + 8)
//					{
//						//ラスボスHPを-1
//						RbossHp -= 1;
//
//						//弾の座標に爆発発生
//						Explosion(bulletX[bu], bulletY[bu]);
//
//						//弾を未発射状態に
//						bulletFlg[bu] = 0;
//					}
//				}
//			}
//		}
//
//		//中ボスの弾
//		//待機時間が0の場合
//		if (TbossFlg == 1)
//		{
//			if (T_shotWait == 0 && shottime > 0)
//			{
//				for (int Tbu = 0; Tbu < T_bulletNum; Tbu++)
//				{
//					if (TbossY == 180)
//					{
//						if (T_bulletFlg[Tbu] == 0)	//弾が未発射の場合
//						{
//							T_bulletFlg[Tbu] = 1;	//発射状態に
//
//							//弾の座標を中ボスの座標にセット
//							T_bulletX[Tbu] = TbossX;
//							T_bulletY[Tbu] = TbossY;
//
//							T_shotWait = 15;		//待機時間15フレーム
//
//							break;	//1発「発射状態」にしたので弾の繰り返しを抜ける
//						}
//					}
//				}
//			}
//		}
//
//		shottime--;
//		if (shottime <= -300)
//		{
//			shottime = 300;
//		}
//
//		//中ボスの弾発射後の処理
//		for (int Tbu = 0; Tbu < T_bulletNum; Tbu++)
//		{
//			if (T_bulletFlg[Tbu] == 1)
//			{
//				T_bulletY[Tbu] -= 10;
//
//				//弾が画面から出たら未発射状態に戻す
//				if (T_bulletY[Tbu] < -360 - T_bulletRadius[Tbu])
//				{
//					T_bulletFlg[Tbu] = 0;
//				}
//
//				//敵の弾と自機の当たり判定
//				if (M_Player.GetAlive() == true)
//				{
//					float a = T_bulletX[Tbu] - M_Player.GetPos().x;  //底辺(X座標の差)
//					float b = T_bulletY[Tbu] - M_Player.GetPos().y;  //高さ(Y座標の差)
//					float c = sqrt(a * a + b * b);  //斜辺(sqrt→ルート)
//
//					if (c < M_Player.GetRadiusX() + T_bulletRadius[Tbu])
//					{
//						//弾を消す
//						T_bulletFlg[Tbu] = 0;
//
//						//自機のHPを減らす
//						//M_Player.GetHp() = -1;
//
//						//爆発発生
//						Explosion(M_Player.GetPos().x, M_Player.GetPos().x);
//					}
//				}
//			}
//		}
//
//		//ラスボスの弾
//		//待機時間が0の場合
//		if (RbossFlg == 1)
//		{
//			if (R_shotWait == 0 && Rshottime > 0)
//			{
//				for (int Rbu = 0; Rbu < R_bulletNum; Rbu++)
//				{
//					if (RbossY == 180)
//					{
//						if (R_bulletFlg[Rbu] == 0)	//弾が未発射の場合
//						{
//							R_bulletFlg[Rbu] = 1;	//発射状態に
//
//							//弾の座標をラスボスの座標にセット
//							R_bulletX[Rbu] = RbossX;
//							R_bulletY[Rbu] = RbossY;
//
//							R_shotWait = 15;		//待機時間15フレーム
//
//							break;	//1発「発射状態」にしたので弾の繰り返しを抜ける
//						}
//
//						if (RR_bulletFlg[Rbu] == 0)	//弾が未発射の場合
//						{
//							RR_bulletFlg[Rbu] = 1;	//発射状態に
//
//							//弾の座標をラスボスの座標にセット
//							RR_bulletX[Rbu] = RbossX;
//							RR_bulletY[Rbu] = RbossY;
//
//							RR_shotWait = 15;		//待機時間15フレーム
//
//							break;	//1発「発射状態」にしたので弾の繰り返しを抜ける
//						}
//
//						if (RL_bulletFlg[Rbu] == 0)	//弾が未発射の場合
//						{
//							RL_bulletFlg[Rbu] = 1;	//発射状態に
//
//							//弾の座標をラスボスの座標にセット
//							RL_bulletX[Rbu] = RbossX;
//							RL_bulletY[Rbu] = RbossY;
//
//							RL_shotWait = 15;		//待機時間15フレーム
//
//							break;	//1発「発射状態」にしたので弾の繰り返しを抜ける
//						}
//					}
//				}
//			}
//		}
//
//		Rshottime--;
//		if (Rshottime <= -180)
//		{
//			Rshottime = 180;
//		}
//
//		//ラスボスの弾発射後の処理
//		for (int Rbu = 0; Rbu < R_bulletNum; Rbu++)
//		{
//			//直線
//			if (R_bulletFlg[Rbu] == 1)
//			{
//				R_bulletY[Rbu] -= 10;
//
//				//弾が画面から出たら未発射状態に戻す
//				if (R_bulletY[Rbu] < -360 - R_bulletRadius[Rbu])
//				{
//					R_bulletFlg[Rbu] = 0;
//				}
//
//				//敵の弾と自機の当たり判定
//				if (M_Player.GetAlive() == true)
//				{
//					float a = R_bulletX[Rbu] - M_Player.GetPos().x;  //底辺(X座標の差)
//					float b = R_bulletY[Rbu] - M_Player.GetPos().y;  //高さ(Y座標の差)
//					float c = sqrt(a * a + b * b);  //斜辺(sqrt→ルート)
//
//					if (c < M_Player.GetRadiusX() + R_bulletRadius[Rbu])
//					{
//						//弾を消す
//						R_bulletFlg[Rbu] = 0;
//
//						//自機のHPを減らす
//						//playerHp -= 1;
//
//						//爆発発生
//						Explosion(M_Player.GetPos().x, M_Player.GetPos().y);
//					}
//				}
//			}
//
//			//右斜め
//			if (RR_bulletFlg[Rbu] == 1)
//			{
//				RR_bulletX[Rbu] += 10;
//				RR_bulletY[Rbu] -= 10;
//
//				//弾が画面から出たら未発射状態に戻す
//				if (RR_bulletY[Rbu] < -360 - RR_bulletRadius[Rbu])
//				{
//					RR_bulletFlg[Rbu] = 0;
//				}
//
//				//敵の弾と自機の当たり判定
//				if (M_Player.GetAlive() == true)
//				{
//					float a = RR_bulletX[Rbu] - M_Player.GetPos().x;  //底辺(X座標の差)
//					float b = RR_bulletY[Rbu] - M_Player.GetPos().y;  //高さ(Y座標の差)
//					float c = sqrt(a * a + b * b);  //斜辺(sqrt→ルート)
//
//					if (c < M_Player.GetRadiusX() + RR_bulletRadius[Rbu])
//					{
//						//弾を消す
//						RR_bulletFlg[Rbu] = 0;
//
//						//自機のHPを減らす
//						//playerHp -= 1;
//
//						//爆発発生
//						Explosion(M_Player.GetPos().x, M_Player.GetPos().y);
//					}
//				}
//			}
//
//			//左斜め
//			if (RL_bulletFlg[Rbu] == 1)
//			{
//				RL_bulletX[Rbu] -= 10;
//				RL_bulletY[Rbu] -= 10;
//
//				//弾が画面から出たら未発射状態に戻す
//				if (RL_bulletY[Rbu] < -360 - RL_bulletRadius[Rbu])
//				{
//					RL_bulletFlg[Rbu] = 0;
//				}
//
//				//敵の弾と自機の当たり判定
//				if (M_Player.GetAlive() == true)
//				{
//					float a = RL_bulletX[Rbu] - M_Player.GetPos().x;  //底辺(X座標の差)
//					float b = RL_bulletY[Rbu] - M_Player.GetPos().y;  //高さ(Y座標の差)
//					float c = sqrt(a * a + b * b);  //斜辺(sqrt→ルート)
//
//					if (c < M_Player.GetRadiusX() + RL_bulletRadius[Rbu])
//					{
//						//弾を消す
//						RL_bulletFlg[Rbu] = 0;
//
//						//自機のHPを減らす
//						//playerHp -= 1;
//
//						//爆発発生
//						Explosion(M_Player.GetPos().x, M_Player.GetPos().y);
//					}
//				}
//			}
//		}
//
//		//ステージ１
//		if (stage == 1)
//		{
//			if (cnt >= 15)
//			{
//				TbossFlg = 1;
//				cnt = 0;
//			}
//
//			//HPチェック
//			if (TbossHp <= 0)
//			{
//				//中ボスを倒す
//				TbossFlg = 0;
//
//				//爆発発生
//				Explosion(TbossX, TbossY);
//
//				//ステージ２に移行
//				stage = 2;
//
//				for (int e = 0;e < enemyNum;e++)
//				{
//					enemyFlg[e] = 1;
//					enemyX[e] = rand() % (1280 + 1 - 48) - (640 - 24);	//画面内ランダムな位置
//					enemyY[e] = rand() % (720 + 1 - 48) - (60 - 24) + 550;	//画面内ランダムな位置
//					enemyAnimCnt[e] = 0;
//					cnt = 0;
//				}
//
//			}
//		}
//
//		//ステージ２
//		if (stage == 2)
//		{
//			if (cnt >= 20)
//			{
//				RbossFlg = 1;
//				cnt = 0;
//			}
//
//			//HPチェック
//			if (RbossHp <= 0 && RbossFlg == 1)
//			{
//				//ラスボスを倒す
//				RbossFlg = 0;
//
//				//爆発発生
//				Explosion(RbossX, RbossY);
//
//				//ゲームクリアを表示
//				GAMECLEARFlg = 1;
//
//				if (GAMECLEARFlg == 1)
//				{
//					for (int e = 0;e < enemyNum;e++)
//					{
//						enemyFlg[e] = 0;
//					}
//				}
//			}
//		}
//
//		////自機のHPチェック
//		//if (playerHp <= 0 && playerFlg == 1)
//		//{
//		//	//自機死亡
//		//	playerFlg = 0;
//
//		//	//爆発発生
//		//	Explosion(playerX, playerY);
//
//		//	//ゲームオーバーを表示
//		//	GAMEOVERFlg = 1;
//		//}
//
//
//		//中ボス
//		if (M_Player.GetAlive() == true)
//		{
//			//自機と当たり判定
//			float a = TbossX - M_Player.GetPos().x;		//底辺(X座標の差)
//			float b = TbossY - M_Player.GetPos().y;		//高さ(Y座標の差)
//			float c = sqrt(a * a + b * b);	//斜辺(sqrt →　ルート)
//
//			if (c < M_Player.GetRadiusX() + TbossRadius)	//衝突していたら(斜辺 < 半径 + 半径)
//			{
//				//ボスのHPを-1
//				TbossHp -= 1;
//
//				//自機死亡
//				//playerFlg = 0;
//
//				//ゲームオーバー表示
//				GAMEOVERFlg = 1;
//
//				//爆発発生
//				Explosion(M_Player.GetPos().x, M_Player.GetPos().y);
//			}
//		}
//
//		//弾の発射待機時間
//		shotWait--;
//		if (shotWait <= 0)
//		{
//			shotWait = 0;
//		}
//
//		//中ボスの弾の発射待機時間
//		T_shotWait--;
//		if (T_shotWait <= 0)
//		{
//			T_shotWait = 0;
//		}
//
//		//ラスボスの弾の発射待機時間
//		//直線
//		R_shotWait--;
//		if (R_shotWait <= 0)
//		{
//			R_shotWait = 0;
//		}
//
//		//右斜め
//		RR_shotWait--;
//		if (RR_shotWait <= 0)
//		{
//			RR_shotWait = 0;
//		}
//
//		//左斜め
//		RL_shotWait--;
//		if (RL_shotWait <= 0)
//		{
//			RL_shotWait = 0;
//		}
//
//		//敵のアニメーション
//		for (int e = 0;e < enemyNum;e++)
//		{
//			if (enemyFlg[e] == 1)
//			{
//				enemyAnimCnt[e] += 0.1f;  //アニメーションを次のコマへ進める
//
//				//終了チェック
//				if (enemyAnimCnt[e] > 4 && stage == 1)
//				{
//					enemyAnimCnt[e] = 0;
//				}
//				else if (enemyAnimCnt[e] > 5 && stage == 2)
//				{
//					enemyAnimCnt[e] = 0;
//				}
//			}
//		}
//
//		//中ボスの弾のアニメーション
//		for (int Tbu = 0;Tbu < T_bulletNum;Tbu++)
//		{
//			if (T_bulletFlg[Tbu] == 1)
//			{
//				T_bulletAnimCnt[Tbu] += 0.1f; //アニメーションを次のコマへ進める
//
//				//終了チェック
//				if (T_bulletAnimCnt[Tbu] > 4)
//				{
//					T_bulletAnimCnt[Tbu] = 0;
//				}
//			}
//		}
//
//		//ラスボスの弾のアニメーション
//		for (int Rbu = 0;Rbu < R_bulletNum;Rbu++)
//		{
//			if (R_bulletFlg[Rbu] == 1)
//			{
//				R_bulletAnimCnt[Rbu] += 0.1f; //アニメーションを次のコマへ進める
//
//				//終了チェック
//				if (R_bulletAnimCnt[Rbu] > 8)
//				{
//					R_bulletAnimCnt[Rbu] = 0;
//				}
//			}
//		}
//
//		//中ボスのアニメーション
//		for (int Tb = 0;Tb < TbossNum;Tb++)
//		{
//			if (TbossFlg == 1)
//			{
//				TbossAnimCnt[Tb] += 0.1f;  //アニメーションを次のコマへ進める
//
//				//終了チェック
//				if (TbossAnimCnt[Tb] > 5)
//				{
//					TbossAnimCnt[Tb] = 0;
//				}
//			}
//		}
//
//		//ラスボスのアニメーション
//		for (int Rb = 0;Rb < RbossNum;Rb++)
//		{
//			if (RbossFlg == 1)
//			{
//				RbossAnimCnt[Rb] += 0.1f;  //アニメーションを次のコマへ進める
//
//				//終了チェック
//				if (RbossAnimCnt[Rb] > 6)
//				{
//					RbossAnimCnt[Rb] = 0;
//				}
//			}
//		}
//
//		//爆発のアニメーション
//		for (int ex = 0; ex < expNum; ex++)
//		{
//			if (expFlg[ex] == 1)
//			{
//				expAnimCnt[ex] += 0.1f;	//アニメーションを次のコマへ進める
//
//				//終了チェック
//				if (expAnimCnt[ex] > 5)
//				{
//					expFlg[ex] = 0;
//				}
//			}
//		}
//
//		//リセット
//		RESET();
//
//		//中ボス
//		if (TbossFlg == 1)
//		{
//			TbossY -= 3;
//			if (TbossY <= 180)
//			{
//				TbossY = 180;
//			}
//		}
//
//		//ラスボス
//		if (RbossFlg == 1)
//		{
//			RbossY -= 3;
//			if (RbossY <= 180)
//			{
//				RbossY = 180;
//			}
//		}
//
//		//ゲームオーバー
//		if (GAMEOVERFlg == 1)
//		{
//			GAMEOVERY -= 5;
//			if (GAMEOVERY <= 0)
//			{
//				GAMEOVERY = 0;
//			}
//		}
//
//		//ゲームクリア
//		if (GAMECLEARFlg == 1)
//		{
//			GAMECLEARY -= 5;
//			if (GAMECLEARY <= 0)
//			{
//				GAMECLEARY = 0;
//			}
//		}
//
//		//updateの最後に行列作成↓↓
//
//		//敵
//		for (int e = 0;e < 30;e++)
//		{
//			Math::Matrix e_trans = Math::Matrix::CreateTranslation(enemyX[e], enemyY[e], 0); //移動行列
//
//			Math::Matrix e_scale = Math::Matrix::CreateScale(enemySize[e], enemySize[e], 0); //拡縮行列
//
//			enemyMat[e] = e_scale * e_trans;
//		}
//
//		//弾
//		for (int bu = 0;bu < bulletNum;bu++)
//		{
//			bulletMat[bu] = Math::Matrix::CreateTranslation(bulletX[bu], bulletY[bu], 0);
//		}
//
//		//中ボスの弾
//		for (int Tbu = 0;Tbu < T_bulletNum;Tbu++)
//		{
//			Math::Matrix Tbu_trans = Math::Matrix::CreateTranslation(T_bulletX[Tbu], T_bulletY[Tbu], 0); //移動行列
//
//			Math::Matrix Tbu_scale = Math::Matrix::CreateScale(T_bulletSize[Tbu], T_bulletSize[Tbu], 0); //拡縮行列
//
//			T_bulletMat[Tbu] = Tbu_scale * Tbu_trans;
//		}
//
//		//ラスボスの弾
//		for (int Rbu = 0;Rbu < R_bulletNum;Rbu++)
//		{
//			//直線
//			Math::Matrix Rbu_trans = Math::Matrix::CreateTranslation(R_bulletX[Rbu], R_bulletY[Rbu], 0); //移動行列
//
//			Math::Matrix Rbu_scale = Math::Matrix::CreateScale(R_bulletSize[Rbu], R_bulletSize[Rbu], 0); //拡縮行列
//
//			R_bulletMat[Rbu] = Rbu_scale * Rbu_trans;
//
//			//右斜め
//			Math::Matrix RRbu_trans = Math::Matrix::CreateTranslation(RR_bulletX[Rbu], RR_bulletY[Rbu], 0); //移動行列
//
//			Math::Matrix RRbu_scale = Math::Matrix::CreateScale(RR_bulletSize[Rbu], RR_bulletSize[Rbu], 0); //拡縮行列
//
//			RR_bulletMat[Rbu] = RRbu_scale * RRbu_trans;
//
//			//左斜め
//			Math::Matrix RLbu_trans = Math::Matrix::CreateTranslation(RL_bulletX[Rbu], RL_bulletY[Rbu], 0); //移動行列
//
//			Math::Matrix RLbu_scale = Math::Matrix::CreateScale(RL_bulletSize[Rbu], RL_bulletSize[Rbu], 0); //拡縮行列
//
//			RL_bulletMat[Rbu] = RLbu_scale * RLbu_trans;
//		}
//
//		//爆発
//		for (int ex = 0; ex < expNum; ex++)
//		{
//			Math::Matrix exp_trans = Math::Matrix::CreateTranslation(expX[ex], expY[ex], 0); //移動行列
//
//			Math::Matrix exp_scale = Math::Matrix::CreateScale(expSize[ex], expSize[ex], 0); //拡縮行列
//
//			expMat[ex] = exp_scale * exp_trans;
//		}
//
//		//中ボス
//		Math::Matrix Tb_trans = Math::Matrix::CreateTranslation(TbossX, TbossY, 0);
//
//		Math::Matrix Tb_scale = Math::Matrix::CreateScale(TbossSize, TbossSize, 0);
//
//		TbossMat = Tb_scale * Tb_trans;
//
//		//ラスボス
//		Math::Matrix Rb_trans = Math::Matrix::CreateTranslation(RbossX, RbossY, 0);
//
//		Math::Matrix Rb_scale = Math::Matrix::CreateScale(RbossSize, RbossSize, 0);
//
//		RbossMat = Rb_scale * Rb_trans;
//
//		//ゲームオーバー
//		Math::Matrix GAME_trans = Math::Matrix::CreateTranslation(GAMEOVERX, GAMEOVERY, 0);
//
//		Math::Matrix GAME_scale = Math::Matrix::CreateScale(GAMEOVERSize, GAMEOVERSize, 0);
//
//		GAMEOVERMat = GAME_scale * GAME_trans;
//
//		//ゲームクリア
//		Math::Matrix GAMECLEAR_trans = Math::Matrix::CreateTranslation(GAMECLEARX, GAMECLEARY, 0);
//
//		Math::Matrix GAMECLEAR_scale = Math::Matrix::CreateScale(GAMECLEARSize, GAMECLEARSize, 0);
//
//		GAMECLEARMat = GAMECLEAR_scale * GAMECLEAR_trans;
//
//		//自機のライフ
//		/*if (playerHp >= 3)
//		{
//			Math::Matrix Life3_trans = Math::Matrix::CreateTranslation(Life3X, Life1Y, 0);
//
//			Math::Matrix Life3_scale = Math::Matrix::CreateScale(Life3Size, Life3Size, 0);
//
//			Life3Mat = Life3_scale * Life3_trans;
//		}
//		if (playerHp >= 2)
//		{
//			Math::Matrix Life2_trans = Math::Matrix::CreateTranslation(Life2X, Life1Y, 0);
//
//			Math::Matrix Life2_scale = Math::Matrix::CreateScale(Life2Size, Life2Size, 0);
//
//			Life2Mat = Life2_scale * Life2_trans;
//		}
//		if (playerHp >= 1)
//		{
//			Math::Matrix Life1_trans = Math::Matrix::CreateTranslation(Life1X, Life1Y, 0);
//
//			Math::Matrix Life1_scale = Math::Matrix::CreateScale(Life1Size, Life1Size, 0);
//
//			Life1Mat = Life1_scale * Life1_trans;
//		}*/
//
//	
//
//	
//}
//
//void Scene::Init()
//{
//	stage = 1;
//	//乱数の初期化処理
//	srand(time(0));
//
//	// 画像の読み込み処理
//	M_PlayerTex.Load("Texture/Mini Pixel Pack 3/Player ship/Player_ship (16 x 16).png");
//	//backTex.Load("Texture/Mini Pixel Pack 3/Space_BG (2 frames) (64 x 64).png");
//	enemyTex.Load("Texture/Mini Pixel Pack 3/Enemies/Bon_Bon (16 x 16).png");
//	bulletTex.Load("Texture/Mini Pixel Pack 3/Projectiles/Player_beam (16 x 16).png");
//	expTex.Load("Texture/Mini Pixel Pack 3/Effects/Explosion (16 x 16).png");
//	TbossTex.Load("Texture/Mini Pixel Pack 3/Enemies/Lips (16 x 16).png");
//	RbossTex.Load("Texture/Mini Pixel Pack 3/Enemies/Alan (16 x 16).png");
//	T_bulletTex.Load("Texture/Mini Pixel Pack 3/Projectiles/Enemy_projectile (16 x 16).png");
//	R_bulletTex.Load("Texture/Mini Pixel Pack 3/Projectiles/Player_charged_square_shot (16 x 16).png");
//	GAMEOVERTex.Load("Texture/Mini Pixel Pack 3/UI objects/GAME_OVER (72 x 8).png");
//	GAMECLEARTex.Load("Texture/Mini Pixel Pack 3/UI objects/GAME_CLEAR(88 x 8)_transparent.png");
//	LifeTex.Load("Texture/Mini Pixel Pack 3/UI objects/Player_life_icon (16 x 16).png");
//	GAMESTARTTex.Load("Texture/Mini Pixel Pack 3/UI objects/START (48 x 8).png");
//
//	//自機の初期化処理
//	M_Player.Init();
//	M_Player.SetStandTex(&M_PlayerTex);
//
//	//敵の初期化処理
//	for (int e = 0;e < 30;e++)
//	{
//		enemyFlg[e] = 1;
//		enemyX[e] = rand() % (1280 + 1 - 48) - (640 - 24);	//画面内ランダムな位置
//		enemyY[e] = rand() % (720 + 1 - 48) + (360 - 24);	//画面内ランダムな位置
//		enemySize[e] = 4;
//		enemyRadius[e] = 8 * enemySize[e];
//		enemyAnimCnt[e] = 0;
//		cnt = 0;
//	}
//
//	//自機の弾の初期化処理
//	for (int bu = 0;bu < bulletNum;bu++)
//	{
//		bulletX[bu] = 0;
//		bulletY[bu] = 0;
//		bulletFlg[bu] = 0;
//	}
//
//	//自機の弾の発射待機時間
//	shotWait = 0;
//
//	//中ボスの弾の初期化処理
//	for (int Tbu = 0;Tbu < T_bulletNum;Tbu++)
//	{
//		T_bulletX[Tbu] = 0;
//		T_bulletY[Tbu] = 0;
//		T_bulletFlg[Tbu] = 0;
//		T_bulletSize[Tbu] = 5;
//		T_bulletRadius[Tbu] = 8 * T_bulletSize[Tbu];
//		T_bulletAnimCnt[Tbu] = 0;
//	}
//
//	//中ボスの弾の発射待機時間
//	T_shotWait = 0;
//	
//	//ラスボスの弾の初期化処理
//	for (int Rbu = 0;Rbu < R_bulletNum;Rbu++)
//	{
//		//直線
//		R_bulletX[Rbu] = 0;
//		R_bulletY[Rbu] = 0;
//		R_bulletFlg[Rbu] = 0;
//		R_bulletSize[Rbu] = 7;
//		R_bulletRadius[Rbu] = 8 * R_bulletSize[Rbu];
//		R_bulletAnimCnt[Rbu] = 0;
//
//		//右斜め
//		RR_bulletX[Rbu] = 0;
//		RR_bulletY[Rbu] = 0;
//		RR_bulletFlg[Rbu] = 0;
//		RR_bulletSize[Rbu] = 7;
//		RR_bulletRadius[Rbu] = 8 * RR_bulletSize[Rbu];
//		RR_bulletAnimCnt[Rbu] = 0;
//
//		//左斜め
//		RL_bulletX[Rbu] = 0;
//		RL_bulletY[Rbu] = 0;
//		RL_bulletFlg[Rbu] = 0;
//		RL_bulletSize[Rbu] = 7;
//		RL_bulletRadius[Rbu] = 8 * RL_bulletSize[Rbu];
//		RL_bulletAnimCnt[Rbu] = 0;
//	}
//
//	//ラスボスの弾の発射待機時間
//	//直線
//	R_shotWait = 0;
//
//	//右斜め
//	RR_shotWait = 0;
//
//	//左斜め
//	RL_shotWait = 0;
//
//	//爆発の初期化処理
//	for (int ex = 0; ex < expNum; ex++)
//	{
//		expX[ex] = 0;
//		expY[ex] = 0;
//		expFlg[ex] = 0;
//		expAnimCnt[ex] = 0;
//		expSize[ex] = 4;
//	}
//
//	//中ボスの初期化処理
//	for (int Tb = 0;Tb < TbossNum;Tb++)
//	{
//		TbossX = 0;
//		TbossY = 360 + TbossRadius;
//		TbossFlg = 0;
//		TbossSize = 8;
//		TbossHp = 30;
//		TbossRadius = 8 * TbossSize;
//		TbossAnimCnt[Tb] = 0;
//	}
//
//	//ラスボスの初期化処理
//	for (int Rb = 0;Rb < RbossNum;Rb++)
//	{
//		RbossX = 0;
//		RbossY = 360 + RbossRadius;
//		RbossFlg = 0;
//		RbossSize = 10;
//		RbossHp = 50;
//		RbossRadius = 8 * RbossSize;
//		RbossAnimCnt[Rb] = 0;
//	}
//
//	//ゲームオーバーの初期化処理
//	GAMEOVERX = 0;
//	GAMEOVERY = 360 + 80;
//	GAMEOVERFlg = 0;
//	GAMEOVERSize = 10;
//
//	//ゲームクリアの初期化処理
//	GAMECLEARX = 0;
//	GAMECLEARY = 360 + 80;
//	GAMECLEARFlg = 0;
//	GAMECLEARSize = 10;
//
//	//自機ライフの初期化処理
//	Life1X = -640 + 45;
//	Life1Y = -360 + 50;
//	Life2X = -640 + 90;
//	Life3X = -640 + 135;
//	Life1Size = 3;
//	Life2Size = 3;
//	Life3Size = 3;
//
//	//ゲームスタート
//	GAMESTARTX = 0;
//	GAMESTARTY = 0;
//	GAMESTARTSize = 5;
//	GAMESTARTFlg = 0;
//
//}
//
//void Scene::Release()
//{
//	// 画像の解放処理
//	M_PlayerTex.Release();
//	backTex.Release();
//	enemyTex.Release();
//	bulletTex.Release();
//	expTex.Release();
//	TbossTex.Release();
//	RbossTex.Release();
//	T_bulletTex.Release();
//	GAMEOVERTex.Release();
//	GAMECLEARTex.Release();
//	GAMESTARTTex.Release();
//}
//
//void Scene::ImGuiUpdate()
//{
//	return;
//
//	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
//	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);
//
//	// デバッグウィンドウ
//	if (ImGui::Begin("Debug Window"))
//	{
//		ImGui::Text("FPS : %d", APP.m_fps);
//	}
//	ImGui::End();
//}
//
//void Scene::RESET()
//{
//	if (GetAsyncKeyState('R') & 0x8000)
//	{
//		stage = 1;
//
//		//自機
//		M_Player.Init();
//		M_Player.SetStandTex(&M_PlayerTex);
//
//		//敵
//		for (int e = 0; e < 30; e++)
//		{
//			enemyFlg[e] = 1;
//			enemyX[e] = rand() % (1280 + 1 - 48) - (640 - 24);	//画面内のランダムな位置
//			enemyY[e] = rand() % (720 + 1 - 48) + (360 - 24);	//画面内のランダムな位置
//			enemyAnimCnt[e] = 0;
//		}
//
//		//中ボス
//		for (int Tb = 0;Tb < TbossNum;Tb++)
//		{
//			TbossX = 0;
//			TbossY = 360 + TbossRadius;
//			TbossFlg = 0;
//			TbossHp = 30;
//			TbossAnimCnt[Tb] = 0;
//		}
//		cnt = 0;
//
//		//ラスボス
//		for (int Rb = 0;Rb < RbossNum;Rb++)
//		{
//			RbossX = 0;
//			RbossY = 360 + RbossRadius;
//			RbossFlg = 0;
//			RbossHp = 50;
//			RbossAnimCnt[Rb] = 0;
//		}
//
//		//自機の弾
//		for (int bu = 0;bu < bulletNum;bu++)
//		{
//			bulletX[bu] = 0;
//			bulletY[bu] = 0;
//			bulletFlg[bu] = 0;
//		}
//
//		//中ボスの弾
//		for (int Tbu = 0;Tbu < T_bulletNum;Tbu++)
//		{
//			T_bulletX[Tbu] = 0;
//			T_bulletY[Tbu] = 0;
//			T_bulletFlg[Tbu] = 0;
//			T_bulletAnimCnt[Tbu] = 0;
//		}
//
//		//ラスボスの弾
//		for (int Rbu = 0;Rbu < R_bulletNum;Rbu++)
//		{
//			R_bulletX[Rbu] = 0;
//			R_bulletY[Rbu] = 0;
//			R_bulletFlg[Rbu] = 0;
//			R_bulletAnimCnt[Rbu] = 0;
//		}
//
//		//ゲームオーバー
//		GAMEOVERX = 0;
//		GAMEOVERY = 360 + 8;
//		GAMEOVERFlg = 0;
//
//		//ゲームクリア
//		GAMECLEARX = 0;
//		GAMECLEARY = 360 + 8;
//		GAMECLEARFlg = 0;
//	}
//}
//
//void Scene::Explosion(float X, float Y)
//{
//	for (int ex = 0; ex < expNum; ex++)
//	{
//		if (expFlg[ex] == 0)	//「未発生」状態の爆発があるか
//		{
//			expFlg[ex] = 1;
//			expX[ex] = X;
//			expY[ex] = Y;
//			expAnimCnt[ex] = 0;		//1コマ目から
//
//			//爆発は1つだけ発生させる
//			break;
//		}
//	}
//}
