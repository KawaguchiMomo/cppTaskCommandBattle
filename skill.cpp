#include "skill.h"
#include <string>

// コンストラクタ
// Skill::Skill(){}

// コンストラクタ
Skill::Skill(std::string name,double HPRate,double attackRate,double defenseRate,
                double luckRate,Type type,int biAttack,int canUseNumber,std::string desc)
                :name(name),HPRate(HPRate),attackRate(attackRate),defenseRate(defenseRate),
                luckRate(luckRate),type(type),biAttack(biAttack),canUseNumber(canUseNumber),desc(desc) {}

// スキル名取得
const string& Skill::getSkillName() const
{
    return name;
}
// HP倍率取得
double Skill::getHPRate() const
{
    return HPRate;
}
// 攻撃倍率取得
double Skill::getAttackRate() const
{
    return attackRate;
}
// 防御力取得
double Skill::getDefenseRate() const
{
    return defenseRate;
}
// 運取得
double Skill::getLuckRate() const
{
    return luckRate;
}
// タイプ取得
Type Skill::getType() const
{
    return type;
}
// スキル説明取得
const string& Skill::getDesc() const
{
    return desc;
}
// 攻撃回数取得
int Skill::getBiAttack() const
{
    return biAttack;
}
// 残り使用回数セット
void Skill::setCanUseNumber(int a)
{
    canUseNumber = a;
}
// 残り使用回数取得
int Skill::getCanUseNumber() const
{
    return canUseNumber;
}
// 残り使用回数減少
void Skill::UsedCanUseNumber()
{
    canUseNumber-=1;
}
