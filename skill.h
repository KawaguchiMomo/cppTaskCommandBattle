#ifndef _SKILL_H
#define _SKILL_H
#include "skillSetting.h"
#include <string>
#include <memory>

using namespace std;

class Skill
{
    private:
        std::shared_ptr<const SkillSetting> skillSetting;
        int canUseNumber;
    public:
        // デフォルトコンストラクタ
        // Skill();
        // コンストラクタ
        Skill(std::shared_ptr<const SkillSetting> skill);
        // デストラクタ
        virtual ~Skill() = default;
        // コピーコンストラクタ
        Skill(const Skill&);
        // 代入演算子
        Skill& operator=(const Skill&);
        
        // スキルへの参照取得
        std::shared_ptr<const SkillSetting> getSkillSetting() const;
        // 残り使用回数セット
        void setCanUseNumber(int a);
        // 残り使用回数取得
        int getCanUseNumber() const;
        // スキルが使えるかどうか
        bool isCanUse() const;
        // 残り使用回数減少
        void UsedCanUseNumber();
};

#endif