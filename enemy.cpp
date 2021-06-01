#include "enemy.h"
#include "gameManager.h"
#include "skillList.h"
#include <memory>
#include <iostream>

// スキル所持最大数
const int MAXHAVESKILL = 4;

// コンストラクタ
Enemy::Enemy(std::string name, std::string image, int hp, int maxHp, double power, double defense, int luck, int haveSkillNumber0, int haveSkillNumber1, int haveSkillNumber2, int haveSkillNumber3, int score, std::string talk, bool isDead)
                    :Character(name, image,hp, maxHp, power, defense, luck, score, talk, isDead)
    {
        // エネミーのスキルはcsvから読み込み
        haveSkillIDList.push_back(0);
        haveSkillIDList.push_back(haveSkillNumber1);
        haveSkillIDList.push_back(haveSkillNumber2);
        haveSkillIDList.push_back(haveSkillNumber3);
    }

// デストラクタ
Enemy::~Enemy(){}

// エネミーの設定
void Enemy::settingEnemy(const SkillList& skillList)
{

    // エネミーにスキルをセット
    for(int i = 0; i < MAXHAVESKILL; i++)
    {
        if(i == 0){
            // 一番目のスキルはたたかう固定
            std::unique_ptr<Skill> tatakauSkill = std::make_unique<Skill>(skillList.getListSkill(i));
            setSkill(std::move(tatakauSkill));
        } else {
            int skillNumber = matchID(haveSkillIDList[i], skillList);
            std::unique_ptr<Skill> skill = std::make_unique<Skill>(skillList.getListSkill(skillNumber));
            setSkill(std::move(skill));
        }
    }
}

// スキルリストのIDとエネミーデータのスキルIDが一致するか走査
int Enemy::matchID(int id, const SkillList& skillList)
{
    for(int i = 0; i < (int)skillList.getSkillList().size() ;i++)
    {
        if(skillList.getListSkill(i)->getID() == id){
            return i;
        }
    } 
    cout << "スキルIDが存在しません。存在しないデータ: " << id << endl;
    exit(1);

}


// 攻撃につかうスキルを選択
int Enemy::inputSkill()
{
    int  countRimit = 100;
    GameManager &gameManager = GameManager::get_instance();
    int skillNumber;

    for(int i = 0; i <= countRimit; i++)
    {
        // 乱数を生成する 
        skillNumber = gameManager.GetRand(0,3);

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
