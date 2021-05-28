#include "battleField.h"
#include "gameManager.h"
#include "skill.h"
#include "skillList.h"

using namespace std;

// コンストラクタ
Battle::Battle(){}
// デストラクタ
Battle::~Battle(){}

void Battle::startBattle(Character& attackChara, Character& defenseChara, const SkillList& skillList){
    GameManager &gameManager = GameManager::get_instance();
    int getSkillNumber;
    while(1)
    {
        //スキル入力
        getSkillNumber = attackChara.inputSkill();
        //スキル発動
        Skill skill = attackChara.getSkill(getSkillNumber);
        std::shared_ptr<const SkillSetting> skillSetting = skill.getSkillSetting();
        // スキル残り使用回数確認
        if(skill.getCanUseNumber() == 0)
        {
            string message = skillSetting->getSkillName() + "は残り使用回数がない！";
            gameManager.printMessage(message);
        }else{
            // 残り使用回数減少
            attackChara.UsedCanUseNumber(getSkillNumber);
            break;
        }
    }
    Skill skill = attackChara.getSkill(getSkillNumber);
    std::shared_ptr<const SkillSetting> skillSetting = skill.getSkillSetting();

    string message = attackChara.getName() + "の" + skillSetting->getSkillName() + "！";
    gameManager.printMessage(message);

    for(int i = 0 ; i < skillSetting->getBiAttack();i++)
    {
        double random = (double)gameManager.GetRand(50, 150) / 100;
        double power = attackChara.getPower() * skillSetting->getAttackRate() * random;

        // クリティカル判定
        int critLine = gameManager.GetRand(0, 100);
        if(attackChara.getLuck() >= critLine)
        {
            gameManager.printMessage("クリティカルヒット！");
            power = power * 2;
        }

        // double defense = defenseChara.getDefense();
        // ダメージがマイナスにならないように
        // double damage = (power - defense) < 0 ? 0 : (power - defense);

        defenseChara.receivedDamage(power);

        string message = defenseChara.getName() + "に" + to_string((int)damage) + "のダメージ！";
        gameManager.printMessage(message);

        // 死亡判定
        defenseChara.judgeDead();

    }
}

