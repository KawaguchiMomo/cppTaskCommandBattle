#ifndef _ENEMY_LIST_H_
#define _ENEMY_LIST_H_
#include <string>
#include <memory>
#include <vector>

class Enemy;

class EnemyList
{
    private:
        std::vector< std::shared_ptr<Enemy> > enemyList;
        // リストを取得
        const std::vector< std::shared_ptr<Enemy> >& getEnemyList() const; 
    public:
        // コンストラクタ
        EnemyList() = default;
        // デストラクタ
        virtual ~EnemyList() = default;
        // コピーコンストラクタ
        EnemyList(const EnemyList&) = delete;
        // 代入演算子
        EnemyList& operator=(const EnemyList&) = delete;
        // csv読み込み
        void loadCSV(const std::string& filename);
        // リストにキャラをセット
        void setEnemy(std::shared_ptr<Enemy>);
        // リストからキャラ取得
        std::shared_ptr<const Enemy> getEnemy(int i) const;
        // エネミーを選択
        std::shared_ptr<Enemy> inputUseEnemy();
};

#endif