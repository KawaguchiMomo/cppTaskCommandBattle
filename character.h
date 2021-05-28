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
        // Character();
        // コンストラクタ
        Character(std::string name, std::string image, int hp, int maxHp, double power, double defense, int luck, int score, std::string talk, bool isDead);
        // デストラクタ
        virtual ~Character();
        // 名前セット
        void setName(const string& a);
        // 名前取得
        const string& getName() const;
        // 見た目セット
        void setImage(const string& a);
        // 見た目取得
        const string& getImage() const;
        // HPセット
        void setMaxHp(int a);
        // HP取得
        int getMaxHp() const;
        // HPセット
        void setHp(int a);
        // HP取得
        int getHp() const;
        // 攻撃力セット
        void setPower(double a);
        // 攻撃力取得
        double getPower() const;
        // 防御力セット
        void setDefense(double a);
        // 防御力取得
        double getDefense() const;
        // 運セット
        void setLuck(int a);
        // 運取得
        int getLuck() const;
        // セリフセット
        void setTalk(const string& a);
        // セリフ取得
        const string& getTalk() const;
        // スコアセット
        void setScore(int a);
        // スコア取得
        int getScore() const;
        // 読み込んだデータをセット
        void setData(const string& name,int hp, int power, int defense, int luck);
        // スキル補正
        void revisionStatus(std::shared_ptr<const SkillSetting> skillSetting);
        // スキル番号をセット
        void setSkillNumber(int skillNumber);
        // 持っているスキル番号を取得
        int getSkillNumber(int skillNumber) const;
        // // 持っているスキルセットを取得
        // std::vector< std::unique_ptr<Skill> > getSkillList() const;
        // スキルをセット
        void setSkill(std::unique_ptr<Skill> skill);
        // // 持っているスキルを取得
        // std::unique_ptr<Skill> getSkill(int skillNumber) const;
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