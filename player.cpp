#include "player.h"
#include "gameManager.h"
#include "skillList.h"
#include <limits>
#include <memory>
#include <iostream>

// スキル所持最大数
const int MAX_HAVE_SKILL = 4;

// 取得スキルを選択
std::unique_ptr<Skill> Player::inputUseSkill(const SkillList& skillList)
{
    GameManager &gameManager = GameManager::get_instance();

    gameManager.printLine();
    int skillListSize = (int)skillList.getSkillList().size();
    // スキル一覧を表示
    for(int i = 0 ; i < skillListSize ; i++)
    {
        const std::shared_ptr< SkillSetting > skillSetting = skillList.getSkillList()[i];
        std::string message;
        message = std::to_string(i + 1) + ": " + skillSetting->getName();
        if(skillSetting->getType() == Type::ACTIVE){
            message = message + "/アクティブ" + ":使用回数 " + std::to_string(skillSetting->getCanUseNumber()) + "/";
        }else if(skillSetting->getType() == Type::PASSIVE){
            message = message + "/パッシブ" + "/";
        }
        message = message + skillSetting->getDesc();
        std::cout << message << std::endl;
    }
    std::cout << std::endl; 
    int skillNumber = gameManager.inputNumber("スキルを選んでください", 1, skillListSize);
    system("clear");

    // キャラクター固有のスキルを作成
    std::unique_ptr<Skill> skill = std::make_unique<Skill>(skillList.getListSkill(skillNumber));
    
    return std::move(skill);
}


// プレイヤーの設定
void Player::settingPlayer(const SkillList& skillList)
{
    GameManager &gameManager = GameManager::get_instance();

    // プレイヤーにスキルをセット

    for(int i = 0; i < MAX_HAVE_SKILL ; i++) 
    {
        if(i == 0){
            // 一番目のスキルはたたかう固定
            std::unique_ptr<Skill> tatakauSkill = std::make_unique<Skill>(skillList.getListSkill(0));
            setSkill(std::move(tatakauSkill));
        } else {
            printHaveSkill();
            setSkill(std::move(inputUseSkill(skillList)));
            gameManager.printLine();
        }
    }
        
    // スキルによるステータス補正
    for(int i = 0; i < MAX_HAVE_SKILL ; i++)
    {
        if(haveSkill[i]->getSkillSetting()->getType() == Type::PASSIVE){
            revisionStatus(haveSkill[i]->getSkillSetting());
        }
    }
}


// 攻撃に使うスキルを選択
int Player::inputSkill()
{
    GameManager &gameManager = GameManager::get_instance();

    int skillNumber;
    while(1)
    {
        //スキル入力
        std::cin.clear();
        gameManager.printBattleWindow();
        printHaveSkill();
        skillNumber = gameManager.inputNumber("コマンドを選んでください", 1, MAX_HAVE_SKILL);

        //スキル発動
        std::shared_ptr<const SkillSetting> skillSetting = haveSkill[skillNumber]->getSkillSetting();
        // スキル残り使用回数確認
        if(!haveSkill[skillNumber]->isCanUse())
        {
            std::string message = skillSetting->getName() + "は残り使用回数がない！";
            gameManager.printMessage(message);
        }else{
            // 残り使用回数減少
            usedCanUseNumber(skillNumber);
            break;
        }
    }

    return skillNumber;

}

// キャラクターの取得しているスキル表示
void Player::printHaveSkill() const
{
    int skillListSize = haveSkill.size();
    for(int i = 0; i < skillListSize; i++){
        std::shared_ptr<const SkillSetting> skillSetting = haveSkill[i]->getSkillSetting();
        const std::string& skillName = skillSetting->getName();
        int skillCanUseNumber = haveSkill[i]->getCanUseNumber();

        // 残り使用回数を表示
        std::string canUseNumber;
        if(skillCanUseNumber == -1){
            canUseNumber = "";
        }else{
            canUseNumber = "(" + std::to_string(skillCanUseNumber) + ")";
        }
        std::cout << i + 1 << " :" << skillName << canUseNumber << "  ";
    }
    std::cout << std::endl;
}


// 死亡
void Player::onDead() 
{
    isDead = true;
    GameManager &gameManager = GameManager::get_instance();
    gameManager.printGameOver();
}
