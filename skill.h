#ifndef _SKILL_H
#define _SKILL_H

// #include "character.h"

#include <string>
#include <vector>

using namespace std;

class Skill
{
    private:
        int attackRate;
        int biAttack;
    public:
        // コンストラクタ
        Skill();
        // デストラクタ
        virtual ~Skill();
};

#endif