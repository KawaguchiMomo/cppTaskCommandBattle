#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"

#include <string>
#include <vector>

using namespace std;

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