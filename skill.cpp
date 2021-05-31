#include "skill.h"
#include <string>
#include <memory>
#include <iostream>
enum class Type;


// コンストラクタ
Skill::Skill(std::shared_ptr<const SkillSetting> skillSetting):skillSetting(skillSetting),canUseNumber(skillSetting->getCanUseNumber()) {    
}

// コピーコンストラクタ
Skill::Skill(const Skill& obj):skillSetting(obj.skillSetting), canUseNumber(obj.canUseNumber) {}
//代入演算子
Skill& Skill::operator=(const Skill& rhs){
    this->canUseNumber = rhs.canUseNumber;
    return *this;
}

// スキルへの参照取得
std::shared_ptr<const SkillSetting> Skill::getSkillSetting() const 
{
    return skillSetting;
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
// スキルが使えるかどうか
bool Skill::isCanUse() const
{
    if (canUseNumber == 0)
    {
        return false;
    } else {
        return true;
    }
}

// 残り使用回数減少
void Skill::UsedCanUseNumber()
{
    canUseNumber-=1;
}
