#include "playerList.h"
#include "player.h"
#include <vector>
#include <string>
#include "csvLoader.h"
#include <iostream>
// コンストラクタ
PlayerList::PlayerList(){
    Player player;
    playerList.push_back(player);
}
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
    auto& label = loadData[0];
    int labelIndexName = csvLoader.getLabelIndex(label, "NAME");
    int labelIndexImage = csvLoader.getLabelIndex(label, "IMAGE");
    int labelIndexHP = csvLoader.getLabelIndex(label, "HP");
    int labelIndexAttack = csvLoader.getLabelIndex(label, "ATK");
    int labelIndexDefense = csvLoader.getLabelIndex(label, "DEF");
    int labelIndexLuck = csvLoader.getLabelIndex(label, "LUC");

    // データ作成
    for (auto& v : loadData) 
    {
        // 一行目はラベルのためスキップ
        if(v == label){
            continue;
        }
        Player player;
        player.setName(v[labelIndexName]);
        player.setImage(v[labelIndexImage]);
        player.setMaxHp(stoi(v[labelIndexHP]));
        player.setHp(stoi(v[labelIndexHP]));
        player.setAttack(stod(v[labelIndexAttack]));
        player.setDefense(stod(v[labelIndexDefense]));
        player.setLuck(stoi(v[labelIndexLuck]));
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
const Player& PlayerList::getPlayer(int i) const
{
    return playerList[i];
}