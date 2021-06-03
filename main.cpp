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

    // 使用キャラクターの選択
    std::shared_ptr<Player> player = playerList.inputUsePlayer();
    player->settingPlayer(skillList);

    // 敵エネミーの選択
    std::shared_ptr<Enemy> enemy = enemyList.inputUseEnemy();
    enemy->settingEnemy(skillList);

    // 戦うキャラクターのデータを表示系にセット
    gameManager.SetCharacterData(player, enemy);
    // 最初の設定確認
    gameManager.initiativeSetting(player, enemy);
    
    while(1)
    {
        gameManager.printBattleWindow();
        // セットしたスキルを表示
        player->printHaveSkill();
        std::cout << std::endl;
        battleField.startBattle(player,enemy);
        battleField.startBattle(enemy,player);
        
    }

}

