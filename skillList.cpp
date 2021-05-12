#include "skillList.h"
#include "skill.h"
#include "csvLoader.h"
#include <vector>
#include <iostream>

Skill skill;
// コンストラクタ
SkillList::SkillList()
{
    Skill skill;
    skillList.push_back(skill);
}
// デストラクタ
SkillList::~SkillList(){}

// リストを取得
const vector<Skill>& SkillList::getSkillList() const
{
    return skillList;
}

// // リストにセット
// void SkillList::pushSkillList(const string& skillName, double HPRate, double attackRate, double defenseRate ,double luckRate, int biAttack)
// {
//     // vector<Skill>::iterator itr;
//     // itr = skillList.end();
//     Skill skill;
//     skill.setSkillName(skillName);
//     skill.setHPRate(HPRate);
//     skill.setAttackRate(attackRate);
//     skill.setDefenseRate(defenseRate);
//     skill.setLuckRate(luckRate);
//     skill.setType(type);
//     skill.setBiAttack(biAttack);
//     skillList.push_back(skill);
// }
// csv読み込み
void SkillList::loadCSV(const string& filename)
{
    CsvLoader csvLoader;
    Skill skill;

    // csv読み込み
    auto loadData = csvLoader.loadCSV(filename);
    // ラベルと一致する番号を取得
    auto label = loadData[0];
    int labelIndexName = csvLoader.getLabelIndex(label, "NAME");
    int labelIndexHPRate = csvLoader.getLabelIndex(label, "HP");
    int labelIndexAttackRate = csvLoader.getLabelIndex(label, "ATK");
    int labelIndexDefenseRate = csvLoader.getLabelIndex(label, "DEF");
    int labelIndexluckRate = csvLoader.getLabelIndex(label, "LUC");
    int labelIndexBiAttack = csvLoader.getLabelIndex(label, "BIATK");
    int labelIndexCanUseNumber = csvLoader.getLabelIndex(label, "CANUSENUMBER");
    int labelIndexType = csvLoader.getLabelIndex(label, "TYPE");

    // データ作成
    for (auto& v : loadData) 
    {
        // 一行目はラベルのためスキップ
        if(v == label){
            continue;
        }
        Skill skill;
        skill.setSkillName(v[labelIndexName]);
        skill.setHPRate(stod(v[labelIndexHPRate]));
        skill.setAttackRate(stod(v[labelIndexAttackRate]));
        skill.setDefenseRate(stod(v[labelIndexDefenseRate]));
        skill.setLuckRate(stod(v[labelIndexluckRate]));
        skill.setLuckRate(stod(v[labelIndexluckRate]));
        skill.setBiAttack(stoi(v[labelIndexBiAttack]));
        skill.setCanUseNumber(stoi(v[labelIndexCanUseNumber]));
        if(v[labelIndexType] == "PASSIVE"){
            // cout << v[labelIndexType] << endl;
            skill.setType(0);
        }else{
            skill.setType(1);
        }
        setSkill(skill);
    }
}
// リストにセット
void SkillList::setSkill(Skill skill)
{
    skillList.push_back(skill);
}

// リストからスキルを取得
const Skill& SkillList::getListSkill(int i) const
{
    return skillList[i];
}
// リストからスキル名取得
const string& SkillList::getListSkillName(int i) const
{
    return skillList[i].getSkillName();
}
// リストから攻撃力取得
int SkillList::getListAttackRate(int i) const
{
    return skillList[i].getAttackRate();
}
// リストから攻撃回数取得
int SkillList::getListBiAttack(int i) const
{
    return skillList[i].getBiAttack();
}
