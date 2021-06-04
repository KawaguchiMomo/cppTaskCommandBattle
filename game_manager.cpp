#include "csv_loader.h"
#include "character.h"
#include "player.h"
#include "player_list.h"
#include "enemy.h"
#include "enemy_list.h"
#include "game_manager.h"
#include "skill_list.h"
#include "skill.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <chrono>
#include <thread>
#include <memory>

using std::this_thread::sleep_for;

// 呼び出し
GameManager& GameManager::get_instance()
{
    static GameManager instance;
    return instance;
}

// 乱数のシード設定
void GameManager::setRand()
{
    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());
    randomEngine = engine;
}
// 乱数の作成
int GameManager::getRand(int min, int max)
{
    std::uniform_int_distribution<> dist(min, max);
    return dist(randomEngine);
}

// 入力とチェック
int GameManager::inputNumber(const std::string& message,int min, int max){
    while(1)
    {
        std::cout << message << ": ";
        // 入力させる
        int inputNumber;
        std::cin >> inputNumber;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(!inputNumber){
            std::cout << "入力が間違っています。" << std::endl;
            continue;
        }
        if(!(min <= inputNumber && inputNumber <= max)){
            std::cout << "入力が間違っています。" << std::endl;
            continue;
        }
        return inputNumber - 1;
    }
}

// 文章表示
void GameManager::printMessage(const std::string& message) const
{
    printBattleWindow();
    std::cout << message << std::endl;
    sleep_for(std::chrono::milliseconds(1000));
}

// 画面表示のためにデータを登録
void GameManager::setCharacterData(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy)
{
    usePlayer = player;
    useEnemy = enemy;
}
// 戦闘画面表示
void GameManager::printBattleWindow() const
{
    system("clear");
    printLine();
    std::cout << std::endl;
    std::cout << useEnemy->getName() << "のHP " << useEnemy->getImage() << std::endl;
    printHPBar(useEnemy->getHPPer());

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << usePlayer->getName() << "のHP "<< usePlayer->getImage() << std::endl;
    printHPBar(usePlayer->getHPPer());

    printLine();
}


// HPバー表示
void GameManager::printHPBar(double par) const
{
    std::string bar;
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

    std::cout << bar << std::endl;
}

// ライン表示
void GameManager::printLine() const
{
    std::cout << "---------------------------------------------------------------" << std::endl;

}



// 最初の設定確認
void GameManager::initiativeSetting(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy)
{
    system("clear");
    printLine();
    // 戦闘準備確認
    player->printData();
    std::cout << "スキル: " << std::endl;
    usePlayer->printHaveSkill();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "戦う相手:" << useEnemy->getName() << std::endl;

    std::cout << "この設定で戦闘を開始します。";
    getchar();
}

// ゲームクリア
void GameManager::printGameClear() const 
{
    std::string message = "ゲームクリア！";
    printMessage(message);
    printScore();
    printTalk();
    exit(0);
}
// ゲームオーバー
void GameManager::printGameOver() const 
{
    std::string message = "ゲームオーバー…";
    printMessage(message);
    printScore();
    printTalk();
    exit(0);
}
// スコア表示
void GameManager::printScore() const
{
    
    int enemyScore = (100 - useEnemy->getHPPer())/100 * useEnemy->getScore();
    std::cout << "　エネミースコア: " << enemyScore << std::endl;

    int playerScore = 1 + usePlayer->getHPPer()/100 * usePlayer->getScore();
    std::cout << "プレイヤースコア: ×" << playerScore << std::endl;
    
    int score = playerScore * enemyScore;
    std::cout << "　　　合計スコア: " << score << std::endl;
}

// 会話表示
void GameManager::printTalk() const
{
    std::cout << usePlayer->getImage() << "「" << usePlayer->getTalk() << "」" << std::endl;
    std::cout << useEnemy->getImage() << "「" << useEnemy->getTalk() << "」" << std::endl;
}