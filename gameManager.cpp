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
#include <cstdlib>
#include <iomanip>

using namespace std;
// スキル所持最大数
const int MAXHAVESKILL = 4;

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
// プレイヤーを選択
const Player& GameManager::inputUsePlayer(const PlayerList& playerList)
{
    printLine();
    int playerListSize = (int)playerList.getPlayerList().size();
    for(int i = 1 ; i < playerListSize ; i++)
    {
        cout << i << ": " << playerList.getPlayerList()[i].getName() << " ";
        if(i % 4 == 0) { cout << endl; }
    }
    cout << endl; 

    int playerNumber = inputNumber("プレイヤーを選んでください", 1, playerListSize);
    printLine();
    return playerList.getPlayer(playerNumber);
}

// エネミーを選択
const Enemy& GameManager::inputUseEnemy(const EnemyList& enemyList)
{
    printLine();
    int enemyListSize = (int)enemyList.getEnemyList().size();
    for(int i = 1 ; i < enemyListSize ; i++)
    {
        cout << i << ": " << enemyList.getEnemyList()[i].getName() << " ";
        if(i % 4 == 0) { cout << endl; }
    }
    cout << endl; 

    int enemyNumber = inputNumber("エネミーを選んでください", 1, enemyListSize);
    printLine();
    return enemyList.getEnemy(enemyNumber);
}

// 入力とチェック
int GameManager::inputNumber(const string& message,int min, int max){
    int inputNumber;
    while(1)
    {
        cout << message << ": ";
        // 入力させる
        cin >> inputNumber;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(!inputNumber){
            cout << "入力が間違っています。" << endl;
            continue;
        }
        if(!(min <= inputNumber && inputNumber < max)){
            cout << "入力が間違っています。" << endl;
            continue;
        }
        return inputNumber;
    }
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
// 戦闘画面表示
void GameManager::printBattleWindow(const Player& player, const Enemy& enemy) const
{
    printLine();
    cout << endl;
    cout << enemy.getName() << "のHP " << enemy.getImage() << endl;
    printHPBar(enemy.getHPPer());

    cout << endl;
    cout << endl;
    cout << player.getName() << "のHP "<< player.getImage() << endl;
    printHPBar(player.getHPPer());

    printLine();
}


// 取得しているスキル表示
void GameManager::printHaveSkill(const Player& player, const SkillList& skillList) const
{
    for(int i = 1; i <= MAXHAVESKILL; i++){
        Skill skill = skillList.getListSkill(player.useSkill(i));
        string skillName = skill.getSkillName();
        cout << setw(2) << i << " :" << skillName << "  ";
    }

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

// ライン表示
void GameManager::printLine() const
{
    cout << "---------------------------------------------------------------" << endl;

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
