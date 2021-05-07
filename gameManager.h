#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "character.h"
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
    public:
        // コンストラクタ
        GameManager();
        // デストラクタ
        virtual ~GameManager();
        // 乱数のシード設定
        void SetRand();
        // プレイヤーを選択
        const Player& inputUsePlayer(const PlayerList& playerList);
        //
        int inputNumber(const string& message,int min, int max);
        // エネミーを選択
        const Enemy& inputUseEnemy(const EnemyList& enemyList);
        // データを表示
        void printData(const Character& character) const;
        // スキルデータを表示
        void printSkillData(const string& skillName,int attackRate, int biAttack) const;
        // 戦闘画面表示
        void printBattleWindow(const Player& player, const Enemy& enemy) const;
        // 取得しているスキル表示
        void printHaveSkill(const Player& player, const SkillList& skillList) const;
        // HPバー表示
        void printHPBar(double par) const;
        // ライン表示
        void printLine() const;
        // ゲームクリア
        void printGameClear() const;
        // ゲームオーバー
        void printGameOver() const;
};

#endif