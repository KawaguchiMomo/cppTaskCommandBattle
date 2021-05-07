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
        // スキル名セット
        void setSkillName(const string& a);
        // スキル名取得
        const string& getSkillName() const;
        // 攻撃力セット
        void setAttackRate(int a);
        // 攻撃力取得
        int getAttackRate() const;
        // 攻撃回数セット
        void setBiAttack(int a);
        // 攻撃回数取得
        int getBiAttack() const;
        // csv読み込み
        void loadCSV(const string& filename);
        // リストにセット
        void pushSkillList(const string& skillName,int attackRate, int biAttack);
        // リストからスキルを取得
        Skill getListSkill(int i) const;
        // リストからスキル名取得
        string getListSkillName(int i) const;
        // リストから攻撃力取得
        int getListAttackRate(int i) const;
        // リストから攻撃回数取得
        int getListBiAttack(int i) const;
};

#endif