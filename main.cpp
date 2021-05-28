#include "csvLoader.h"
#include "character.h"
#include "player.h"
#include "playerList.h"
#include "enemy.h"
#include "enemyList.h"
#include "gameManager.h"
#include "skillList.h"
#include "skill.h"
#include "battleField.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <memory>


using namespace std;
class SkillList;

int main(){
    
    PlayerList playerList;
    EnemyList enemyList;
    GameManager &gameManager = GameManager::get_instance();
    SkillList skillList;
    Battle battleField;

    // 乱数のシード設定
    gameManager.SetRand();

    // データの読み込み
    playerList.loadCSV("../playerData.csv");
    enemyList.loadCSV("../enemyData.csv");
    skillList.loadCSV("../skillData.csv");
    cout << "oooooooooooooo" << endl;
    std::shared_ptr<Player> player = playerList.inputUsePlayer();
    cout << "aaaaaaaaaaaaaaa" << endl;
    std::shared_ptr<Enemy> enemy = enemyList.inputUseEnemy();
    gameManager.initiativeSetting(player, enemy);
    
    // 戦うキャラクターのデータを表示系にセット
    gameManager.SetCharacterData(player, enemy);

    while(1)
    {
        gameManager.printBattleWindow();
        // セットしたスキルを表示
        player->printHaveSkill();
        cout << endl;
        battleField.startBattle(player,enemy);
        battleField.startBattle(enemy,player);
        
    }

}

