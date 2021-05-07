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
    const  Skill& skill = skillList.getListSkill(useSkillNumber);

    cout << attackChara.getName() << "の" << skill.getSkillName() << "！" << endl;
    int attack = attackChara.getAttack() * skill.getAttackRate();
    int defense = defenseChara.getDefense();
    
    for(int i = 0 ; i < skill.getBiAttack();i++)
    {
        int damage = (attack - defense) < 0 ? 0 : (attack - defense);
        cout << defenseChara.getName() << "に" << damage << "のダメージ！" << endl;
        defenseChara.receivedDamage(damage);
        // HPバー表示
        // gameManager.printHPBar(enemy.getHPPer());

    }
}

