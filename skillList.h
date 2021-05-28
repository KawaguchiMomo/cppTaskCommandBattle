#ifndef _SKILL_LIST_H
#define _SKILL_LIST_H


#include <string>
#include <vector>
#include <memory>

using namespace std;
class SkillSetting;
class SkillList
{
    private:
        std::vector< std::shared_ptr<SkillSetting> > skillList;
    public:
        // コンストラクタ
        SkillList();
        // デストラクタ
        virtual ~SkillList() = default;
        // リストを取得
        std::vector< std::shared_ptr<SkillSetting> > getSkillList() const;
        // csv読み込み
        void loadCSV(const string& filename);
        // リストにセット
        void setSkill(std::shared_ptr<SkillSetting>);
        // リストからスキルを取得
        std::shared_ptr<const SkillSetting> getListSkill(int i) const;
};

#endif