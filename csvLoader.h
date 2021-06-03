#ifndef _CSV_LOADER_H
#define _CSV_LOADER_H
#include <fstream>
#include <vector>
#include <string>


class CsvLoader
{
    private:
        const std::string basePath;
        // UTF-8 with BOMをUTF-8に変換
        void skip_utf8_bom(std::ifstream& fs);
    public:
        // コンストラクタ
        CsvLoader(const std::string basePath);
        // デストラクタ
        virtual ~CsvLoader() = default;
        // コピーコンストラクタ
        CsvLoader(const CsvLoader&) = delete;
        // 代入演算子
        CsvLoader& operator=(const CsvLoader&) = delete;
        // csv読み込み
        std::vector<std::vector<std::string> > loadCSV(const std::string& name);
        // csvラベルの取得
        int getLabelIndex(const std::vector<std::string>& label, const std::string& labelName);
};

#endif