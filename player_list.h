#ifndef _PLAYER_LIST_H_
#define _PLAYER_LIST_H_
#include <string>
#include <memory>
#include <vector>

class Player;

class PlayerList
{
    private:
        std::vector< std::shared_ptr<Player> > playerList;
        // リストにキャラをセット
        void setPlayer(std::shared_ptr<Player>);
    public:
        // コンストラクタ
        PlayerList() = default;
        // デストラクタ
        virtual ~PlayerList() = default;
        // コピーコンストラクタ
        PlayerList(const PlayerList&) = delete;
        // 代入演算子
        PlayerList& operator=(const PlayerList&) = delete;
        // csv読み込み
        void loadCSV(const std::string& filename);
        // リストを取得
        const std::vector< std::shared_ptr<Player> >& getPlayerList() const;
        // リストからキャラ取得
        std::shared_ptr<const Player> getPlayer(int i) const;
        // プレイヤーを選択
        std::shared_ptr<Player> inputUsePlayer();
};

#endif