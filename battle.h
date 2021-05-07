#ifndef _BATTLE_H
#define _BATTLE_H

class Character;
class SkillList;

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