#include "csvLoader.h"
#include "character.h"
#include "player.h"
#include "playerList.h"
#include "enemy.h"
#include "enemyList.h"
#include "gameManager.h"
#include "skillList.h"
#include "skill.h"
#include "battle.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>


using namespace std;

int main(){
    
    Player player;
    PlayerList playerList;
    Enemy enemy;
    EnemyList enemyList;
    GameManager &gameManager = GameManager::get_instance();
    SkillList skillList;
    Battle battle;

    // 乱数のシード設定
    gameManager.SetRand();

    // データの読み込み
    playerList.loadCSV("../playerData.csv");
    enemyList.loadCSV("../enemyData.csv");
    skillList.loadCSV("../skillData.csv");
    
    player = gameManager.settingPlayer(playerList, skillList);
    enemy = gameManager.settingEnemy(enemyList, skillList);
    gameManager.initiativeSetting(player, enemy);
    
    // 戦うキャラクターのデータを表示系にセット
    gameManager.SetCharacterData(&player, &enemy);

    while(1)
    {
        gameManager.printBattleWindow();
        // セットしたスキルを表示
        gameManager.printHaveSkill(player);
        cout << endl;
        battle.startBattle(player,enemy,skillList);
        battle.startBattle(enemy,player,skillList);
        
    }

}

