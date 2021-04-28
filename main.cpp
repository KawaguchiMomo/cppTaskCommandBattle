#include "character.h"
#include "player.h"
#include "enemy.h"
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
    
    Player player;
    Enemy enemy;
    GameManager gameManager;
    SkillList skillList;
    Skill skill;
    Battle battle;

    // TODO:csvから読み込みできるように
    player.loadCSV("ああああ.csv");
    enemy.loadCSV("エネミー.csv");
    skillList.loadCSV("skill.csv");

    // 読み込んだ情報を表示(テスト用)
    gameManager.printData(player);
    
    // 読み込んだスキル表示（テスト用）
    // for (int i = 0;i<5;i++)
    // {
    //     gameManager.printSkillData(skill.getListSkillName(i), skill.getListAttackRate(i), skill.getListBiAttack(i));
    // }

    // プレイヤーにスキルをセット
    // ex) 自分でスキルを選択する式の場合はここの処理を手動入力できるようにする
    player.setSkill(0); // 1から入力してもらうためにダミー
    player.setSkill(1);
    player.setSkill(2);
    player.setSkill(3);
    player.setSkill(4);

    // エネミーにスキルをセット
    // csvから読み込みできるようにする
    enemy.setSkill(0); // 1から入力してもらうためにダミー
    enemy.setSkill(1);
    enemy.setSkill(2);
    enemy.setSkill(3);
    enemy.setSkill(4);

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
            gameManager.printHaveSkill(i, skillList.getListSkillName(i));
        }
        cout << endl;

        cout << "---------------------------------------------------------------" << endl;

        battle.startBattle(player,enemy,skillList);
        battle.startBattle(enemy,player,skillList);




        // ここで勝敗判定すると引き分けもあり得る仕様になる
        // 倒した時点で終わりにしたい場合ロジック修正
        if(enemy.getIsDead()){
            cout << "ゲームクリア！" << endl;
            exit(0);
        }
        if(player.getIsDead()){
            cout << "ゲームオーバー…" << endl;
            exit(0);
        }
    }

}

