#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "skill.h"

#include <string>
#include <vector>

using namespace std;

class Skill;
class Character
{
    private:
    public:
        // コンストラクタ
        Character();
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
        void setAttack(double a);
        // 攻撃力取得
        double getAttack() const;
        // 防御力セット
        void setDefense(double a);
        // 防御力取得
        double getDefense() const;
        // 運セット
        void setLuck(int a);
        // 運取得
        int getLuck() const;
        // 読み込んだデータをセット
        void setData(const string& charaName,int hp, int attack, int defense, int luck);
        // スキルをセット
        void setSkill(int skillNumber);
        // スキルを選択
        virtual int inputSkill() = 0;
        // 持っているスキル番号を取得
        int useSkill(int skillNumber) const;
        // ダメージを受ける
        virtual void receivedDamage(int damage);
        // 死亡判定
        void judgeDead();
        // 現在HP/最大HPの割合を算出
        double getHPPer() const;
        // 死亡
        virtual void onDead() = 0;
    protected:
        string charaName;
        string charaImage;
        int hp;
        int maxHp;
        double attack;
        double defense;
        int luck;
        vector<int> haveSkill;
        bool isDead;


};

#endif