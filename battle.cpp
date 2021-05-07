#include "battle.h"
#include "gameManager.h"
#include "skill.h"
#include "skillList.h"

#include <iostream>

// コンストラクタ
Battle::Battle(){}
// デストラクタ
Battle::~Battle(){}

void Battle::startBattle(Character& attackChara, Character& defenseChara, const SkillList& skillList){
    //スキル入力
    int useSkillNumber = attackChara.useSkill(attackChara.inputSkill());
    //スキル発動
    const Skill& skill = skillList.getListSkill(useSkillNumber);

    cout << attackChara.getName() << "の" << skill.getSkillName() << "！" << endl;
    // cout << attackChara.getAttack() << " * " << skill.getAttackRate() << endl;

    // cout << "攻撃力: " << attack << endl << "防御力: " << defense << endl;
    
    for(int i = 0 ; i < skill.getBiAttack();i++)
    {
        // TODO:ダメージに乱数を適用する
        double attack = attackChara.getAttack() * skill.getAttackRate() * (0.1 + random() % 10);
        double defense = defenseChara.getDefense();
        double damage = (attack - defense) < 0 ? 0 : (attack - defense);
        cout << defenseChara.getName() << "に" << damage << "のダメージ！" << endl;
        defenseChara.receivedDamage(damage);
        // HPバー表示
        // gameManager.printHPBar(enemy.getHPPer());

    }
}

