#include "csvLoader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;


// コンストラクタ
CsvLoader::CsvLoader(){}
// デストラクタ
CsvLoader::~CsvLoader(){}
// csv読み込み
vector<vector<string> > CsvLoader::loadCSV(const string& name)
{
    cout << "読み込み開始" << endl;

    vector<vector<string> > data;
    string str_buf;
    string str_conma_buf;
    string csvFilePath = "./";
    string inputFilePath = csvFilePath + name;

    // 読み込むcsvファイルを開く
    ifstream ifs(name);
    if(!ifs){
        // 読み込み失敗処理
        cout << "ファイルが存在しません" << endl;
        exit(1);
    }

    // getline関数で1行ずつ読み込む(読み込んだ内容はstr_bufに格納)
    while (getline(ifs, str_buf)) {    
        istringstream i_stream(str_buf);
        data.push_back(vector<string>());

        // データ読み込み
        while (getline(i_stream, str_conma_buf, ',')) {
            data[data.size()-1].push_back(str_conma_buf);
            // cout << str_conma_buf << endl;
        }
    }
    cout << "読み込み終了" << endl;
    for (auto& v : data) 
    {
        for (auto& e : v) std::cout << " " << e ;
        std::cout << "\n";
    }
    return data;
}

// csvラベルの取得
int CsvLoader::getLabelIndex(vector<string> label, const string& labelName)
{
    auto itr = find(label.begin(), label.end(), labelName);
    int labelIndex = 0;
    if(itr == label.end()){
        cout << "ラベルが形式と異なっています" << endl;
        exit(1);
    }else{
        // ラベルの番号を取得
        labelIndex = distance(label.begin(), itr);
    }
    return labelIndex;
}

