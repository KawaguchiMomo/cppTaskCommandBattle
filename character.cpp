#include "character.h"
#include "gameManager.h"
#include <iostream>
#include <vector>

// コンストラクタ
Character::Character()
{
    isDead = false;
    haveSkill.push_back(0);
}
// デストラクタ
Character::~Character(){}

// 名前セット
void Character::setName(const string& a)
{
    charaName = a;
}
// 名前取得
const string& Character::getName() const
{
    return charaName;
}

// 最大HPセット
void Character::setMaxHp(int a)
{
    maxHp = a;
}

// 最大HP取得
int Character::getMaxHp() const
{
    return maxHp;
}
// HPセット
void Character::setHp(int a)
{
    hp = a;
}

// HP取得
int Character::getHp() const
{
    return hp;
}
// 攻撃力セット
void Character::setAttack(int a)
{
    attack = a;
}
// 攻撃力取得
int Character::getAttack() const
{
    return attack;
}
// 防御力セット
void Character::setDefense(int a)
{
    defense = a;
}
// 防御力取得
int Character::getDefense() const
{
    return defense;
}
// 運セット
void Character::setLuck(int a)
{
    luck = a;
}
// 運取得
int Character::getLuck() const
{
    return luck;
}


// 読み込んだデータをセット
void Character::setData(const string& charaName,int hp, int attack, int defense, int luck){
    setName(charaName);
    setMaxHp(hp);
    setHp(hp);
    setAttack(attack);
    setDefense(defense);
    setLuck(luck);
}
// スキルをセット
void Character::setSkill(int skillNumber)
{
    haveSkill.push_back(skillNumber);
}
// スキルを選択
int Character::inputSkill(){
    return 1;
}
// 持っているスキル番号を取得
int Character::useSkill(int skillNumber)
{
    return haveSkill[skillNumber];
}
// ダメージを受ける
void Character::receivedDamage(int damage)
{
    hp-=damage;
    if(hp <= 0){
        onDead();
    }
}
// 現在HP/最大HPの割合を算出
double Character::getHPPer() const
{
    double HPPer;
    HPPer = static_cast<double>(getHp() / static_cast<double>(getMaxHp())) *100;
    return HPPer;
}

// // 死亡
// void Character::onDead()
// {
//     isDead = true;
// }
