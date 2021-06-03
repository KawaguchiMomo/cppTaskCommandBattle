#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"

class Enemy : public Character
{
    public:
        // コンストラクタ
        Enemy(
            std::string name, 
            std::string image, 
            int hp, int maxHp, 
            double power, 
            double defense, 
            int luck, 
            int haveSkillNumber0, 
            int haveSkillNumber1, 
            int haveSkillNumber2, 
            int haveSkillNumber3, 
            int score, 
            std::string talk, 
            bool isDead
        );
        // デストラクタ
        virtual ~Enemy() = default;
        // エネミーの設定
        void settingEnemy(const SkillList& skillList);
        // スキルを選択
        int inputSkill();
    private:
        // 死亡
        void onDead();
};

#endif