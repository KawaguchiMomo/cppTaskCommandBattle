#include "skillSetting.h"

enum class Type;

// デフォルトコンストラクタ
SkillSetting::SkillSetting():id(0),name(""),HPRate(0),attackRate(0),defenseRate(0),
                luckRate(0),type(Type::PASSIVE),biAttack(0),canUseNumber(0),desc("") {}

// コンストラクタ
SkillSetting::SkillSetting(int id, std::string name,double HPRate,double attackRate,double defenseRate,
                double luckRate,Type type,int biAttack,int canUseNumber,std::string desc)
                :id(id),name(name),HPRate(HPRate),attackRate(attackRate),defenseRate(defenseRate),
                luckRate(luckRate),type(type),biAttack(biAttack),canUseNumber(canUseNumber),desc(desc) {}

// スキルID取得
const int SkillSetting::getID() const
{
    return id;
}
// スキル名取得
const std::string& SkillSetting::getName() const
{
    return name;
}
// HP倍率取得
double SkillSetting::getHPRate() const
{
    return HPRate;
}
// 攻撃倍率取得
double SkillSetting::getAttackRate() const
{
    return attackRate;
}
// 防御力取得
double SkillSetting::getDefenseRate() const
{
    return defenseRate;
}
// 運取得
double SkillSetting::getLuckRate() const
{
    return luckRate;
}
// タイプ取得
Type SkillSetting::getType() const
{
    return type;
}
// スキル説明取得
const std::string& SkillSetting::getDesc() const
{
    return desc;
}
// 攻撃回数取得
int SkillSetting::getBiAttack() const
{
    return biAttack;
}
// 残り使用回数取得
int SkillSetting::getCanUseNumber() const
{
    return canUseNumber;
}
