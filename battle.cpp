#include "battle.h"
#include "gameManager.h"
#include "player.h"
#include "enemy.h"
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
    cout << attackChara.getName() << "の" << skillList.getListSkillName(useSkillNumber) << "！" << endl;
    int attack = attackChara.getAttack() * skillList.getListAttackRate(useSkillNumber);
    int defense = defenseChara.getDefense();
    for(int i = 0 ; i < skillList.getListBiAttack(useSkillNumber);i++)
    {
        int damage = (attack - defense) < 0 ? 0 : (attack - defense);
        defenseChara.receivedDamage(damage);
        cout << defenseChara.getName() << "に" << damage << "のダメージ！" << endl;
        // HPバー表示
        // gameManager.printHPBar(enemy.getHPPer());

    }
}

