#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "character.h"
#include "player.h"
#include "enemy.h"
#include <string>
#include <random>

class Character;
class Player;
class PlayerList;
class Enemy;
class EnemyList;
class SkillList;
class GameManager
{
    private:
        std::string victoryMessage;
        std::shared_ptr<Player> usePlayer;
        std::shared_ptr<Enemy> useEnemy;

        std::default_random_engine randomEngine;

        // スコア表示
        void printScore() const;
        // セリフ表示
        void printTalk() const;
    public:
        // コンストラクタ
        GameManager() = default;
        // デストラクタ
        virtual ~GameManager() = default;
        // コピーコンストラクタ
        GameManager(const GameManager&) = delete;
        // 代入演算子
        GameManager& operator=(const GameManager&) = delete;
        // 呼び出し
        static GameManager& get_instance();
        // 乱数のシード設定
        void setRand();
        // 乱数の作成
        int getRand(int min, int max);
        // 入力とチェック
        int inputNumber(const std::string& message,int min, int max);
        // コマンドを選択
        int inputSkill();
        // 画面表示のためにデータを登録
        void setCharacterData(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy);
        // 文章表示
        void printMessage(const std::string& message) const;
        // 戦闘画面表示
        void printBattleWindow() const;
        // HPバー表示
        void printHPBar(double par) const;
        // ライン表示
        void printLine() const;
        // 最初の設定確認
        void initiativeSetting(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy);
        // ゲームクリア
        void printGameClear() const;
        // ゲームオーバー
        void printGameOver() const;
};

#endif