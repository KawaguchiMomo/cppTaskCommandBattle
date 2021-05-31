#include "enemy.h"
#include "gameManager.h"
#include "skillList.h"
#include <memory>
#include <iostream>

// コンストラクタ
Enemy::Enemy(std::string name, std::string image, int hp, int maxHp, double power, double defense, int luck, int haveSkillNumber1, int haveSkillNumber2, int haveSkillNumber3, int haveSkillNumber4, int score, std::string talk, bool isDead)
                    :Character(name, image,hp, maxHp, power, defense, luck, score, talk, isDead)
    {
        // エネミーのスキルはcsvから読み込み
        haveSkillNumber.push_back(0);
        haveSkillNumber.push_back(1);
        haveSkillNumber.push_back(haveSkillNumber2);
        haveSkillNumber.push_back(haveSkillNumber3);
        haveSkillNumber.push_back(haveSkillNumber4);
    }

// デストラクタ
Enemy::~Enemy(){}

// エネミーの設定
void Enemy::settingEnemy(const SkillList& skillList)
{

    // エネミーにスキルをセット
    // settingPlayerと同じ問題
    std::unique_ptr<Skill> dummySkill = std::make_unique<Skill>(skillList.getListSkill(0));
    std::unique_ptr<Skill> tatakauSkill = std::make_unique<Skill>(skillList.getListSkill(1));
    std::unique_ptr<Skill> skill1 = std::make_unique<Skill>(skillList.getListSkill(haveSkillNumber[2]));
    std::unique_ptr<Skill> skill2 = std::make_unique<Skill>(skillList.getListSkill(haveSkillNumber[3]));
    std::unique_ptr<Skill> skill3 = std::make_unique<Skill>(skillList.getListSkill(haveSkillNumber[4]));

    setSkill(std::move(dummySkill));
    setSkill(std::move(tatakauSkill));
    setSkill(std::move(skill1));
    setSkill(std::move(skill2));
    setSkill(std::move(skill3));

}


// 攻撃につかうスキルを選択
int Enemy::inputSkill()
{

    GameManager &gameManager = GameManager::get_instance();
    int skillNumber;
    std::cout << haveSkill[0]->getSkillSetting()->getName() << std::endl;
    // 整数1~9以外はエラー、すでに書き込んである箇所はエラー
    while(1) {
        // 乱数を生成する 
        skillNumber = gameManager.GetRand(1,4);

        // 発動条件を満たしていない場合再抽選
        if(!haveSkill[skillNumber]->isCanUse()){
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
