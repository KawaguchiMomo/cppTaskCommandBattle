#include "player.h"
#include "gameManager.h"
#include "skillList.h"
#include <limits>
#include <memory>
#include <iostream>

// スキル所持最大数
const int MAXHAVESKILL = 4;

// 取得スキルを選択
std::unique_ptr<Skill> Player::inputUseSkill(const SkillList& skillList)
{
    // シングルトン不採用　最終的に下記コードはやめる
    GameManager &gameManager = GameManager::get_instance();

    gameManager.printLine();
    int skillListSize = (int)skillList.getSkillList().size();
    // スキル一覧を表示
    for(int i = 1 ; i < skillListSize ; i++)
    {
        const std::shared_ptr< SkillSetting > skillSetting = skillList.getSkillList()[i];
        string message;
        message = to_string(i) + ": " + skillSetting->getName();
        if(skillSetting->getType() == Type::ACTIVE){
            message = message + "/アクティブ" + ":使用回数 " + to_string(skillSetting->getCanUseNumber()) + "/";
        }else if(skillSetting->getType() == Type::PASSIVE){
            message = message + "/パッシブ" + "/";
        }
        message = message + skillSetting->getDesc();
        cout << message << endl;
    }
    cout << endl; 
    int skillNumber = gameManager.inputNumber("スキルを選んでください", 1, skillListSize);
    system("clear");

    // キャラクター固有のスキルを作成
    std::unique_ptr<Skill> skill = std::make_unique<Skill>(skillList.getListSkill(skillNumber));
    
    return std::move(skill);
}


// プレイヤーの設定
void Player::settingPlayer(const SkillList& skillList)
{
    // シングルトン不採用　最終的に下記コードはやめる
    GameManager &gameManager = GameManager::get_instance();

    // Player player;

    // プレイヤーにスキルをセット
    // player = inputUsePlayer(playerList);
    // ダミースキルやたたかうスキルはどのキャラクターがもっても同じだが、
    // いちいちSkillクラスを作成しなければならないので
    // どこかで共通で呼び出せるようにしておく…？
    // std::shared_ptr<const SkillSetting> skill = std::make_shared<SkillSetting>();
    std::unique_ptr<Skill> dummySkill = std::make_unique<Skill>(skillList.getListSkill(0));
    setSkill(std::move(dummySkill));

    std::unique_ptr<Skill> tatakauSkill = std::make_unique<Skill>(skillList.getListSkill(1));
    setSkill(std::move(tatakauSkill));
    
    printHaveSkill();
    setSkill(std::move(inputUseSkill(skillList)));
    gameManager.printLine();

    printHaveSkill();
    setSkill(std::move(inputUseSkill(skillList)));
    gameManager.printLine();

    printHaveSkill();
    setSkill(std::move(inputUseSkill(skillList)));
    gameManager.printLine();
    
    // スキルによるステータス補正
    for(int i=1; i<=4 ; i++)
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
        cin.clear();
        gameManager.printBattleWindow();
        printHaveSkill();
        skillNumber = gameManager.inputNumber("コマンドを選んでください", 1, MAXHAVESKILL+1);

        //スキル発動
        std::shared_ptr<const SkillSetting> skillSetting = haveSkill[skillNumber]->getSkillSetting();
        // スキル残り使用回数確認
        if(!haveSkill[skillNumber]->isCanUse())
        {
            string message = skillSetting->getName() + "は残り使用回数がない！";
            gameManager.printMessage(message);
        }else{
            // 残り使用回数減少
            UsedCanUseNumber(skillNumber);
            break;
        }
    }

    return skillNumber;

}

// キャラクターの取得しているスキル表示
void Player::printHaveSkill() const
{
    int skillListSize = haveSkill.size();
    for(int i = 1; i < skillListSize; i++){
        std::shared_ptr<const SkillSetting> skillSetting = haveSkill[i]->getSkillSetting();
        const string& skillName = skillSetting->getName();
        int skillCanUseNumber = haveSkill[i]->getCanUseNumber();

        // 残り使用回数を表示
        string canUseNumber;
        if(skillCanUseNumber == -1){
            canUseNumber = "";
        }else{
            canUseNumber = "(" + to_string(skillCanUseNumber) + ")";
        }
        cout << i << " :" << skillName << canUseNumber << "  ";
    }
    cout << endl;
}


// 死亡
void Player::onDead() 
{
    isDead = true;
    GameManager &gameManager = GameManager::get_instance();
    gameManager.printGameOver();
}
