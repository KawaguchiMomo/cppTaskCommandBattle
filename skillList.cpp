#include "skillList.h"
#include "skill.h"
#include "csvLoader.h"
#include <vector>
#include <iostream>
#include <string>

enum class Type;

// コンストラクタ
SkillList::SkillList()
{
    Skill skill("ダミー",0,0,0,0,Type::PASSIVE,0,0,"");
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

    // csv読み込み
    auto loadData = csvLoader.loadCSV(filename);
    // ラベルと一致する番号を取得
    auto label = loadData[0];
    int labelIndexName = csvLoader.getLabelIndex(label, "NAME");
    int labelIndexHPRate = csvLoader.getLabelIndex(label, "HP");
    int labelIndexAttackRate = csvLoader.getLabelIndex(label, "ATK");
    int labelIndexDefenseRate = csvLoader.getLabelIndex(label, "DEF");
    int labelIndexluckRate = csvLoader.getLabelIndex(label, "LUC");
    int labelIndexType = csvLoader.getLabelIndex(label, "TYPE");
    int labelIndexBiAttack = csvLoader.getLabelIndex(label, "BIATK");
    int labelIndexCanUseNumber = csvLoader.getLabelIndex(label, "CANUSENUMBER");
    int labelIndexDesc = csvLoader.getLabelIndex(label, "DESC");
    

    // データ作成
    for (auto& v : loadData) 
    {
        // 一行目はラベルのためスキップ
        if(v == label){
            continue;
        }
        std::string name = v[labelIndexName];
        double HPRate = std::stod(v[labelIndexHPRate]);
        double AttackRate = std::stod(v[labelIndexAttackRate]);
        double DefenseRate = std::stod(v[labelIndexDefenseRate]);
        double luckRate = std::stod(v[labelIndexluckRate]);
        Type type;
        if(v[labelIndexType] == "PASSIVE") {
            type = Type::PASSIVE;
        }else if(v[labelIndexType] == "ACTIVE"){
            type = Type::ACTIVE;
        }else{
            cout << "タイプが間違っています。間違っているデータ: " << v[labelIndexType] << endl;
            exit(1);
        }
        int BiAttack = std::stoi(v[labelIndexBiAttack]);
        int CanUseNumber = std::stoi(v[labelIndexCanUseNumber]);
        std::string desc = v[labelIndexDesc];

        Skill skill(name,HPRate,AttackRate,DefenseRate,luckRate,type,BiAttack,CanUseNumber,desc);

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