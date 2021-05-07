// vectorのpush_backやCharacter型を返り値にするのがうまくいかなかったため後で削除
//
//
//


#include "characterList.h"
#include "character.h"
#include <vector>
#include <string>
#include "csvLoader.h"
#include <iostream>
// コンストラクタ
CharacterList::CharacterList(){
    // Character& character;
    // characterList.push_back(character);
}
// デストラクタ
CharacterList::~CharacterList(){}

// csv読み込み
void CharacterList::loadCSV(const string& filename)
{
}
// リストを取得
const vector<Character>& CharacterList::getCharacterList() const
{
    return characterList;
} 

// リストにキャラをセット
void CharacterList::setCharacter(Character& character)
{
    // characterList.push_back(character);
}
// リストからキャラ取得
Character CharacterList::getCharacter(int i) const
{
    return characterList[i];
}