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
        void setName(string a);
        // 名前取得
        string getName() const;
        // HPセット
        void setMaxHp(int a);
        // HP取得
        int getMaxHp() const;
        // HPセット
        void setHp(int a);
        // HP取得
        int getHp() const;
        // 攻撃力セット
        void setAttack(int a);
        // 攻撃力取得
        int getAttack() const;
        // 防御力セット
        void setDefense(int a);
        // 防御力取得
        int getDefense() const;
        // 運セット
        void setLuck(int a);
        // 運取得
        int getLuck() const;
        // csv読み込み
        void loadCSV(string filename);
        // 読み込んだデータをセット
        void setData(string charaName,int hp, int attack, int defense, int luck);
        // スキルをセット
        void setSkill(int skillNumber);
        // スキルを選択
        virtual int inputSkill() = 0;
        // スキルを使用
        int useSkill(int skillNumber);
        // ダメージを受ける
        void receivedDamage(int damage);
        // 現在HP/最大HPの割合を算出
        double getHPPer() const;
    protected:
        string charaName;
        int hp;
        int maxHp;
        int attack;
        int defense;
        int luck;
        vector<int> haveSkill;


};

#endif