#include "battle_field.h"
#include "game_manager.h"
#include "skill.h"
#include "skill_list.h"
#include <memory>

// コンストラクタ
Battle::Battle(){}

void Battle::startBattle(std::shared_ptr<Character> attackChara, std::shared_ptr<Character> defenseChara){

    int skillNumber = attackChara->useSkill();

    // 連続攻撃系ができなくなってしまったので要改修
    // for(int i = 0 ; i < skillSetting->getBiAttack();i++)
    // {
        double power = attackChara->attack(skillNumber);

        defenseChara->receivedDamage(power);


    // }
}

