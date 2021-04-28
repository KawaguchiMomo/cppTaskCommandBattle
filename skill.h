#ifndef _SKILL_H
#define _SKILL_H

#include <string>
#include <vector>

using namespace std;

class Skill
{
    private:
        string skillName;
        int attackRate;
        int biAttack;
    public:
        // コンストラクタ
        Skill();
        // デストラクタ
        virtual ~Skill();
        // スキル名セット
        void setSkillName(const string& a);
        // スキル名取得
        const string& getSkillName() const;
        // 攻撃力セット
        void setAttackRate(int a);
        // 攻撃力取得
        int getAttackRate() const;
        // 攻撃回数セット
        void setBiAttack(int a);
        // 攻撃回数取得
        int getBiAttack() const;
};

#endif