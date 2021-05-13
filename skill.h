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
        string skillName;
        double HPRate;
        double attackRate;
        double defenseRate;
        double luckRate;
        Type type;
        int biAttack;
        int canUseNumber;
        string Desc;
    public:
        // コンストラクタ
        Skill();
        // デストラクタ
        virtual ~Skill();
        // スキル名セット
        void setSkillName(const string& a);
        // スキル名取得
        const string& getSkillName() const;
        // HPセット
        void setHPRate(double a);
        // HP取得
        double getHPRate() const;
        // 攻撃力セット
        void setAttackRate(double a);
        // 攻撃力取得
        double getAttackRate() const;
        // 防御力セット
        void setDefenseRate(double a);
        // 防御力取得
        double getDefenseRate() const;
        // 運セット
        void setLuckRate(double a);
        // 運取得
        double getLuckRate() const;
        // タイプセット
        void setType(Type a);
        // タイプ取得
        Type getType() const;
        // スキル説明セット
        void setDesc(const string& a);
        // スキル説明取得
        const string& getDesc() const;
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