#ifndef _SKILL_LIST_H
#define _SKILL_LIST_H


#include <string>
#include <vector>

using namespace std;
class SkillSetting;
class SkillList
{
    private:
        vector<SkillSetting> skillList;
    public:
        // コンストラクタ
        SkillList();
        // デストラクタ
        virtual ~SkillList();
        // リストを取得
        const vector<SkillSetting>& getSkillList() const;
        // csv読み込み
        void loadCSV(const string& filename);
        // リストにセット
        void setSkill(const SkillSetting& skillSetting);
        // リストからスキルを取得
        const SkillSetting& getListSkill(int i) const;
};

#endif