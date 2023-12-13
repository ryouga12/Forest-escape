#include "System_Manager.h"
#include "../dxlib_ext/dxlib_ext.h"
#include"Player.h"


SystemManager::SystemManager()
{
  
    score = 10000;                          //スコアの初期化(10000が初期値)
    currentTime = 0;                        // タイマー開始時刻を取得
	timerActive = true;                     // タイマーがアクティブかどうかを示すフラグ
    previousTime = GetNowCount();           // 前回の時間を保持
    timerDuration = 1000;                   // タイマーの期間（1秒）
    downScore = 100;				        //経過事にスコアが下がっていく時の値
   

    

}

SystemManager::~SystemManager()
{
}

void SystemManager::draw()
{
    // スコアの描画
   /* DrawStringEx(10, 10, -1, "Score : %d", score);*/
    // 経過時間を描画
    DrawStringEx(10, 50, -1, "Timer : %f", (float)currentTime / 1000.0f); // 経過時間を秒に変換して表示
    
}



void SystemManager::update(float deltaTime)
{
 
    // タイマーがアクティブな場合のみ処理を行う
    if (timerActive) {
        // 現在の時間を取得
        int currentTimeMillis = GetNowCount();

        // 1秒経過したかをチェック
        if (currentTimeMillis - previousTime >= timerDuration) {
            // 1秒経過した場合、スコアを増加させる
            score -= downScore;

            // 現在の時間を前回の時間として更新
            previousTime = currentTimeMillis;

            //スコアが0以下になったら、0に固定する
            if (score < 0) {
                score = 0;
            }

            
        }

        


        // 経過時間も更新
        currentTime += deltaTime * timerDuration; // 経過時間をミリ秒単位で更新
    }

   
    
}



int SystemManager::getScore()
{
    return score;
}

int SystemManager::getTime()
{
    return currentTime;
}





