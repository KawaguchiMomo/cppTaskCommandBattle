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
        virtual ~Battle() = default;
        void startBattle(std::shared_ptr<Character> attackChara, std::shared_ptr<Character> defenseChara);

};

#endif