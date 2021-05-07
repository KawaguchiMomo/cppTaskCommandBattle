#ifndef _ENEMY_LIST_H_
#define _ENEMY_LIST_H_
#include <string>

#include <vector>
using namespace std;
class Enemy;

class EnemyList
{
    private:
        vector<Enemy> enemyList;
    public:
        // コンストラクタ
        EnemyList();
        // デストラクタ
        virtual ~EnemyList();
        // csv読み込み
        void loadCSV(const string& filename);
        // リストにキャラをセット
        void setEnemy(Enemy& enemy);
        // リストからキャラ取得
        Enemy& getEnemy(int i);
};

#endif