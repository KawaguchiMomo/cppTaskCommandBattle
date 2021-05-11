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
#include <random>
#include <chrono>
#include <thread>

using std::this_thread::sleep_for;

using namespace std;
// スキル所持最大数
const int MAXHAVESKILL = 4;

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

// 取得スキルを選択
Skill GameManager::inputUseSkill(const SkillList& skillList)
{
    int skillListSize = (int)skillList.getSkillList().size();
    for(int i = 1 ; i < skillListSize ; i++)
    {
        cout << i << ": " << skillList.getSkillList()[i].getSkillName() << " ";
        if(i % 4 == 0) { cout << endl; }
    }
    cout << endl; 
    int skillNumber = inputNumber("スキルを選んでください", 1, skillListSize);
    printLine();
    cout << skillList.getListSkill(skillNumber).getSkillName() << endl;
    return skillList.getListSkill(skillNumber);
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
// コマンドを選択
int GameManager::inputSkill()
{
    printLine();

    int skillNumber = inputNumber("コマンドを選んでください", 1, MAXHAVESKILL+1);
    printLine();
    return skillNumber;
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

// 文章表示
void GameManager::printMessage(const string& message) const
{
    printBattleWindow();
    cout << message << endl;
    sleep_for(std::chrono::milliseconds(1000));
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

// 画面表示のためにデータを登録
void GameManager::SetCharacterData(Player* player, Enemy* enemy)
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


// 取得しているスキル表示
void GameManager::printHaveSkill(const Player& player, const SkillList& skillList) const
{
    for(int i = 1; i <= MAXHAVESKILL; i++){
        Skill skill = player.getSkill(i);
        string skillName = skill.getSkillName();
        int skillCanUseNumber = skill.getCanUseNumber();

        string canUseNumber;
        if(skillCanUseNumber == -1){
            canUseNumber = "";
        }else{
            canUseNumber = "(" + to_string(skillCanUseNumber) + ")";
        }
        cout << setw(2) << i << " :" << skillName << canUseNumber << "  ";
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
    string message = "ゲームクリア！";
    printMessage(message);
    exit(0);
}
// ゲームオーバー
void GameManager::printGameOver() const 
{
    string message = "ゲームオーバー…";
    printMessage(message);
    exit(0);
}
