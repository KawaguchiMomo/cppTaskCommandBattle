#include "battle.h"
#include "gameManager.h"
#include "skill.h"
#include "skillList.h"

#include <iostream>
#include <random>
using namespace std;

// コンストラクタ
Battle::Battle(){}
// デストラクタ
Battle::~Battle(){}

void Battle::startBattle(Character& attackChara, Character& defenseChara, const SkillList& skillList){
    GameManager &gameManager = GameManager::get_instance();
    //スキル入力
    int useSkillNumber = attackChara.useSkill(attackChara.inputSkill());
    //スキル発動
    const Skill& skill = skillList.getListSkill(useSkillNumber);

    string message = attackChara.getName() + "の" + skill.getSkillName() + "！";
    gameManager.printMessage(message);

    // cout << "攻撃力: " << attack << endl << "防御力: " << defense << endl;
    
    for(int i = 0 ; i < skill.getBiAttack();i++)
    {
        double random = (double)gameManager.GetRand(5, 15) / 10;
        // cout << random << endl;
        double attack = attackChara.getAttack() * skill.getAttackRate() * random;

        // クリティカル判定
        int critLine = gameManager.GetRand(0, 100);
        if(attackChara.getLuck() >= critLine)
        {
            gameManager.printMessage("クリティカルヒット！");
            attack = attack * 2;
        }

        double defense = defenseChara.getDefense();
        // ダメージがマイナスにならないように
        double damage = (attack - defense) < 0 ? 0 : (attack - defense);

        defenseChara.receivedDamage(damage);
        string message = defenseChara.getName() + "に" + to_string(damage) + "のダメージ！";
        gameManager.printMessage(message);

        // 死亡判定
        defenseChara.judgeDead();

    }
}

