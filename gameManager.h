#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "character.h"
#include "player.h"
#include "enemy.h"
#include <string>

using namespace std;
class Character;
class Player;
class PlayerList;
class Enemy;
class EnemyList;
class SkillList;
class GameManager
{
    private:
        string victoryMessage;
        Player* usePlayer;
        Enemy* useEnemy;
        // コンストラクタ
        GameManager();
        // デストラクタ
        virtual ~GameManager();
        GameManager(const GameManager&);
        GameManager& operator = (const GameManager&);
    public:
        // 呼び出し
        static GameManager& get_instance();
        // 乱数のシード設定
        void SetRand();
        // 乱数の作成
        int GetRand(int min, int max);
        // 取得スキルを選択
        Skill inputUseSkill(const SkillList& skillList);
        // プレイヤーを選択
        const Player& inputUsePlayer(const PlayerList& playerList);
        //
        int inputNumber(const string& message,int min, int max);
        // エネミーを選択
        const Enemy& inputUseEnemy(const EnemyList& enemyList);
        // コマンドを選択
        int inputSkill();
        // データを表示
        void printData(const Character& character) const;
        // スキルデータを表示
        void printSkillData(const string& skillName,int attackRate, int biAttack) const;
        // 画面表示のためにデータを登録
        void SetCharacterData(Player* player, Enemy* enemy);
        // 文章表示
        void printMessage(const string& message) const;
        // 戦闘画面表示
        void printBattleWindow() const;
        // 取得しているスキル表示
        void printHaveSkill(const Player& player) const;
        // HPバー表示
        void printHPBar(double par) const;
        // ライン表示
        void printLine() const;
        // プレイヤーの設定
        Player settingPlayer(const PlayerList& playerList, const SkillList& skillList);
        // エネミーの設定
        Enemy settingEnemy(const EnemyList& enemyList, const SkillList& skillList);
        // 最初の設定
        void initiativeSetting(const Player& player, const Enemy& enemy);
        // ゲームクリア
        void printGameClear() const;
        // ゲームオーバー
        void printGameOver() const;
        // スコア表示
        void printScore() const;
        // セリフ表示
        void printTalk() const;
};

#endif