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

// csv読み込み
void SkillList::loadCSV(const string& filename)
{
    CsvLoader &csvLoader = CsvLoader::get_instance();
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
    int labelIndexDesc = csvLoader.getLabelIndex(label, "DESC");
    

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
        skill.setBiAttack(stoi(v[labelIndexBiAttack]));
        skill.setCanUseNumber(stoi(v[labelIndexCanUseNumber]));
        if(v[labelIndexType] == "PASSIVE"){
            skill.setType(Type::PASSIVE);
        }else if (v[labelIndexType] == "ACTIVE"){
            skill.setType(Type::ACTIVE);
        }else{
            cout << "タイプが間違っています。間違っているデータ: " << v[labelIndexType] << endl;
            exit(1);
        }
        skill.setDesc(v[labelIndexDesc]);
        setSkill(skill);
    }
}
// リストにセット
void SkillList::setSkill(const Skill& skill)
{
    skillList.push_back(skill);
}

// リストからスキルを取得
const Skill& SkillList::getListSkill(int i) const
{
    return skillList[i];
}