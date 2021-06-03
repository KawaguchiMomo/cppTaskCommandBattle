#include "character.h"
#include "game_manager.h"
#include "skill.h"
#include "skill_setting.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>

// コンストラクタ
Character::Character(
    std::string name, std::string image, int hp, int maxHp, double power, double defense, int luck, int score, std::string talk, bool isDead
)
:name(name),image(image),hp(hp),maxHp(maxHp),power(power),defense(defense),luck(luck),score(score),talk(talk),isDead(isDead) 
{}

// 名前取得
const std::string& Character::getName() const
{
    return name;
}
// 見た目取得
const std::string& Character::getImage() const
{
    return image;
}
// 最大HP取得
int Character::getMaxHp() const
{
    return maxHp;
}
// HP取得
int Character::getHp() const
{
    return hp;
}
// 攻撃力取得
double Character::getPower() const
{
    return power;
}
// 防御力取得
double Character::getDefense() const
{
    return defense;
}
// 運取得
int Character::getLuck() const
{
    return luck;
}
// セリフ取得
const std::string& Character::getTalk() const
{
    return talk;
}
// スコア取得
int Character::getScore() const
{
    return score;
}
// 最大HP補正
void Character::revisionMaxHp(int rate)
{
    maxHp *= rate;
}
// HP補正
void Character::revisionHp(int rate)
{
    hp *= rate;
}
// 攻撃力補正
void Character::revisionPower(double rate)
{
    power *= rate;
}
// 防御力補正
void Character::revisionDefense(double rate)
{
    defense *= rate;
}
// 運補正
void Character::revisionLuck(int rate)
{
    luck *= rate;
}

// スキル補正
void Character::revisionStatus(std::shared_ptr<const SkillSetting> skillSetting)
{
    revisionMaxHp(skillSetting->getHPRate());
    revisionHp(skillSetting->getHPRate());
    revisionPower(skillSetting->getAttackRate());
    revisionDefense(skillSetting->getDefenseRate());
    revisionLuck(skillSetting->getLuckRate());
}


// 持っているスキル番号を取得
int Character::getSkillNumber(int skillNumber) const
{
    return haveSkillIDList[skillNumber];
}
// スキルをセット
void Character::setSkill(std::unique_ptr<Skill> skill)
{
    haveSkill.push_back(std::move(skill));
}

// スキルを選択
int Character::inputSkill(){
    return 1;
}
// スキル回数を減少
void Character::usedCanUseNumber(int skillNumber)
{
    if(haveSkill[skillNumber]->getCanUseNumber() >= 1){
        // 残り使用回数減少
        haveSkill[skillNumber]->usedCanUseNumber();
    }
}

// スキルを決定する
int Character::useSkill()
{
    // 入力
    int skillNumber = inputSkill();

    // スキル取得
    std::shared_ptr<const SkillSetting> skillSetting = haveSkill[skillNumber]->getSkillSetting();

    GameManager &gameManager = GameManager::get_instance();
    std::string message = name + "の" + skillSetting->getName() + "！";
    gameManager.printMessage(message);

    return skillNumber;
}

// 決定したスキルを使って攻撃する
double Character::attack(int skillNumber)
{
    
    std::shared_ptr<const SkillSetting> skillSetting = haveSkill[skillNumber]->getSkillSetting();

    GameManager &gameManager = GameManager::get_instance();
    double random = (double)gameManager.getRand(50, 150) / 100;
    double attackPower = power * skillSetting->getAttackRate() * random;
    // クリティカル判定
    int critLine = gameManager.getRand(0, 100);
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

    // ダメージはマイナスにならない
    double damage = (receivedPower - defense) < 0 ? 0 : (receivedPower - defense);
    hp-=damage;

    std::string message = name + "に" + std::to_string((int)damage) + "のダメージ！";
    GameManager &gameManager = GameManager::get_instance();
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

// データを表示
void Character::printData() const
{
    std::cout << "名前: " << name << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "攻撃力: " << power << std::endl;
    std::cout << "防御力: " << defense << std::endl;
    std::cout << "運: " << luck << std::endl;
}