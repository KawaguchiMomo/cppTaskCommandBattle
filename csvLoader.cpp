#include "csvLoader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

// 呼び出し
CsvLoader& CsvLoader::get_instance()
{
    static CsvLoader instance;
    return instance;
}

// コンストラクタ
CsvLoader::CsvLoader(){
    csvFilePath = "./";
}
// デストラクタ
CsvLoader::~CsvLoader(){}
// csv読み込み
vector<vector<string> > CsvLoader::loadCSV(const string& name)
{
    vector<vector<string> > data;
    string str_buf;
    string str_comma_buf;
    string inputFilePath = csvFilePath + name;

    // 読み込むcsvファイルを開く
    ifstream file;
    file.open(inputFilePath);
    if(!file){
        // 読み込み失敗処理
        cout << "ファイルが存在しません" << endl;
        exit(1);
    }
    file.imbue(std::locale());
    skip_utf8_bom(file);

    // getline関数で1行ずつ読み込む(読み込んだ内容はstr_bufに格納)
    while (getline(file, str_buf)) {    
        istringstream i_stream(str_buf);
        data.push_back(vector<string>());

        // データ読み込み
        while (getline(i_stream, str_comma_buf, ',')) {
            data[data.size()-1].push_back(str_comma_buf);
            // cout << str_comma_buf << endl;
        }
    }
    // // 読み込んだデータの表示（テスト用）
    // for (auto& v : data) 
    // {
    //     for (auto& e : v) std::cout << " " << e ;
    //     std::cout << "\n";
    // }
    return data;
}

// csvラベルの取得
int CsvLoader::getLabelIndex(const vector<string>& label, const string& labelName)
{
    auto itr = find(label.begin(), label.end(), labelName);
    int labelIndex = 0;
    if(itr == label.end()){
        cout << "ラベルが形式と異なっています。見つからない値: " << labelName << endl;
        exit(1);
    }else{
        // ラベルの番号を取得
        labelIndex = distance(label.begin(), itr);
    }
    return labelIndex;
}

// UTF-8 with BOMをUTF-8に変換
void CsvLoader::skip_utf8_bom(ifstream& fs) {
    int dst[3];
    for (auto& i : dst) i = fs.get();
    constexpr int utf8[] = { 0xEF, 0xBB, 0xBF };
    if (!equal(begin(dst), end(dst), utf8)) fs.seekg(0);
}
