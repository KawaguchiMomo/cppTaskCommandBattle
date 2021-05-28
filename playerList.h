#ifndef _PLAYER_LIST_H_
#define _PLAYER_LIST_H_
#include <string>
#include <memory>
#include <vector>
using namespace std;
class Player;

class PlayerList
{
    private:
        std::vector< std::shared_ptr<Player> > playerList;
    public:
        // コンストラクタ
        PlayerList();
        // デストラクタ
        virtual ~PlayerList();
        // csv読み込み
        void loadCSV(const string& filename);
        // リストを取得
        std::vector< std::shared_ptr<Player> > getPlayerList(); 
        // リストにキャラをセット
        void setPlayer(std::shared_ptr<Player>);
        // リストからキャラ取得
        std::shared_ptr<const Player> getPlayer(int i) const;
        // プレイヤーを選択
        std::shared_ptr<Player> inputUsePlayer();
};

#endif