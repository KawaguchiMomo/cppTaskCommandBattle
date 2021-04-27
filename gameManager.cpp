#include <iostream>
#include <stdlib.h>
#include "gameManager.h"
#include "character.h"



// コンストラクタ
GameManager::GameManager(){}
// デストラクタ
GameManager::~GameManager(){}
// データを表示
void GameManager::printData(Character& character) const
{
    cout << "名前" << character.getName() << endl;
    cout << "HP" << character.getHp() << endl;
    cout << "攻撃力" << character.getAttack() << endl;
    cout << "防御力" << character.getDefense() << endl;
    cout << "運" << character.getLuck() << endl;

}

