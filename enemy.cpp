#include "enemy.h"
#include "gameManager.h"

// コンストラクタ
// Enemy::Enemy(){}
// デストラクタ
Enemy::~Enemy(){}

// エネミーの設定
void GameManager::settingEnemy(const SkillList& skillList)
{
    Enemy enemy;

    // エネミーにスキルをセット
    enemy = inputUseEnemy(enemyList);
    // settingPlayerと同じ問題
    Skill dummySkill(skillList.getListSkill(0), skillList.getListSkill(0)->getCanUseNumber());
    Skill tatakauSkill(skillList.getListSkill(1), skillList.getListSkill(1)->getCanUseNumber());
    Skill skill1(skillList.getListSkill(haveSkillNumber[2]), skillList.getListSkill(2)->getCanUseNumber());
    Skill skill2(skillList.getListSkill(haveSkillNumber[3]), skillList.getListSkill(3)->getCanUseNumber());
    Skill skill3(skillList.getListSkill(haveSkillNumber[4]), skillList.getListSkill(4)->getCanUseNumber());

    setSkill(dummySkill);
    setSkill(tatakauSkill);
    setSkill(skill1);
    setSkill(skill2);
    setSkill(skill3);

    return enemy;
}


// 攻撃につかうスキルを選択
int Enemy::inputSkill()
{
    GameManager &gameManager = GameManager::get_instance();
    int skillNumber = 1;
    // 整数1~9以外はエラー、すでに書き込んである箇所はエラー
    while(1) {
        // 乱数を生成する 
        skillNumber = gameManager.GetRand(1,4);

        // 発動条件を満たしていない場合再抽選
        if(haveSkill[skillNumber]->getCanUseNumber() == 0){
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
