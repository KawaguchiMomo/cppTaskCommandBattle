#ifndef _SKILL_H
#define _SKILL_H

// #include "character.h"

#include <string>
#include <vector>

using namespace std;

class Skill
{
    private:
        vector<Skill> skillList;
        string skillName;
        int attackRate;
        int biAttack;
    public:
        // コンストラクタ
        Skill();
        // デストラクタ
        virtual ~Skill();
        // スキル名セット
        void setSkillName(string a);
        // スキル名取得
        string getSkillName() const;
        // 攻撃力セット
        void setAttackRate(int a);
        // 攻撃力取得
        int getAttackRate() const;
        // 攻撃回数セット
        void setBiAttack(int a);
        // 攻撃回数取得
        int getBiAttack() const;
        // csv読み込み
        void loadCSV(string filename);
        // リストにセット
        void setData(string skillName,int attackRate, int biAttack);
        // リストからスキル名取得
        string getListSkillName(int i) const;
        // リストから攻撃力取得
        int getListAttackRate(int i) const;
        // リストから攻撃回数取得
        int getListBiAttack(int i) const;
};

#endif