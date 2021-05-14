#ifndef _SKILL_LIST_H
#define _SKILL_LIST_H


#include <string>
#include <vector>

using namespace std;
class Skill;
class SkillList
{
    private:
        vector<Skill> skillList;
    public:
        // コンストラクタ
        SkillList();
        // デストラクタ
        virtual ~SkillList();
        // リストを取得
        const vector<Skill>& getSkillList() const;
        // csv読み込み
        void loadCSV(const string& filename);
        // リストにセット
        void setSkill(const Skill& skill);
        // リストからスキルを取得
        const Skill& getListSkill(int i) const;
};

#endif