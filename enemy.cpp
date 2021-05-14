#include "enemy.h"
#include "gameManager.h"

// コンストラクタ
Enemy::Enemy(){}
// デストラクタ
Enemy::~Enemy(){}

// スキルを選択
int Enemy::inputSkill()
{
    GameManager &gameManager = GameManager::get_instance();
    int skillNumber = 1;
    // 整数1~9以外はエラー、すでに書き込んである箇所はエラー
    while(1) {
        // 乱数を生成する 
        skillNumber = gameManager.GetRand(1,4);

        // 発動条件を満たしていない場合再抽選
        if(haveSkill[skillNumber].getCanUseNumber() == 0){
            continue;
        }
        break;
    }
    return skillNumber;
}

// 死亡
void Enemy::onDead() 
{
    isDead = true;
    GameManager &gameManager = GameManager::get_instance();
    gameManager.printGameClear();
}
