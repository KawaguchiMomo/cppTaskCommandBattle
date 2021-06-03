#include "skill.h"
#include <string>
#include <memory>
enum class Type;


// コンストラクタ
Skill::Skill(std::shared_ptr<const SkillSetting> skillSetting)
            :skillSetting(skillSetting),canUseNumber(skillSetting->getCanUseNumber()) {    
}


// スキルへの参照取得
std::shared_ptr<const SkillSetting> Skill::getSkillSetting() const 
{
    return skillSetting;
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
void Skill::usedCanUseNumber()
{
    canUseNumber-=1;
}
