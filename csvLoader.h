#ifndef _CSV_LOADER_H
#define _CSV_LOADER_H
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class CsvLoader
{
    private:
        string csvFilePath;
        // コンストラクタ
        CsvLoader();
        // デストラクタ
        virtual ~CsvLoader();
        CsvLoader(const CsvLoader&);
        CsvLoader& operator = (const CsvLoader&);
    public:
        // 呼び出し
        static CsvLoader& get_instance();
        // csv読み込み
        vector<vector<string> > loadCSV(const string& name);
        // csvラベルの取得
        int getLabelIndex(const vector<string>& label, const string& labelName);
        void skip_utf8_bom(ifstream& fs);
};

#endif