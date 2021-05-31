// CharacterはSkillを格納している。

#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "skill.h"

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Skill;
class SkillList;
class Character
{
    private:
    public:
        // コンストラクタ
        Character(std::string name, std::string image, int hp, int maxHp, double power, double defense, int luck, int score, std::string talk, bool isDead);
        // デストラクタ
        virtual ~Character();
        // 名前取得
        const string& getName() const;
        // 見た目取得
        const string& getImage() const;
        // HP取得
        int getMaxHp() const;
        // HP取得
        int getHp() const;
        // 攻撃力取得
        double getPower() const;
        // 防御力取得
        double getDefense() const;
        // 運取得
        int getLuck() const;
        // スコア取得
        int getScore() const;
        // HP補正
        void revisionMaxHp(int rate);
        // HP補正
        void revisionHp(int rate);
        // 攻撃力補正
        void revisionPower(double rate);
        // 防御力補正
        void revisionDefense(double rate);
        // 運補正
        void revisionLuck(int rate);
        // セリフ取得
        const string& getTalk() const;
        // スキル補正
        void revisionStatus(std::shared_ptr<const SkillSetting> skillSetting);
        // 持っているスキル番号を取得
        int getSkillNumber(int skillNumber) const;
        // スキルをセット
        void setSkill(std::unique_ptr<Skill> skill);
        // スキル回数を減少
        void UsedCanUseNumber(int skillNumber);
        // スキルを選択
        virtual int inputSkill() = 0;
        // スキルを決定する
        int useSkill();
        // 決定したスキルを使って攻撃する
        double attack(int skillNumber);
        // ダメージを受ける
        virtual void receivedDamage(double receivedPower);
        // 死亡判定
        void judgeDead();
        // 現在HP/最大HPの割合を算出
        double getHPPer() const;
        // 死亡
        virtual void onDead() = 0;
        // データを表示
        void printData() const;

    protected:
        string name;
        string image;
        int hp;
        int maxHp;
        double power;
        double defense;
        int luck;
        vector<int> haveSkillNumber;
        std::vector< std::unique_ptr<Skill> > haveSkill;
        int score;
        string talk;
        bool isDead;


};

#endif