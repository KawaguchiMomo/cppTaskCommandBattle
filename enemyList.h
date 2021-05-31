#ifndef _ENEMY_LIST_H_
#define _ENEMY_LIST_H_
#include <string>
#include <memory>
#include <vector>
using namespace std;
class Enemy;

class EnemyList
{
    private:
        std::vector< std::shared_ptr<Enemy> > enemyList;
    public:
        // コンストラクタ
        EnemyList() = default;
        // デストラクタ
        virtual ~EnemyList() = default;
        // csv読み込み
        void loadCSV(const string& filename);
        // リストを取得
        std::vector< std::shared_ptr<Enemy> > getEnemyList() const; 
        // リストにキャラをセット
        void setEnemy(std::shared_ptr<Enemy>);
        // リストからキャラ取得
        std::shared_ptr<const Enemy> getEnemy(int i) const;
        // エネミーを選択
        std::shared_ptr<Enemy> inputUseEnemy();
};

#endif