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
// enum Type;

int main(){
    
    CsvLoader csvLoader;
    Player player;
    PlayerList playerList;
    Enemy enemy;
    EnemyList enemyList;
    GameManager &gameManager = GameManager::get_instance();
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
    player = gameManager.inputUsePlayer(playerList);
    player.setSkill(skillList.getListSkill(0));
    player.setSkill(gameManager.inputUseSkill(skillList));
    player.setSkill(gameManager.inputUseSkill(skillList));
    player.setSkill(gameManager.inputUseSkill(skillList));
    player.setSkill(gameManager.inputUseSkill(skillList));

    // エネミーにスキルをセット
    enemy = gameManager.inputUseEnemy(enemyList);
    enemy.setSkill(skillList.getListSkill(0));
    enemy.setSkill(skillList.getListSkill(enemy.getSkillNumber(1)));
    enemy.setSkill(skillList.getListSkill(enemy.getSkillNumber(2)));
    enemy.setSkill(skillList.getListSkill(enemy.getSkillNumber(3)));
    enemy.setSkill(skillList.getListSkill(enemy.getSkillNumber(4)));


    // スキルによるステータス補正（TODO:キャラクタークラスに移動）
    for(int i=1; i<=4 ; i++)
    {
        if(player.getSkill(i).getType() == TYPE::PASSIVE){ //error: ‘TYPE’ has not been declared
            player.revisionStatus(player.getSkill(i));
        }
    }
    
    // 戦闘準備確認(TODO:エンターキーだけで次に進めるようにし、ゲームマネージャークラスに移動)
    gameManager.printData(player);
    cout << "スキル: " << endl;
    gameManager.printHaveSkill(player, skillList);
    cout << endl;
    cout << endl;
    cout << "戦う相手:" << enemy.getName() << endl;

    int a;
    cout << "この設定で戦闘を開始します。";
    cin >> a;

    // 戦うキャラクターのデータを表示系にセット
    gameManager.SetCharacterData(&player, &enemy);

    while(1)
    {
        gameManager.printBattleWindow();
        // セットしたスキルを表示
        gameManager.printHaveSkill(player, skillList);
        cout << endl;
        gameManager.printLine();
        battle.startBattle(player,enemy,skillList);
        battle.startBattle(enemy,player,skillList);
        
    }

}

