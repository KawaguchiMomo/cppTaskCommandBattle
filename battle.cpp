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
    Skill skill;
    while(1)
    {
        //スキル入力
        int getSkillNumber = attackChara.inputSkill();
        //スキル発動
        skill = attackChara.getSkill(getSkillNumber);
                    cout << skill.getCanUseNumber() << endl;

        // スキル残り使用回数確認
        if(skill.getCanUseNumber() == 0)
        {
            string message = skill.getSkillName() + "は残り使用回数がない！";
            gameManager.printMessage(message);
        }else{
            // 残り使用回数減少
            attackChara.UsedCanUseNumber(getSkillNumber);
            break;
        }
    }

    string message = attackChara.getName() + "の" + skill.getSkillName() + "！";
    gameManager.printMessage(message);
   
    for(int i = 0 ; i < skill.getBiAttack();i++)
    {
        double random = (double)gameManager.GetRand(5, 15) / 10;
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
