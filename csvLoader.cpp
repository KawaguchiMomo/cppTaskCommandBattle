#include "csvLoader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

// コンストラクタ
CsvLoader::CsvLoader(const std::string& basePath = "./") :basePath(basePath) {}

// csv読み込み
std::vector<std::vector<std::string> > CsvLoader::loadCSV(const std::string& name)
{
    std::vector<std::vector<std::string> > data;
    std::string str_buf;
    std::string str_comma_buf;
    std::string inputFilePath = basePath + name;

    // 読み込むcsvファイルを開く
    std::ifstream file;
    file.open(inputFilePath);
    if(!file){
        // 読み込み失敗処理
        std::cout << "ファイルが存在しません" << std::endl;
        exit(1);
    }
    file.imbue(std::locale());
    skip_utf8_bom(file);

    // getline関数で1行ずつ読み込む(読み込んだ内容はstr_bufに格納)
    while (getline(file, str_buf)) {    
        std::istringstream i_stream(str_buf);
        data.push_back(std::vector<std::string>());

        // データ読み込み
        while (getline(i_stream, str_comma_buf, ',')) {
            data[data.size()-1].push_back(str_comma_buf);
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
int CsvLoader::getLabelIndex(const std::vector<std::string>& label, const std::string& labelName)
{
    auto itr = find(label.begin(), label.end(), labelName);
    int labelIndex = 0;
    if(itr == label.end()){
        std::cout << "ラベルが形式と異なっています。見つからない値: " << labelName << std::endl;
        exit(1);
    }else{
        // ラベルの番号を取得
        labelIndex = distance(label.begin(), itr);
    }
    return labelIndex;
}

// UTF-8 with BOMをUTF-8に変換
void CsvLoader::skip_utf8_bom(std::ifstream& fs) {
    int dst[3];
    for (auto& i : dst) i = fs.get();
    constexpr int utf8[] = { 0xEF, 0xBB, 0xBF };
    if (!std::equal(std::begin(dst), std::end(dst), utf8)) fs.seekg(0);
}
