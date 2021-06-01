#include "csvLoader.h"
#include "character.h"
#include "player.h"
#include "playerList.h"
#include "enemy.h"
#include "enemyList.h"
#include "gameManager.h"
#include "skillList.h"
#include "skill.h"
#include "battleField.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <chrono>
#include <thread>
#include <memory>

using std::this_thread::sleep_for;

using namespace std;

// 呼び出し
GameManager& GameManager::get_instance()
{
    static GameManager instance;
    return instance;
}

// コンストラクタ
GameManager::GameManager(){}
// デストラクタ
GameManager::~GameManager(){}
// 乱数のシード設定
void GameManager::SetRand()
{
}
// 乱数の作成
int GameManager::GetRand(int min, int max)
{
    random_device seed_gen;
    default_random_engine engine(seed_gen());
    uniform_int_distribution<> dist(min, max);
    return dist(engine);
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
        if(!(min <= inputNumber && inputNumber <= max)){
            cout << "入力が間違っています。" << endl;
            continue;
        }
        return inputNumber - 1;
    }
}

// 文章表示
void GameManager::printMessage(const string& message) const
{
    printBattleWindow();
    cout << message << endl;
    sleep_for(std::chrono::milliseconds(1000));
}

// 画面表示のためにデータを登録
void GameManager::SetCharacterData(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy)
{
    usePlayer = player;
    useEnemy = enemy;
}
// 戦闘画面表示
void GameManager::printBattleWindow() const
{
    system("clear");
    printLine();
    cout << endl;
    cout << useEnemy->getName() << "のHP " << useEnemy->getImage() << endl;
    printHPBar(useEnemy->getHPPer());

    cout << endl;
    cout << endl;
    cout << usePlayer->getName() << "のHP "<< usePlayer->getImage() << endl;
    printHPBar(usePlayer->getHPPer());

    printLine();
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



// 最初の設定確認
void GameManager::initiativeSetting(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy)
{
    system("clear");
    printLine();
    // 戦闘準備確認
    player->printData();
    cout << "スキル: " << endl;
    usePlayer->printHaveSkill();
    cout << endl;
    cout << endl;
    cout << "戦う相手:" << useEnemy->getName() << endl;

    cout << "この設定で戦闘を開始します。";
    getchar();
}

// ゲームクリア
void GameManager::printGameClear() const 
{
    string message = "ゲームクリア！";
    printMessage(message);
    printScore();
    printTalk();
    exit(0);
}
// ゲームオーバー
void GameManager::printGameOver() const 
{
    string message = "ゲームオーバー…";
    printMessage(message);
    printScore();
    printTalk();
    exit(0);
}
// スコア表示
void GameManager::printScore() const
{
    int playerScore = 1 + usePlayer->getHPPer()/100 * usePlayer->getScore();
    int enemyScore = (100 - useEnemy->getHPPer())/100 * useEnemy->getScore();
    int score = playerScore * enemyScore;
    
    cout << "　エネミースコア: " << enemyScore << endl;
    cout << "プレイヤースコア: ×" << playerScore << endl;
    cout << "　　　合計スコア: " << score << endl;
}

// 会話表示
void GameManager::printTalk() const
{
    cout << usePlayer->getImage() << "「" << usePlayer->getTalk() << "」" << endl;
    cout << useEnemy->getImage() << "「" << useEnemy->getTalk() << "」" << endl;
}