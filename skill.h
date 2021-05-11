#ifndef _SKILL_H
#define _SKILL_H

#include <string>
#include <vector>

using namespace std;

class Skill
{
    private:
        string skillName;
        double attackRate;
        int biAttack;
        int canUseNumber;
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
        void setAttackRate(double a);
        // 攻撃力取得
        double getAttackRate() const;
        // 攻撃回数セット
        void setBiAttack(int a);
        // 攻撃回数取得
        int getBiAttack() const;
        // 残り使用回数セット
        void setCanUseNumber(int a);
        // 残り使用回数取得
        int getCanUseNumber() const;
        // 残り使用回数減少
        void UsedCanUseNumber();
};

#endif