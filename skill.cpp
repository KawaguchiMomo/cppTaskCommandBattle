#include "skill.h"
#include <vector>
// コンストラクタ
Skill::Skill()
{
    //string skillName,int attackRate, int biAttack
    // this->skillName = skillName;
    // this->attackRate = attackRate;
    // this->biAttack = biAttack;
}
// デストラクタ
Skill::~Skill(){}
// スキル名セット
void Skill::setSkillName(string a)
{
    skillName = a;
}
// スキル名取得
string Skill::getSkillName() const
{
    return skillName;
}
// 攻撃力セット
void Skill::setAttackRate(int a)
{
    attackRate = a;
}
// 攻撃力取得
int Skill::getAttackRate() const
{
    return attackRate;
}
// 攻撃回数セット
void Skill::setBiAttack(int a)
{
    biAttack = a;
}
// 攻撃回数取得
int Skill::getBiAttack() const
{
    return biAttack;
}

// csv読み込み
void Skill::loadCSV(string filename)
{
    // TODO:csvから読み込み
    setData("ダミ～",0,0);
    setData("たたかう",1,1);
    setData("アタック",2,2);
    setData("つよアタック",10000,3);
    setData("連続アタック",10,5);
    setData("あったく4",100,5);
    setData("あったく5",100,5);
}


// リストにセット
void Skill::setData(string skillName,int attackRate, int biAttack)
{
    // vector<Skill>::iterator itr;
    // itr = skillList.end();
    Skill skill;
    skill.setSkillName(skillName);
    skill.setAttackRate(attackRate);
    skill.setBiAttack(biAttack);
    skillList.push_back(skill);
}

// リストからスキル名取得
string Skill::getListSkillName(int i) const
{
    return skillList[i].skillName;
}
// リストから攻撃力取得
int Skill::getListAttackRate(int i) const
{
    return skillList[i].attackRate;
}
// リストから攻撃回数取得
int Skill::getListBiAttack(int i) const
{
    return skillList[i].biAttack;
}

// // スキル発動
// void Skill::useSkill(int i)
// {
//     return skillList[i].biAttack;
// }
