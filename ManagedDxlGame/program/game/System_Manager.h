#pragma once



class SystemManager {
public:
	SystemManager();
	~SystemManager();
	void update(float deltaTime);
	void draw();
	

	float  currentTime;								//���݂̎���
	bool timerActive;								//�^�C�}�[���A�N�e�B�u���ǂ����������t���O
	int score;										// �X�R�A
	int previousTime;								//�O��̎��Ԃ�ێ�
	int timerDuration;								//�^�C�}�[�̊��ԁi1�b�j
	float downScore;								//�o�ߎ��Ɏ擾�ł���X�R�A
	int getScore();									//�X�R�A���擾���郁�\�b�h
	int getTime();									//�o�ߎ��Ԃ��擾���郁�\�b�h
	

private:
	

};



