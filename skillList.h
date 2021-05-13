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
        void setSkill(Skill skill);
        // リストにセット(不要)
        void pushSkillList(const string& skillName, double HPRate, double attackRate, double defenseRate ,double luckRate, int biAttack);
        // リストからスキルを取得
        const Skill& getListSkill(int i) const;
};

#endif