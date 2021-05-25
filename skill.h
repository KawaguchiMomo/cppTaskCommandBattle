#ifndef _SKILL_H
#define _SKILL_H

#include <string>

using namespace std;
enum class Type
{
    PASSIVE,
    ACTIVE,
};

class Skill
{
    private:
        const std::string name;
        const double HPRate;
        const double attackRate;
        const double defenseRate;
        const double luckRate;
        const Type type;
        const int biAttack;
        int canUseNumber;
        const std::string desc;
    public:
        // コンストラクタ
        // Skill();
        // コンストラクタ
        Skill(std::string name,double HPRate,double attackRate,double defenseRate,
                double luckRate,Type type,int biAttack,int canUseNumber,std::string desc);
        // スキル名取得
        const string& getSkillName() const;
        // HP取得
        double getHPRate() const;
        // 攻撃力取得
        double getAttackRate() const;
        // 防御力取得
        double getDefenseRate() const;
        // 運取得
        double getLuckRate() const;
        // タイプ取得
        Type getType() const;
        // スキル説明取得
        const string& getDesc() const;
        // 攻撃回数セット
        // void setBiAttack(int a);
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