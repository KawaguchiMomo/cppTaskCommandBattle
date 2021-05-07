#ifndef _PLAYER_LIST_H_
#define _PLAYER_LIST_H_
#include <string>

#include <vector>
using namespace std;
class Player;

class PlayerList
{
    private:
        vector<Player> playerList;
    public:
        // コンストラクタ
        PlayerList();
        // デストラクタ
        virtual ~PlayerList();
        // csv読み込み
        void loadCSV(const string& filename);
        // リストを取得
        const vector<Player>& getPlayerList() const; 
        // リストにキャラをセット
        void setPlayer(Player& player);
        // リストからキャラ取得
        Player& getPlayer(int i);
};

#endif