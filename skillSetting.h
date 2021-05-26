#ifndef _SKILL_SETTING_H
#define _SKILL_SETTING_H

#include <string>
enum class Type
{
    PASSIVE,
    ACTIVE,
};
class SkillSetting;

class SkillSetting
{   
    private:
        const std::string name;
        const double HPRate;
        const double attackRate;
        const double defenseRate;
        const double luckRate;
        const Type type;
        const int biAttack;
        const std::string desc;

    public:
        // デフォルトコンストラクタ
        SkillSetting();
        // コンストラクタ
        SkillSetting(std::string name,double HPRate,double attackRate,double defenseRate,
                double luckRate,Type type,int biAttack,int canUseNumber, std::string desc);
        // コピーコンストラクタ(禁止にする)
        SkillSetting(const SkillSetting&) = delete;
        // 代入演算子(禁止にする)
        SkillSetting& operator=(const SkillSetting&) = delete;
        // スキル名取得
        const std::string& getSkillName() const;
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
        const std::string& getDesc() const;
        // 攻撃回数取得
        int getBiAttack() const;
        // 残り使用回数取得
        int getCanUseNumber() const;
};

#endif