#include "character.h"
#include "gameManager.h"
#include "skill.h"
#include "skillSetting.h"
#include <vector>
#include <memory>
#include <string>

// コンストラクタ
// Character::Character():name(""),image(""),hp(0),maxHp(0),power(0),defense(0),luck(0),score(0),talk(""),isDead(false) {}

// コンストラクタ
Character::Character(std::string name, std::string image, int hp, int maxHp, double power, double defense, int luck, int score, std::string talk, bool isDead)
                    :name(name),image(image),hp(hp),maxHp(maxHp),power(power),defense(defense),luck(luck),score(score),talk(talk),isDead(isDead) {}

// デストラクタ
Character::~Character(){}

// 名前セット
void Character::setName(const string& a)
{
    name = a;
}
// 名前取得
const string& Character::getName() const
{
    return name;
}

// 見た目セット
void Character::setImage(const string& a)
{
    image = a;
}
// 見た目取得
const string& Character::getImage() const
{
    return image;
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
void Character::setPower(double a)
{
    power = a;
}
// 攻撃力取得
double Character::getPower() const
{
    return power;
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
void Character::revisionStatus(std::shared_ptr<const SkillSetting> skillSetting)
{
    // std::shared_ptr<const SkillSetting> skillSetting = skill.getSkillSetting();
    setMaxHp(maxHp*skillSetting->getHPRate());
    setHp(hp*skillSetting->getHPRate());
    setPower(power*skillSetting->getAttackRate());
    setDefense(defense*skillSetting->getDefenseRate());
    setLuck(luck*skillSetting->getLuckRate());
}


// 読み込んだデータをセット
void Character::setData(const string& name,int hp, int power, int defense, int luck){
    setName(name);
    setMaxHp(hp);
    setHp(hp);
    setPower(power);
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
// // 持っているスキルセットを取得
// std::vector< std::unique_ptr<Skill> > Character::getSkillList() const
// {
//     return haveSkill;
// }
// スキルをセット
void Character::setSkill(std::unique_ptr<Skill> skill)
{
    haveSkill.push_back(std::move(skill));
}
// 持っているスキルを取得
// std::unique_ptr<Skill> Character::getSkill(int skillNumber) const
// {
//     return haveSkill[skillNumber];
// }

// スキルを選択
int Character::inputSkill(){
    return 1;
}
// スキル回数を減少
void Character::UsedCanUseNumber(int skillNumber)
{
    if(haveSkill[skillNumber]->getCanUseNumber() >= 1){
        // 残り使用回数減少
        haveSkill[skillNumber]->UsedCanUseNumber();
    }
}

// スキルを決定する
int Character::useSkill()
{
    GameManager &gameManager = GameManager::get_instance();
    
    // 入力
    int skillNumber = inputSkill();

    std::shared_ptr<const SkillSetting> skillSetting = haveSkill[skillNumber]->getSkillSetting();

    string message = name + "の" + skillSetting->getSkillName() + "！";
    gameManager.printMessage(message);

    return skillNumber;
}

// 決定したスキルを使って攻撃する
double Character::attack(int skillNumber)
{
    GameManager &gameManager = GameManager::get_instance();
    
    std::shared_ptr<const SkillSetting> skillSetting = haveSkill[skillNumber]->getSkillSetting();

    double random = (double)gameManager.GetRand(50, 150) / 100;
    double attackPower = power * skillSetting->getAttackRate() * random;
    // クリティカル判定
    int critLine = gameManager.GetRand(0, 100);
    if(luck >= critLine)
    {
        gameManager.printMessage("クリティカルヒット！");
        attackPower *= 2;
    }
    return attackPower;
}


// ダメージを受ける
void Character::receivedDamage(double receivedPower)
{
    GameManager &gameManager = GameManager::get_instance();

    double damage = (receivedPower - defense) < 0 ? 0 : (receivedPower - defense);
    hp-=damage;

    string message = name + "に" + to_string((int)damage) + "のダメージ！";
    gameManager.printMessage(message);

    judgeDead();

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
