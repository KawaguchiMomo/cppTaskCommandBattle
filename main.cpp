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
    // スキルデータの読み込み
    SkillList skillList;
    skillList.loadCSV("../skill_data.csv");

    // 使用キャラクターの選択
    PlayerList playerList;
    playerList.loadCSV("../player_data.csv");
    std::shared_ptr<Player> player = playerList.inputUsePlayer();
    player->settingPlayer(skillList);

    // 敵エネミーの選択
    EnemyList enemyList;
    enemyList.loadCSV("../enemy_data.csv");
    std::shared_ptr<Enemy> enemy = enemyList.inputUseEnemy();
    enemy->settingEnemy(skillList);

    // 乱数のシード設定
    GameManager &gameManager = GameManager::get_instance();
    gameManager.setRand();
    // 戦うキャラクターのデータを表示系にセット
    gameManager.setCharacterData(player, enemy);
    // 最初の設定確認
    gameManager.initiativeSetting(player, enemy);
    
    Battle battleField;
    while(1)
    {
        // 戦闘画面の表示
        gameManager.printBattleWindow();
        // セットしたスキルを表示
        player->printHaveSkill();

        // 戦闘処理
        battleField.startBattle(player,enemy);
        battleField.startBattle(enemy,player);
        
    }

}

