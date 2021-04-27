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

};

#endif