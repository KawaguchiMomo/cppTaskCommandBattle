#include "skill.h"
#include <vector>

// コンストラクタ
Skill::Skill(){}
// デストラクタ
Skill::~Skill(){}


// スキル名セット
void Skill::setSkillName(const string& a)
{
    skillName = a;
}
// スキル名取得
const string& Skill::getSkillName() const
{
    return skillName;
}
// HP倍率セット
void Skill::setHPRate(double a)
{
    HPRate = a;
}
// HP倍率取得
double Skill::getHPRate() const
{
    return HPRate;
}
// 攻撃倍率セット
void Skill::setAttackRate(double a)
{
    attackRate = a;
}
// 攻撃倍率取得
double Skill::getAttackRate() const
{
    return attackRate;
}
// 防御力セット
void Skill::setDefenseRate(double a)
{
    defenseRate = a;
}
// 防御力取得
double Skill::getDefenseRate() const
{
    return defenseRate;
}
// 運セット
void Skill::setLuckRate(double a)
{
    luckRate = a;
}
// 運取得
double Skill::getLuckRate() const
{
    return luckRate;
}
// タイプセット
void Skill::setType(Type a)
{
    type = a;
}
// タイプ取得
Type Skill::getType() const
{
    return type;
}

// 攻撃回数セット
void Skill::setBiAttack(int a)
{
    biAttack = a;
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
