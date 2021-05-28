#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"

class Enemy : public Character
{
    public:
        // コンストラクタ
        using Character::Character;
        // Enemy();
        // デストラクタ
        virtual ~Enemy();
        // エネミーの設定
        void settingEnemy(const SkillList& skillList);
        // スキルを選択
        int inputSkill();
        // 死亡
        void onDead();
};

#endif