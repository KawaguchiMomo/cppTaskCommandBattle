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
#include <memory>

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
    system("clear");
    printLine();
    int playerListSize = (int)playerList.getPlayerList().size();
    for(int i = 1 ; i < playerListSize ; i++)
    {
        cout << i << ": " << playerList.getPlayerList()[i].getName() << " ";
        if(i % 4 == 0) { cout << endl; }
    }
    cout << endl; 

    int playerNumber = inputNumber("プレイヤーを選んでください", 1, playerListSize);
    system("clear");
    return playerList.getPlayer(playerNumber);
}

// 取得スキルを選択
Skill GameManager::inputUseSkill(const SkillList& skillList)
{
    printLine();
    int skillListSize = (int)skillList.getSkillList().size();
    // スキル一覧を表示
    for(int i = 1 ; i < skillListSize ; i++)
    {
        const std::shared_ptr< SkillSetting > skillSetting = skillList.getSkillList()[i];
        string message;
        message = to_string(i) + ": " + skillSetting->getSkillName();
        if(skillSetting->getType() == Type::ACTIVE){
            message = message + "/アクティブ" + ":使用回数 " + to_string(skillSetting->getCanUseNumber()) + "/";
        }else if(skillSetting->getType() == Type::PASSIVE){
            message = message + "/パッシブ" + "/";
        }
        message = message + skillSetting->getDesc();
        cout << message << endl;
    }
    cout << endl; 
    int skillNumber = inputNumber("スキルを選んでください", 1, skillListSize);
    system("clear");

    // キャラクター固有のスキルを作成
    Skill skill(skillList.getListSkill(skillNumber), skillList.getListSkill(skillNumber)->getCanUseNumber());
     
    return skill;
}

// エネミーを選択
const Enemy& GameManager::inputUseEnemy(const EnemyList& enemyList)
{
    system("clear");
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
    cin.clear();
    printBattleWindow();
    printHaveSkill(*usePlayer);
    int skillNumber = inputNumber("コマンドを選んでください", 1, MAXHAVESKILL+1);
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
    cout << "名前: " << character.getName() << endl;
    cout << "HP: " << character.getHp() << endl;
    cout << "攻撃力: " << character.getAttack() << endl;
    cout << "防御力: " << character.getDefense() << endl;
    cout << "運: " << character.getLuck() << endl;

}
void GameManager::printSkillData(const string& skillName,int attackRate, int biAttack) const
{
    cout << "名前: " << skillName << endl;
    cout << "攻撃倍率: " << attackRate << endl;
    cout << "攻撃回数: " << biAttack << endl;
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


// キャラクターの取得しているスキル表示
void GameManager::printHaveSkill(const Player& player) const
{
    int skillListSize = player.getSkillList().size();
    for(int i = 1; i < skillListSize; i++){
        const Skill& skill = player.getSkill(i);
        std::shared_ptr<const SkillSetting> skillSetting = std::shared_ptr<const SkillSetting>(skill.getSkillSetting());

        const string& skillName = skillSetting->getSkillName();
        int skillCanUseNumber = skill.getCanUseNumber();

        // 残り使用回数を表示
        string canUseNumber;
        if(skillCanUseNumber == -1){
            canUseNumber = "";
        }else{
            canUseNumber = "(" + to_string(skillCanUseNumber) + ")";
        }
        cout << setw(2) << i << " :" << skillName << canUseNumber << "  ";
    }
    cout << endl;
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

// プレイヤーの設定
Player GameManager::settingPlayer(const PlayerList& playerList, const SkillList& skillList)
{
    Player player;

    // プレイヤーにスキルをセット
    player = inputUsePlayer(playerList);
    // ダミースキルやたたかうスキルはどのキャラクターがもっても同じだが、
    // いちいちSkillクラスを作成しなければならないので
    // どこかで共通で呼び出せるようにしておく…？
    // std::shared_ptr<const SkillSetting> skill = std::make_shared<SkillSetting>();
    Skill dummySkill(skillList.getListSkill(0), skillList.getListSkill(0)->getCanUseNumber());
    player.setSkill(dummySkill);

    Skill tatakauSkill(skillList.getListSkill(1), skillList.getListSkill(1)->getCanUseNumber());
    player.setSkill(tatakauSkill);

    printHaveSkill(player);
    player.setSkill(inputUseSkill(skillList));
    printLine();

    printHaveSkill(player);
    player.setSkill(inputUseSkill(skillList));
    printLine();

    printHaveSkill(player);
    player.setSkill(inputUseSkill(skillList));
    printLine();
    
    // スキルによるステータス補正
    for(int i=1; i<=4 ; i++)
    {
        if(player.getSkill(i).getSkillSetting()->getType() == Type::PASSIVE){
            player.revisionStatus(player.getSkill(i));
        }
    }
    
    return player;
}

// エネミーの設定
Enemy GameManager::settingEnemy(const EnemyList& enemyList, const SkillList& skillList)
{
    Enemy enemy;

    // エネミーにスキルをセット
    enemy = inputUseEnemy(enemyList);
    // settingPlayerと同じ問題
    Skill dummySkill(skillList.getListSkill(0), skillList.getListSkill(0)->getCanUseNumber());
    Skill tatakauSkill(skillList.getListSkill(1), skillList.getListSkill(1)->getCanUseNumber());
    Skill skill1(skillList.getListSkill(enemy.getSkillNumber(2)), skillList.getListSkill(2)->getCanUseNumber());
    Skill skill2(skillList.getListSkill(enemy.getSkillNumber(3)), skillList.getListSkill(3)->getCanUseNumber());
    Skill skill3(skillList.getListSkill(enemy.getSkillNumber(4)), skillList.getListSkill(4)->getCanUseNumber());

    enemy.setSkill(dummySkill);
    enemy.setSkill(tatakauSkill);
    enemy.setSkill(skill1);
    enemy.setSkill(skill2);
    enemy.setSkill(skill3);

    return enemy;
}

// 最初の設定
void GameManager::initiativeSetting(const Player& player, const Enemy& enemy)
{
    system("clear");
    printLine();
    // 戦闘準備確認
    printData(player);
    cout << "スキル: " << endl;
    printHaveSkill(player);
    cout << endl;
    cout << endl;
    cout << "戦う相手:" << enemy.getName() << endl;

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