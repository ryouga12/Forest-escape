#pragma once



class SystemManager {
public:
	SystemManager();
	~SystemManager();
	void update(float deltaTime);
	void draw();
	

	float  currentTime;								//現在の時間
	bool timerActive;								//タイマーがアクティブかどうかを示すフラグ
	int score;										// スコア
	int previousTime;								//前回の時間を保持
	int timerDuration;								//タイマーの期間（1秒）
	float downScore;								//経過事に取得できるスコア
	int getScore();									//スコアを取得するメソッド
	int getTime();									//経過時間を取得するメソッド
	

private:
	

};



