#include "character.h"
#include "player.h"
#include "gameManager.h"
#include <iostream>

int main(){
    
    Player player;
    GameManager gameManager;

    // player.setName("ああああ");
    // player.setHp(10);
    // player.setAttack(10);
    // player.setDefense(10);
    // player.setLuck(10);
    player.loadDataCSV();

    // 以下は実装できてるかの確認
    // 情報出力
    // cout << "名前" << player.getName() << endl;
    // cout << "HP" << player.getHp() << endl;
    // cout << "攻撃力" << player.getAttack() << endl;
    // cout << "防御力" << player.getDefense() << endl;
    // cout << "運" << player.getLuck() << endl;
    gameManager.printData(player);


    // 攻撃
    cout << player.getHp() << endl;
    player.receivedDamage(2);
    cout << player.getHp() << endl;

    //スキル入力
    int i =player.inputSkill();
}