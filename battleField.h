#ifndef _BATTLE_H
#define _BATTLE_H
#include <memory>
class Character;
class SkillList;

class Battle
{
    public:
        // コンストラクタ
        Battle();
        // デストラクタ
        virtual ~Battle() = default;
        // 戦闘処理
        void startBattle(std::shared_ptr<Character> attackChara, std::shared_ptr<Character> defenseChara);

};

#endif