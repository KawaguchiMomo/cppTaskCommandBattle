#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "character.h"
#include <string>

using namespace std;
class Character;

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
        // データを表示
        void printData(const Character& character) const;
        // スキルデータを表示
        void printSkillData(const string& skillName,int attackRate, int biAttack) const;
        // 取得しているスキル表示
        void printHaveSkill(int i, const string& skillName) const;
        // HPバー表示
        void printHPBar(double par) const;
        // ゲームクリア
        void printGameClear() const;
        // ゲームオーバー
        void printGameOver() const;
};

#endif