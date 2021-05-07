#include "playerList.h"
#include "player.h"
#include <vector>
#include <string>
#include "csvLoader.h"
#include <iostream>
// コンストラクタ
PlayerList::PlayerList(){}
// デストラクタ
PlayerList::~PlayerList(){}

// csv読み込み
void PlayerList::loadCSV(const string& filename)
{
    CsvLoader csvLoader;
    Player player;

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
        Player player;
        player.setName(v[labelIndexName]);
        player.setMaxHp(stoi(v[labelIndexHP]));
        player.setHp(stoi(v[labelIndexHP]));
        player.setAttack(stoi(v[labelIndexAttack]));
        player.setDefense(stoi(v[labelIndexDefense]));
        player.setLuck(stoi(v[labelIndexLuck]));
        player.setSkill(stoi(v[labelIndexSkill1]));
        player.setSkill(stoi(v[labelIndexSkill2]));
        player.setSkill(stoi(v[labelIndexSkill3]));
        player.setSkill(stoi(v[labelIndexSkill4]));
        setPlayer(player);
    }
}
// リストを取得
const vector<Player>& PlayerList::getPlayerList() const
{
    return playerList;
} 

// リストにキャラをセット
void PlayerList::setPlayer(Player& player)
{
    playerList.push_back(player);
}
// リストからキャラ取得
Player& PlayerList::getPlayer(int i)
{
    return playerList[i];
}