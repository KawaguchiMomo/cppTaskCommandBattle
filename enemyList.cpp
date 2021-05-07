#include "enemyList.h"
#include "enemy.h"
#include <vector>
#include <string>
#include "csvLoader.h"
#include <iostream>
// コンストラクタ
EnemyList::EnemyList(){}
// デストラクタ
EnemyList::~EnemyList(){}

// csv読み込み
void EnemyList::loadCSV(const string& filename)
{
    CsvLoader csvLoader;
    Enemy enemy;

    // csv読み込み
    auto loadData = csvLoader.loadCSV(filename);
    // ラベルと一致する番号を取得
    auto label = loadData[0];
    int labelIndexName = csvLoader.getLabelIndex(label, "NAME");
    int labelIndexHP = csvLoader.getLabelIndex(label, "HP");
    int labelIndexAttack = csvLoader.getLabelIndex(label, "ATK");
    int labelIndexDefense = csvLoader.getLabelIndex(label, "DEF");
    int labelIndexLuck = csvLoader.getLabelIndex(label, "LUC");
    int labelIndexSkill1 = csvLoader.getLabelIndex(label, "SKILL1");
    int labelIndexSkill2 = csvLoader.getLabelIndex(label, "SKILL2");
    int labelIndexSkill3 = csvLoader.getLabelIndex(label, "SKILL3");
    int labelIndexSkill4 = csvLoader.getLabelIndex(label, "SKILL4");

    // データ作成
    for (auto& v : loadData) 
    {
        // 一行目はラベルのためスキップ
        if(v == label){
            continue;
        }
        Enemy enemy;
        enemy.setName(v[labelIndexName]);
        enemy.setMaxHp(stoi(v[labelIndexHP]));
        enemy.setHp(stoi(v[labelIndexHP]));
        enemy.setAttack(stoi(v[labelIndexAttack]));
        enemy.setDefense(stoi(v[labelIndexDefense]));
        enemy.setLuck(stoi(v[labelIndexLuck]));
        enemy.setSkill(stoi(v[labelIndexSkill1]));
        enemy.setSkill(stoi(v[labelIndexSkill2]));
        enemy.setSkill(stoi(v[labelIndexSkill3]));
        enemy.setSkill(stoi(v[labelIndexSkill4]));
        setEnemy(enemy);
    }
}

// リストにキャラをセット
void EnemyList::setEnemy(Enemy& enemy)
{
    enemyList.push_back(enemy);
}
// リストからキャラ取得
Enemy& EnemyList::getEnemy(int i)
{
    return enemyList[i];
}