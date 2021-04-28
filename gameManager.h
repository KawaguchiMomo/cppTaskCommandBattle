#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "character.h"
#include <string>

using namespace std;
class Character;

class GameManager{
    private:
        string victoryMessage;
    public:
        // コンストラクタ
        GameManager();
        // デストラクタ
        virtual ~GameManager();
        // データを表示
        void printData(Character& character) const;
        // スキルデータを表示
        void printSkillData(string skillName,int attackRate, int biAttack) const;
        // 取得しているスキル表示
        void printHaveSkill(int i, string skillName) const;
        // HPバー表示
        void printHPBar(double par) const;

};

#endif