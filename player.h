#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "character.h"

#include <string>
#include <vector>

using namespace std;

class Player : public Character
{
    public:
        // コンストラクタ
        Player();
        // デストラクタ
        virtual ~Player();
        // スキルを選択
        int inputSkill();
};

#endif