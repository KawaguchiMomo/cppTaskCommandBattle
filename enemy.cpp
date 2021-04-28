#include "enemy.h"
#include <limits>
#include <iostream>
#include <time.h>
#include <cstdlib>
// コンストラクタ
Enemy::Enemy()
{

}
// デストラクタ
Enemy::~Enemy(){}

// スキルを選択
int Enemy::inputSkill()
{
    int skillNumber = 1;
    // 整数1~9以外はエラー、すでに書き込んである箇所はエラー
    while(1) {
        // 乱数作成
        struct timespec ts;
        // 現在時刻を取得する
        timespec_get(&ts, TIME_UTC);
        // 乱数のシードを設定する
        srandom(ts.tv_nsec ^ ts.tv_sec);
        // 乱数を生成する 
        skillNumber = 1 + random() % 4;

        // 発動条件を満たしていない場合再抽選
        // if(!skillNumber){
        //     continue;
        // }
        break;
    }
    return skillNumber;
}

