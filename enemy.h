#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"

class Enemy : public Character
{
    public:
        // コンストラクタ
        Enemy();
        // デストラクタ
        virtual ~Enemy();
        // スキルを選択
        int inputSkill();
};

#endif