#include "player.h"
#include "gameManager.h"
#include <limits>
#include <iostream>

// コンストラクタ
Player::Player(){}
// デストラクタ
Player::~Player(){}

// スキルを選択
int Player::inputSkill()
{
    GameManager &gameManager = GameManager::get_instance();
    int skillNumber = gameManager.inputSkill();
    return skillNumber;
}

// 死亡
void Player::onDead() 
{
    isDead = true;
    GameManager &gameManager = GameManager::get_instance();
    gameManager.printGameOver();
}
