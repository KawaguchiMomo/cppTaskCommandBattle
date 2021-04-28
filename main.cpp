#include "character.h"
#include "player.h"
#include "enemy.h"
#include "gameManager.h"
#include "skill.h"
#include <iostream>
#include <iomanip>
using namespace std;
// スキル所持最大数
const int MAXHAVESkill = 4;


int main(){
    
    Player player;
    Enemy enemy;
    GameManager gameManager;
    Skill skill;

    // TODO:csvから読み込みできるように
    player.loadCSV("ああああ.csv");
    enemy.loadCSV("エネミー.csv");
    skill.loadCSV("skill.csv");

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
    for(int i = 1; i <= MAXHAVESkill; i++){
        gameManager.printHaveSkill(i, skill.getListSkillName(i));
    }
    cout << endl;

    cout << "---------------------------------------------------------------" << endl;

    //スキル入力
    int useSkillNumber = player.useSkill(player.inputSkill());

    //TODO: 攻撃の処理が長いのでアタッククラスなどを作成するか？
    //スキル発動
    cout << player.getName() << "の" << skill.getListSkillName(useSkillNumber) << "！" << endl;
    int attack = player.getAttack()*skill.getListAttackRate(useSkillNumber);
    int defense = enemy.getDefense();
    for(int i = 0 ; i <skill.getListBiAttack(useSkillNumber);i++)
    {
        int damage = (attack - defense) < 0 ? 0 : (attack - defense);
        enemy.receivedDamage(damage);
        cout << enemy.getName() << "に" << damage << "のダメージ！" << endl;
        // HPバー表示
        gameManager.printHPBar(enemy.getHPPer());

    }
}