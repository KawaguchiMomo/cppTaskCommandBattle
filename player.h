#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "character.h"

class Player : public Character
{
    public:
        // コンストラクタ
        Player();
        // デストラクタ
        virtual ~Player();
        // スキルを選択
        int inputSkill();
        // 死亡
        void onDead();
};

#endif