#ifndef _CSV_LOADER_H
#define _CSV_LOADER_H
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class CsvLoader
{
    static const std::string csvFolderPath;
    private:
        // コンストラクタ
        CsvLoader();
        // デストラクタ
        virtual ~CsvLoader() = default;
        CsvLoader(const CsvLoader&);
        CsvLoader& operator = (const CsvLoader&);
        // UTF-8 with BOMをUTF-8に変換
        static void skip_utf8_bom(ifstream& fs);
    public:
        // 呼び出し
        static CsvLoader& get_instance();
        // csv読み込み
        static vector<vector<string> > loadCSV(const string& name);
        // csvラベルの取得
        int getLabelIndex(const vector<string>& label, const string& labelName);
};

#endif