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
    
    CsvLoader csvLoader;
    Player player;
    PlayerList playerList;
    Enemy enemy;
    EnemyList enemyList;
    GameManager gameManager;
    SkillList skillList;
    Skill skill;
    Battle battle;

    // 乱数のシード設定
    gameManager.SetRand();

    playerList.loadCSV("../playerData.csv");
    enemyList.loadCSV("../enemyData.csv");
    skillList.loadCSV("../skillData.csv");

    // 読み込んだ情報を表示(テスト用)
    gameManager.printData(playerList.getPlayer(0));
    gameManager.printData(enemyList.getEnemy(0));
    
    // 読み込んだスキル表示（テスト用）
    // for (int i = 0;i<5;i++)
    // {
    //     gameManager.printSkillData(skill.getListSkillName(i), skill.getListAttackRate(i), skill.getListBiAttack(i));
    // }

    // プレイヤーにスキルをセット
    // ex) 自分でスキルを選択する式の場合はここの処理を手動入力できるようにする
    player = gameManager.inputUsePlayer(playerList);

    // エネミーにスキルをセット
    enemy = gameManager.inputUseEnemy(enemyList);

    while(1)
    {
        gameManager.printBattleWindow(player, enemy);
        // セットしたスキルを表示
        gameManager.printHaveSkill(player, skillList);
        cout << endl;

        gameManager.printLine();
        battle.startBattle(player,enemy,skillList);
        battle.startBattle(enemy,player,skillList);

    }

}

