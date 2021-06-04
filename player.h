#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "character.h"

class Player : public Character
{
    public:
        // コンストラクタ
        using Character::Character;
        // Player();
        // 取得スキルを選択
        std::unique_ptr<Skill> inputUseSkill(const SkillList& skillList);
        // プレイヤーの設定
        void settingPlayer(const SkillList& skillList);
        // スキルを選択
        int inputSkill();
        // 取得しているスキル表示
        void printHaveSkill() const;
        // 死亡
        void onDead();
};

#endif