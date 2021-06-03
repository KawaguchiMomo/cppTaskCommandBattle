#ifndef _SKILL_LIST_H
#define _SKILL_LIST_H


#include <string>
#include <vector>
#include <memory>


class SkillSetting;
class SkillList
{
    private:
        std::vector< std::shared_ptr<SkillSetting> > skillList;
        // リストにセット
        void setSkill(std::shared_ptr<SkillSetting>);
    public:
        // コンストラクタ
        SkillList() = default;
        // デストラクタ
        virtual ~SkillList() = default;
        // コピーコンストラクタ
        SkillList(const SkillList&) = delete;
        // 代入演算子
        SkillList& operator=(const SkillList&) = delete;
        // リストを取得
        const std::vector< std::shared_ptr<SkillSetting> >& getSkillList() const;
        // csv読み込み
        void loadCSV(const std::string& filename);
        // リストからスキルを取得
        std::shared_ptr<const SkillSetting> getListSkill(int i) const;
        // スキルリストのIDとエネミーデータのスキルIDが一致するか走査
        std::shared_ptr<const SkillSetting> matchID(int id) const;
};

#endif