#include "skill.h"
#include <vector>
// コンストラクタ
Skill::Skill()
{
    //string skillName,int attackRate, int biAttack
    // this->skillName = skillName;
    // this->attackRate = attackRate;
    // this->biAttack = biAttack;
}
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
