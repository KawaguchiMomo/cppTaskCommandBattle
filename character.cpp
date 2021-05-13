#include "character.h"
#include "gameManager.h"
#include <vector>

// コンストラクタ
Character::Character()
{
    isDead = false;
    haveSkillNumber.push_back(0);
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

// 見た目セット
void Character::setImage(const string& a)
{
    charaImage = a;
}
// 見た目取得
const string& Character::getImage() const
{
    return charaImage;
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
void Character::setAttack(double a)
{
    attack = a;
}
// 攻撃力取得
double Character::getAttack() const
{
    return attack;
}
// 防御力セット
void Character::setDefense(double a)
{
    defense = a;
}
// 防御力取得
double Character::getDefense() const
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
// セリフセット
void Character::setTalk(const string& a)
{
    talk = a;
}
// セリフ取得
const string& Character::getTalk() const
{
    return talk;
}
// スコアセット
void Character::setScore(int a)
{
    score = a;
}
// スコア取得
int Character::getScore() const
{
    return score;
}

// スキル補正
void Character::revisionStatus(const Skill& skill)
{
    setMaxHp(maxHp*skill.getHPRate());
    setHp(hp*skill.getHPRate());
    setAttack(attack*skill.getAttackRate());
    setDefense(defense*skill.getDefenseRate());
    setLuck(luck*skill.getLuckRate());
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
// スキル番号をセット
void Character::setSkillNumber(int skillNumber)
{
    haveSkillNumber.push_back(skillNumber);
}
// 持っているスキル番号を取得
int Character::getSkillNumber(int skillNumber) const
{
    return haveSkillNumber[skillNumber];
}
// 持っているスキルセットを取得
const vector<Skill>& Character::getSkillList() const
{
    return haveSkill;
}
// スキルをセット
void Character::setSkill(const Skill& skill)
{
    haveSkill.push_back(skill);
}
// 持っているスキルを取得
const Skill& Character::getSkill(int skillNumber) const
{
    return haveSkill[skillNumber];
}

// スキルを選択
int Character::inputSkill(){
    return 1;
}
// スキル回数を減少
void Character::UsedCanUseNumber(int skillNumber)
{
    haveSkill[skillNumber].UsedCanUseNumber();
}

// ダメージを受ける
void Character::receivedDamage(int damage)
{
    hp-=damage;
}
// 死亡判定
void Character::judgeDead()
{
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
