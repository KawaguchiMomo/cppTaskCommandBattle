// SkillListはSkillSettingを格納している。

#include "skill_list.h"
#include "skill_setting.h"
#include "csv_loader.h"
#include <vector>
#include <iostream>
#include <string>
#include <memory>

enum class Type;
class SkillSetting;

// リストを取得
const std::vector< std::shared_ptr<SkillSetting> >& SkillList::getSkillList() const
{
    return skillList;
}

// csv読み込み
void SkillList::loadCSV(const std::string& filename)
{
    CsvLoader csvLoader("./");
    
    // csv読み込み
    auto loadData = csvLoader.loadCSV(filename);
    // ラベルと一致する番号を取得
    auto label = loadData[0];
    int labelIndexId = csvLoader.getLabelIndex(label, "ID");
    int labelIndexName = csvLoader.getLabelIndex(label, "NAME");
    int labelIndexHPRate = csvLoader.getLabelIndex(label, "HP");
    int labelIndexAttackRate = csvLoader.getLabelIndex(label, "POW");
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
        int id = std::stoi(v[labelIndexId]);
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
            std::cout << "タイプが間違っています。間違っているデータ: " << v[labelIndexType] << std::endl;
            exit(1);
        }
        int BiAttack = std::stoi(v[labelIndexBiAttack]);
        int CanUseNumber = std::stoi(v[labelIndexCanUseNumber]);
        std::string desc = v[labelIndexDesc];

        std::shared_ptr<SkillSetting> skillSetting = std::make_shared<SkillSetting>(
            id,
            name,
            HPRate,
            AttackRate,
            DefenseRate,
            luckRate,
            type,
            BiAttack,
            CanUseNumber,
            desc
        );

        setSkill(skillSetting);
    }
}
// リストにセット
void SkillList::setSkill(std::shared_ptr<SkillSetting> skillSetting)
{
    skillList.push_back(skillSetting);
}

// リストからスキルを取得
std::shared_ptr<const SkillSetting> SkillList::getListSkill(int i) const
{
    return skillList[i];
}

// スキルリストのIDとエネミーデータのスキルIDが一致するか走査
std::shared_ptr<const SkillSetting> SkillList::matchID(int id) const
{
    for(int i = 0; i < (int)skillList.size() ;i++)
    {
        if(skillList[i]->getID() == id){
            return skillList[i];
        }
    } 
    std::cout << "スキルIDが存在しません。存在しないデータ: " << id << std::endl;
    exit(1);

}