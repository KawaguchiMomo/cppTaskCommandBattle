#include "csv_loader.h"
#include "character.h"
#include "player.h"
#include "player_list.h"
#include "enemy.h"
#include "enemy_list.h"
#include "game_manager.h"
#include "skill_list.h"
#include "skill.h"
#include "battle_field.h"
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
    gameManager.setRand();

    // データの読み込み
    playerList.loadCSV("../player_data.csv");
    enemyList.loadCSV("../enemy_data.csv");
    skillList.loadCSV("../skill_data.csv");

    // 使用キャラクターの選択
    std::shared_ptr<Player> player = playerList.inputUsePlayer();
    player->settingPlayer(skillList);

    // 敵エネミーの選択
    std::shared_ptr<Enemy> enemy = enemyList.inputUseEnemy();
    enemy->settingEnemy(skillList);

    // 戦うキャラクターのデータを表示系にセット
    gameManager.setCharacterData(player, enemy);
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

