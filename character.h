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
        string getName();
        // HPセット
        void setHp(int a);
        // HP取得
        int getHp();
        // 攻撃力セット
        void setAttack(int a);
        // 攻撃力取得
        int getAttack();
        // 防御力セット
        void setDefense(int a);
        // 防御力取得
        int getDefense();
        // 運セット
        void setLuck(int a);
        // 運取得
        int getLuck();

        
        // csvからデータを読み込む
        void loadDataCSV();
        // スキルを選択
        virtual int inputSkill() = 0;
        // スキルを使用
        void useSkill(int skillNumber);
        // ダメージを受ける
        void receivedDamage(int damage);
    protected:
        string charaName;
        int hp;
        int attack;
        int defense;
        int luck;
        vector<Skill> haveSkill;


};

#endif