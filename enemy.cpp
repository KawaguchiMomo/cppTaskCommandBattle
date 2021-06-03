#include "enemy.h"
#include "game_manager.h"
#include "skill_list.h"
#include <memory>
#include <iostream>

// スキル所持最大数
const int MAX_HAVE_SKILL = 4;

// コンストラクタ
Enemy::Enemy(
    std::string name, std::string image, int hp, int maxHp, double power, double defense, int luck, 
    int haveSkillNumber0, int haveSkillNumber1, int haveSkillNumber2, int haveSkillNumber3, int score, std::string talk, bool isDead
)
:Character(name, image,hp, maxHp, power, defense, luck, score, talk, isDead)
{
    // エネミーのスキルはcsvから読み込み
    haveSkillIDList.push_back(0);
    haveSkillIDList.push_back(haveSkillNumber1);
    haveSkillIDList.push_back(haveSkillNumber2);
    haveSkillIDList.push_back(haveSkillNumber3);
}


// エネミーの設定
void Enemy::settingEnemy(const SkillList& skillList)
{

    // エネミーにスキルをセット
    for(int i = 0; i < MAX_HAVE_SKILL; i++)
    {
        if(i == 0){
            // 一番目のスキルはたたかう固定
            std::unique_ptr<Skill> tatakauSkill = std::make_unique<Skill>(skillList.getListSkill(i));
            setSkill(std::move(tatakauSkill));
        } else {
            std::unique_ptr<Skill> skill = std::make_unique<Skill>(skillList.matchID(haveSkillIDList[i]));
            setSkill(std::move(skill));
        }
    }
}



// 攻撃につかうスキルを選択
int Enemy::inputSkill()
{
    int  countLimit = 100;
    GameManager &gameManager = GameManager::get_instance();
    for(int i = 0; i <= countLimit; i++)
    {
        // 乱数を生成する 
        int skillNumber = gameManager.getRand(0,3);

        // 発動条件を満たしていない場合再抽選
        if(!haveSkill[skillNumber]->isCanUse()){
            continue;
        }
        return skillNumber;
    }
    return 0;
}

// 死亡
void Enemy::onDead() 
{
    isDead = true;
    GameManager &gameManager = GameManager::get_instance();
    gameManager.printGameClear();
}
