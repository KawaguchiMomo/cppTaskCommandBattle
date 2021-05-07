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

using namespace std;
// スキル所持最大数
const int MAXHAVESKILL = 4;

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

    // TODO:csvから読み込みできるように
    // csvLoader.loadCSV("playerData");
    playerList.loadCSV("../playerData.csv");
    enemyList.loadCSV("../enemyData.csv");
    skillList.loadCSV("skill.csv");

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
    player = playerList.getPlayer(0);
    for(auto& v : playerList.getPlayerList())
    {
        cout << v.getName() << endl;
    }

    // エネミーにスキルをセット
    enemy = enemyList.getEnemy(0);

    while(1)
    {
        // 画面表示（TODO:gameManagerクラスにうつす）
        // TODO:表示する字数が変わっても中央寄りにしたい
        cout << "---------------------------------------------------------------" << endl;
        cout << endl;
        gameManager.printHPBar(enemy.getHPPer());
        cout << endl;
        cout << "( ﾟДﾟ)" << endl;
        cout << endl;
        cout << endl;
        cout << "---------------------------------------------------------------" << endl;

        // セットしたスキルを表示
        for(int i = 1; i <= MAXHAVESKILL; i++){
            gameManager.printHaveSkill(i, (skillList.getListSkillName(player.useSkill(i))));
        }
        cout << endl;

        cout << "---------------------------------------------------------------" << endl;

        battle.startBattle(player,enemy,skillList);
        battle.startBattle(enemy,player,skillList);

    }

}

