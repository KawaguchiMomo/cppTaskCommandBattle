#include "skillList.h"
#include "skill.h"
#include "csvLoader.h"
#include <vector>

Skill skill;
// コンストラクタ
SkillList::SkillList()
{
        pushSkillList("ダミ～",0,0);

    //string skillName,int attackRate, int biAttack
    // this->skillName = skillName;
    // this->attackRate = attackRate;
    // this->biAttack = biAttack;
}
// デストラクタ
SkillList::~SkillList(){}

// // csv読み込み
// void SkillList::loadCSV(const string& filename)
// {


//     // TODO:csvから読み込み
//     pushSkillList("たたかう",1,1);
//     pushSkillList("アタック",2,2);
//     pushSkillList("つよアタック",10000,3);
//     pushSkillList("連続アタック",10,5);
//     pushSkillList("あったく4",100,5);
//     pushSkillList("あったく5",100,5);
// }

// リストにセット
void SkillList::pushSkillList(const string& skillName,int attackRate, int biAttack)
{
    // vector<Skill>::iterator itr;
    // itr = skillList.end();
    Skill skill;
    skill.setSkillName(skillName);
    skill.setAttackRate(attackRate);
    skill.setBiAttack(biAttack);
    // skillList.push_back(skill);
    skillList.push_back(skill);
}
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
    double labelIndexRate = csvLoader.getLabelIndex(label, "RATE");
    int labelIndexBiAttack = csvLoader.getLabelIndex(label, "BIATK");

    // データ作成
    for (auto& v : loadData) 
    {
        // 一行目はラベルのためスキップ
        if(v == label){
            continue;
        }
        Skill skill;
        skill.setSkillName(v[labelIndexName]);
        skill.setAttackRate(stod(v[labelIndexRate]));
        skill.setBiAttack(stoi(v[labelIndexBiAttack]));
        setSkill(skill);
    }
}
// リストにセット
void SkillList::setSkill(Skill skill)
{
    skillList.push_back(skill);
}

// リストからスキルを取得
Skill SkillList::getListSkill(int i) const
{
    return skillList[i];
}
// リストからスキル名取得
string SkillList::getListSkillName(int i) const
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
