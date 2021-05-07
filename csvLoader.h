#ifndef _CSV_LOADER_H
#define _CSV_LOADER_H
#include <vector>
#include <string>
using namespace std;

class CsvLoader
{
    private:
        
    public:
        // コンストラクタ
        CsvLoader();
        // デストラクタ
        virtual ~CsvLoader();
        // csv読み込み
        vector<vector<string> > loadCSV(const string& name);
        // csvラベルの取得
        int getLabelIndex(vector<string> label, const string& labelName);
};

#endif