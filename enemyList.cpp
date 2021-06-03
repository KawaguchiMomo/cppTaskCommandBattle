#include "enemyList.h"
#include "enemy.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "csvLoader.h"
#include "gameManager.h"

// csv読み込み
void EnemyList::loadCSV(const std::string& filename)
{

    CsvLoader csvLoader("./");

    // csv読み込み
    auto loadData = csvLoader.loadCSV(filename);
    // ラベルと一致する番号を取得
    auto& label = loadData[0];
    int labelIndexName = csvLoader.getLabelIndex(label, "NAME");
    int labelIndexImage = csvLoader.getLabelIndex(label, "IMAGE");
    int labelIndexHP = csvLoader.getLabelIndex(label, "HP");
    int labelIndexPower = csvLoader.getLabelIndex(label, "POW");
    int labelIndexDefense = csvLoader.getLabelIndex(label, "DEF");
    int labelIndexLuck = csvLoader.getLabelIndex(label, "LUC");
    int labelIndexSkill1 = csvLoader.getLabelIndex(label, "SKILL1");
    int labelIndexSkill2 = csvLoader.getLabelIndex(label, "SKILL2");
    int labelIndexSkill3 = csvLoader.getLabelIndex(label, "SKILL3");
    int labelIndexSkill4 = csvLoader.getLabelIndex(label, "SKILL4");
    int labelIndexScore = csvLoader.getLabelIndex(label, "SCORE");
    int labelIndexTalk = csvLoader.getLabelIndex(label, "TALK");

    // データ作成
    for (auto& v : loadData) 
    {
        // 一行目はラベルのためスキップ
        if(v == label){
            continue;
        }
        std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(
            v[labelIndexName],
            v[labelIndexImage],
            stoi(v[labelIndexHP]),
            stoi(v[labelIndexHP]),
            stod(v[labelIndexPower]),
            stod(v[labelIndexDefense]),
            stoi(v[labelIndexLuck]),
            stoi(v[labelIndexSkill1]),
            stoi(v[labelIndexSkill2]),
            stoi(v[labelIndexSkill3]),
            stoi(v[labelIndexSkill4]),
            stoi(v[labelIndexScore]),
            v[labelIndexTalk],
            false
        );
        setEnemy(enemy);
    }
}
// リストを取得
const std::vector< std::shared_ptr<Enemy> >& EnemyList::getEnemyList() const
{
    return enemyList;
} 
// リストにキャラをセット
void EnemyList::setEnemy(std::shared_ptr<Enemy> enemy)
{
    enemyList.push_back(std::move(enemy));
}
// リストからキャラ取得
std::shared_ptr<const Enemy> EnemyList::getEnemy(int i) const
{
    return enemyList[i];
}

// エネミーを選択
std::shared_ptr<Enemy> EnemyList::inputUseEnemy()
{
    GameManager &gameManager = GameManager::get_instance();

    system("clear");
    gameManager.printLine();
    int enemyListSize = (int)enemyList.size();
    for(int i = 0 ; i < enemyListSize ; i++)
    {
        std::cout << i + 1 << ": " << enemyList[i]->getName() << " " << std::endl;;
        // if(i % 4 == 0) { std::cout << std::endl; }
    }
    std::cout << std::endl; 

    int enemyNumber = gameManager.inputNumber("エネミーを選んでください", 1, enemyListSize);
    gameManager.printLine();
    return enemyList[enemyNumber];
}
