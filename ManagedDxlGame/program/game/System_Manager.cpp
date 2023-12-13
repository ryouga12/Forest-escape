#include "System_Manager.h"
#include "../dxlib_ext/dxlib_ext.h"
#include"Player.h"


SystemManager::SystemManager()
{
  
    score = 10000;                          //�X�R�A�̏�����(10000�������l)
    currentTime = 0;                        // �^�C�}�[�J�n�������擾
	timerActive = true;                     // �^�C�}�[���A�N�e�B�u���ǂ����������t���O
    previousTime = GetNowCount();           // �O��̎��Ԃ�ێ�
    timerDuration = 1000;                   // �^�C�}�[�̊��ԁi1�b�j
    downScore = 100;				        //�o�ߎ��ɃX�R�A���������Ă������̒l
   

    

}

SystemManager::~SystemManager()
{
}

void SystemManager::draw()
{
    // �X�R�A�̕`��
   /* DrawStringEx(10, 10, -1, "Score : %d", score);*/
    // �o�ߎ��Ԃ�`��
    DrawStringEx(10, 50, -1, "Timer : %f", (float)currentTime / 1000.0f); // �o�ߎ��Ԃ�b�ɕϊ����ĕ\��
    
}



void SystemManager::update(float deltaTime)
{
 
    // �^�C�}�[���A�N�e�B�u�ȏꍇ�̂ݏ������s��
    if (timerActive) {
        // ���݂̎��Ԃ��擾
        int currentTimeMillis = GetNowCount();

        // 1�b�o�߂��������`�F�b�N
        if (currentTimeMillis - previousTime >= timerDuration) {
            // 1�b�o�߂����ꍇ�A�X�R�A�𑝉�������
            score -= downScore;

            // ���݂̎��Ԃ�O��̎��ԂƂ��čX�V
            previousTime = currentTimeMillis;

            //�X�R�A��0�ȉ��ɂȂ�����A0�ɌŒ肷��
            if (score < 0) {
                score = 0;
            }

            
        }

        


        // �o�ߎ��Ԃ��X�V
        currentTime += deltaTime * timerDuration; // �o�ߎ��Ԃ��~���b�P�ʂōX�V
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





