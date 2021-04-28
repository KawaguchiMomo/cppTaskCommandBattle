#ifndef _BATTLE_H
#define _BATTLE_H

#include "player.h"
#include "enemy.h"
#include "skillList.h"

class Battle
{
    public:
        // コンストラクタ
        Battle();
        // デストラクタ
        virtual ~Battle();
        void startBattle(Character& attackChara, Character& defenseChara, const SkillList& skillList);

};

#endif