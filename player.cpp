#include "player.h"
#include <limits>
#include <iostream>

// コンストラクタ
Player::Player()
{

}
// デストラクタ
Player::~Player(){}

// スキルを選択
int Player::inputSkill()
{
    int skillNumber;
    // 整数1~9以外はエラー、すでに書き込んである箇所はエラー
    // while(1) {
    //     // 入力させる
    //     cout << "スキルを入力してください。(1~4)";
    //     cin >> skillNumber;
    //     cin.clear();
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     if(!skillNumber){
    //         cout << "入力が間違っています。" << endl;
    //         continue;
    //     }
    //     if(!(1 <= skillNumber && skillNumber <= 4)){
    //         cout << "入力が間違っています。" << endl;
    //         continue;
    //     }
    //     break;
    // }
        cout << "スキルを入力してください。(1~4)";
        cin >> skillNumber;
    return skillNumber;
}

