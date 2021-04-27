#include "character.h"
#include <iostream>
// コンストラクタ
Character::Character()
{
    hp = 10;
}
// デストラクタ
Character::~Character(){}

// 名前セット
void Character::setName(string a)
{
    charaName = a;
}
// 名前取得
string Character::getName()
{
    return charaName;
}

// HPセット
void Character::setHp(int a)
{
    hp = a;
}

// HP取得
int Character::getHp()
{
    return hp;
}
// 攻撃力セット
void Character::setAttack(int a)
{
    attack = a;
}
// 攻撃力取得
int Character::getAttack()
{
    return attack;
}
// 防御力セット
void Character::setDefense(int a)
{
    defense = a;
}
// 防御力取得
int Character::getDefense()
{
    return defense;
}
// 運セット
void Character::setLuck(int a)
{
    luck = a;
}
// 運取得
int Character::getLuck()
{
    return luck;
}

// csvからデータを読み込む
void Character::loadDataCSV(){
    setName("ああああ");
    setHp(10);
    setAttack(10);
    setDefense(10);
    setLuck(10);
}
// スキルを選択
int Character::inputSkill(){}
// スキルを使用
void Character::useSkill(int skillNumber)
{
    haveSkill[skillNumber];
}
// ダメージを受ける
void Character::receivedDamage(int damage)
{
    hp-=damage;
}
