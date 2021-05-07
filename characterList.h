#ifndef _CHARACTER_LIST_H_
#define _CHARACTER_LIST_H_
#include <string>

#include <vector>
using namespace std;
class Character;

class CharacterList
{
    private:
        vector<Character> characterList;
    public:
        // コンストラクタ
        CharacterList();
        // デストラクタ
        virtual ~CharacterList();
        // csv読み込み
        void loadCSV(const string& filename);
        // リストを取得
        const vector<Character>& getCharacterList() const; 
        // リストにキャラをセット
        void setCharacter(Character& character);
        // リストからキャラ取得
        Character getCharacter(int i) const;
};

#endif