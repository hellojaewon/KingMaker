#include <unordered_map>
#include <random>
#include <cassert>
#include "KingParameter.h"
#include "Liege.h"

//=============================================================================
class CLiege : public ILiege {
public:
    CLiege (
        std::string name,
        std::string occupation,
        EGrade grade,
        std::vector<LiegeStat> stats,
        std::vector<std::string> dialogues,
        std::string successDialogue,
        std::string greatSuccessDialogue,
        std::string moneyEvasionDialogue,
        unsigned loyalty,
        unsigned selfishness,
        unsigned passion,
        unsigned bonusCriticalPower
    );

    ELiegeResult DoMeeting () const override;

    unsigned GetId () const override { return m_id; }
    std::string GetName () const override { return m_name; }
    std::string GetOccupation () const override { return m_occupation; }
    EGrade GetGrade () const override { return m_grade; }
    std::string GetDialogue (ELiegeResult result) const override;
    const std::vector<LiegeStat> & GetStats () const override { return m_stats; }
    unsigned GetBonusCriticalPower () const override { return m_bonusCriticalPower; }
    unsigned GetSelfishness () const override { return m_selfishness; }

private:
    static unsigned s_id;

    unsigned m_id;
    std::string m_name;                     // max : 16
    std::string m_occupation;
    EGrade m_grade;
    std::vector<LiegeStat> m_stats;         // max : 3
    std::vector<std::string> m_dialogues;   // max : 5 (30 characters per each)

    std::string m_successDialogue;
    std::string m_greatSuccessDialogue;
    std::string m_failDialogue;
    std::string m_moneyEvasionDialogue;

    unsigned m_loyalty;
    unsigned m_selfishness;
    unsigned m_passion;
    unsigned m_bonusCriticalPower;
};

unsigned CLiege::s_id = 1;

//=============================================================================
CLiege::CLiege (
    std::string name,
    std::string occupation,
    EGrade grade,
    std::vector<LiegeStat> stats,
    std::vector<std::string> dialogues,
    std::string successDialogue,
    std::string greatSuccessDialogue,
    std::string moneyEvasionDialogue,
    unsigned loyalty,
    unsigned selfishness,
    unsigned passion,
    unsigned bonusCriticalPower
)
 : m_id(s_id++)
 , m_name(name)
 , m_occupation(occupation),
   m_grade(grade),
   m_stats(stats),
   m_dialogues(dialogues),
   m_successDialogue(successDialogue),
   m_greatSuccessDialogue(greatSuccessDialogue),
   m_moneyEvasionDialogue(moneyEvasionDialogue),
   m_loyalty(loyalty),
   m_selfishness(selfishness),
   m_passion(passion),
   m_bonusCriticalPower(bonusCriticalPower)
{}

//=============================================================================
ELiegeResult CLiege::DoMeeting () const {
    ELiegeResult result{ELiegeResult::FAIL};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1,100);

    if (m_loyalty > unsigned(dis(gen))) {
        if (m_passion > unsigned(dis(gen)))
            result = ELiegeResult::GREAT_SUCCESS;
        else
            result = ELiegeResult::SUCCESS;
    } else {
        if (m_selfishness > unsigned(dis(gen)))
            result = ELiegeResult::MONEY_EVASION;
        else
            result = ELiegeResult::FAIL;
    }

    return result;
}

//=============================================================================
std::string CLiege::GetDialogue (ELiegeResult result) const {
    switch (result) {
        case ELiegeResult::SUCCESS:
            return m_successDialogue;
        case ELiegeResult::GREAT_SUCCESS:
            return m_greatSuccessDialogue;
        case ELiegeResult::FAIL:
            return m_failDialogue;
        case ELiegeResult::MONEY_EVASION:
            return m_moneyEvasionDialogue;
    }
}

//=============================================================================
struct EnumClassHash {
    template <typename T>
    std::size_t operator() (T t) const {
        return static_cast<std::size_t>(t);
    }
};

//=============================================================================
static bool s_initialized = false;
static std::vector<std::shared_ptr<ILiege>> s_lieges;
static std::unordered_map<ELiegeStatType, std::vector<Stat>, EnumClassHash> s_table;

//=============================================================================
static std::vector<Stat> Setting (unsigned index) {
    static std::vector<std::vector<double>> s_settings = {
        { 1,0,0,0,0,0,0,0,0,0 },
        { 0,1,0,0,0,0,0,0,0,0 },
        { 0,0,1,0,0,0,0,0,0,0 },
        { 0,0,0,1,0,0,0,0,0,0 },
        { 0,0,0,0,1,0,0,0,0,0 },
        { 0,0,0,0,0,1,0,0,0,0 },
        { 0,0,0,0,0,0,1,0,0,0 },
        { 0,0,0,0,0,0,0,0,-1,2 },
        { 0,0,0,0,0,0,0,1,0,0 },
    };

    static std::vector<std::string> s_statNames = {
        "commerce",
        "agriculture",
        "science",
        "culture",
        "magic",
        "military",
        "education",
        "faith",
        "approvalRating",
        "stateCoffers",
    };

    std::vector<Stat> stats;

    auto row = s_settings[index];
    for (unsigned i = 0; i < 10; i++) {
        if (row[i] == 0)
            continue;
        Stat stat;
        stat.name = s_statNames[i];
        stat.value = row[i];
        stats.push_back(stat);
    }

    return stats;
}

//=============================================================================
void LoadLieges () {
    if (s_initialized)
        return;

    struct MeetingParam {
        ELiegeStatType    type;
        std::vector<Stat> stats;
    };

    MeetingParam meetingParams[] = {
        { ELiegeStatType::COMMERCE_DEVELOP,    Setting(0) },
        { ELiegeStatType::AGRICULTURE_DEVELOP, Setting(1) },
        { ELiegeStatType::SCIENCE_DEVELOP,     Setting(2) },
        { ELiegeStatType::CULTURE_DEVELOP,     Setting(3) },
        { ELiegeStatType::MAGIC_DEVELOP,       Setting(4) },
        { ELiegeStatType::EDUCATION_DEVELOP,   Setting(5) },
        { ELiegeStatType::MILITARY_DEVELOP,    Setting(6) },
        { ELiegeStatType::TAX,                 Setting(7) },
        { ELiegeStatType::PROPOGATION,         Setting(8) },
    };

    for (auto param : meetingParams)
        s_table.insert(std::make_pair(param.type, param.stats));

    s_initialized = true;
}

//=============================================================================
void CreateLiege (
    std::string name,
    std::string occupation,
    EGrade grade,
    std::vector<LiegeStat> stats,
    std::vector<std::string> dialogues,
    std::string successDialogue,
    std::string greatSuccessDialogue,
    std::string moneyEvasionDialogue,
    unsigned loyalty,
    unsigned selfishness,
    unsigned passion,
    unsigned bonusCriticalPower
) {
    s_lieges.push_back(std::make_shared<CLiege>(
        name,
        occupation,
        grade,
        stats,
        dialogues,
        successDialogue,
        greatSuccessDialogue,
        moneyEvasionDialogue,
        loyalty,
        selfishness,
        passion,
        bonusCriticalPower
    ));
}

//=============================================================================
std::vector<std::shared_ptr<ILiege>> ListLieges () {
    return s_lieges;
}

//=============================================================================
std::vector<Stat> GetStats (ELiegeStatType type) {
    auto it = s_table.find(type);
    if (it == s_table.end())
        assert(false);

    return it->second;
}
