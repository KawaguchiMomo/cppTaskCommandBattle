#include "playerList.h"
#include "player.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "csvLoader.h"
#include "gameManager.h"
#include "character.h"


PlayerList::PlayerList(){}
// デストラクタ
PlayerList::~PlayerList(){}

// csv読み込み
void PlayerList::loadCSV(const string& filename)
{

    CsvLoader &csvLoader = CsvLoader::get_instance();

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
    int labelIndexScore = csvLoader.getLabelIndex(label, "SCORE");
    int labelIndexTalk = csvLoader.getLabelIndex(label, "TALK");

    // データ作成
    for (auto& v : loadData) 
    {

        // 一行目はラベルのためスキップ
        if(v == label){
            continue;
        }
        
        std::shared_ptr<Player> player = std::make_shared<Player>(v[labelIndexName],v[labelIndexImage],stoi(v[labelIndexHP]),stoi(v[labelIndexHP]),stod(v[labelIndexPower]),stod(v[labelIndexDefense]),stoi(v[labelIndexLuck])
        ,stoi(v[labelIndexScore]),v[labelIndexTalk],false);
        setPlayer(player);
    }
}
// リストを取得
std::vector< std::shared_ptr<Player> > PlayerList::getPlayerList()
{
    return playerList;
} 

// リストにキャラをセット
void PlayerList::setPlayer(std::shared_ptr<Player> player)
{
    playerList.push_back(std::move(player));
}
// リストからキャラ取得
std::shared_ptr<const Player> PlayerList::getPlayer(int i) const
{
    return playerList[i];
}

// プレイヤーを選択
std::shared_ptr<Player> PlayerList::inputUsePlayer()
{
    // シングルトン不採用　最終的に下記コードはやめる
    GameManager &gameManager = GameManager::get_instance();

    system("clear");
    gameManager.printLine();
    int playerListSize = (int)playerList.size();
    for(int i = 0 ; i < playerListSize ; i++)
    {
        std::cout << i + 1 << ": " << playerList[i]->getName() << " " << endl;;
        // if(i % 4 == 0) { std::cout << endl; }
    }
    std::cout << endl; 

    int playerNumber = gameManager.inputNumber("プレイヤーを選んでください", 1, playerListSize);
    system("clear");

    return playerList[playerNumber];
}
