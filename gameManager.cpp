#include "gameManager.h"
#include "character.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
// コンストラクタ
GameManager::GameManager(){}
// デストラクタ
GameManager::~GameManager(){}
// 乱数のシード設定
void GameManager::SetRand()
{
    // 乱数の作成
    struct timespec ts;
    // 現在時刻を取得する
    timespec_get(&ts, TIME_UTC);
    // 乱数のシードを設定する
    srandom(ts.tv_nsec ^ ts.tv_sec);

}
// データを表示
void GameManager::printData(const Character& character) const
{
    cout << "名前" << character.getName() << endl;
    cout << "HP" << character.getHp() << endl;
    cout << "攻撃力" << character.getAttack() << endl;
    cout << "防御力" << character.getDefense() << endl;
    cout << "運" << character.getLuck() << endl;

}
void GameManager::printSkillData(const string& skillName,int attackRate, int biAttack) const
{
    cout << "名前" << skillName << endl;
    cout << "攻撃倍率" << attackRate << endl;
    cout << "攻撃回数" << biAttack << endl;
}

// 取得しているスキル表示
void GameManager::printHaveSkill(int i, const string& skillName) const
{
    cout << setw(2) << i << " :" << skillName << "  ";
}

// HPバー表示
void GameManager::printHPBar(double par) const
{
    string bar;
    bar += "[";
    for(int i = 0 ; i < 10; i++)
    {
        if(i <= par / 10){
            bar += "■";
        }else{
            bar += "□";
        }
    }
    bar += "]";

    cout << setw(40) << bar << endl;
}

// ゲームクリア
void GameManager::printGameClear() const 
{
    cout << "ゲームクリア！" << endl;
    exit(0);
}
// ゲームオーバー
void GameManager::printGameOver() const 
{
    cout << "ゲームオーバー…" << endl;
    exit(0);
}
