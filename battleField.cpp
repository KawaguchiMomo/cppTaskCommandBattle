#include "battleField.h"
#include "gameManager.h"
#include "skill.h"
#include "skillList.h"
#include <memory>

// コンストラクタ
Battle::Battle(){}

void Battle::startBattle(std::shared_ptr<Character> attackChara, std::shared_ptr<Character> defenseChara){
    int skillNumber = attackChara.useSkill();

    // 連続攻撃系ができなくなってしまったので要改修
    // for(int i = 0 ; i < skillSetting->getBiAttack();i++)
    // {
        double power = attackChara.attack(skillNumber);

        defenseChara.receivedDamage(power);


    // }
}

