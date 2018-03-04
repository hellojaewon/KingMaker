#include <string>
#include <unordered_map>
#include <cassert>
#include <random>
#include "Schedule.h"

//=============================================================================
class CSchedule : public ISchedule {
public:
    CSchedule (const ScheduleParam & param)
     : m_id(param.id)
     , m_catetory(param.category)
     , m_successRate(param.successRate)
     , m_criticalSuccessRate(param.criticalSuccessRate)
     , m_riseRate(param.riseRate)
     , m_stats(std::move(param.stats))
    {}

    // ISchedule Interface
    EScheduleResult DoSchedule () const override;
    std::string GetId () const override { return m_id; }
    ECategory GetCategory () const override { return m_catetory; }
    double GetRiseRate () const override { return m_riseRate; }
    const std::vector<ScheduleStat> & GetStats () const override { return m_stats; }

private:
    std::string               m_id;
    ECategory                 m_catetory;
    double                    m_successRate;
    double                    m_criticalSuccessRate;
    double                    m_riseRate;
    std::vector<ScheduleStat> m_stats;
};

//=============================================================================
EScheduleResult CSchedule::DoSchedule () const {
    EScheduleResult result{EScheduleResult::FAIL};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1,10000);

    if (m_successRate > dis(gen)) {
        if (m_criticalSuccessRate > dis(gen))
            result = EScheduleResult::CRITICAL_SUCCESS;
        else
            result = EScheduleResult::SUCCESS;
    }

    return result;
}

//=============================================================================
static bool s_initialized = false;
static std::unordered_map<std::string, std::shared_ptr<ISchedule>> s_table;

std::vector<std::vector<double>> s_settings = {
    { 10,0,0,0,3,0,2,3,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    { 10,0,0,0,4,1,4,2,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    { 10,0,0,0,5,0,3,4,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0},
    { 10,0,0,3,2,2,3,3,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0},
    { 10,0,0,5,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0},
    { 10,3,0,1,0,2,0,0,0,-2,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0},
    { 10,3,0,1,0,1,0,0,0,2,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0},
    { 10,4,3,2,0,1,0,0,0,-1,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0},
    { 10,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0},
    { 10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0},
    { 10,5,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0},
    { 10,3,2,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0},
    { 10,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0},
    { 10,4,3,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0},
    { 10,2,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10},
    { 10,3,5,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10},
    { -20,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    { -6,0,2,1,2,0,0,3,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    { -15,0,0,0,0,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    { -15,0,2,0,-1,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    { -30,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    { -30,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
static std::vector<std::string> s_scheduleStatNames = {
    "Stress",
    "Intellegence",
    "Politics",
    "Health",
    "Art",
    "Charm",
    "Dignity",
    "Character",
    "Charisma",
    "Faith",
    "Obesity",
    "PaintingComprehension",
    "MusicComprehension",
    "LiteratureComprehension",
    "GourmetComprehension",
    "SwordsComprehension",
    "BlackMagicComprehension",
    "WhiteMagicComprehension",
    "ScienceComprehension",
    "MilitaryComprehension",
    "SocialComprehension",
    "EconomyComprehension",
    "AgricultureComprehension",
    "DiplomacyComprehension",
    "HistoryComprehension",
    "TheologyComprehension",
    "LawComprehension"
};

//=============================================================================
static std::vector<ScheduleStat> Setting (unsigned index) {
    std::vector<ScheduleStat> stats;

    auto row = s_settings[index];
    for (unsigned i = 0; i < 27; i++) {
        if (row[i] == 0)
            continue;
        ScheduleStat stat;
        stat.name = s_scheduleStatNames[i];
        stat.value = row[i];
        stats.push_back(stat);
    }

    return stats;
}

//=============================================================================
void LoadSchedules () {
    if (s_initialized)
        return;

    ScheduleParam schedules[] = {
        { "EducationArtDrawing",              ECategory::ART,          ESchedule::PAINTING,       1, 1, 1, Setting(0)  },
        { "EducationArtMusic",                ECategory::ART,          ESchedule::MUSIC,          1, 1, 1, Setting(1)  },
        { "EducationArtLiterature",           ECategory::ART,          ESchedule::LITERATURE,     1, 1, 1, Setting(2)  },
        { "EducationArtDelicacies",           ECategory::ART,          ESchedule::GOURMET,        1, 1, 1, Setting(3)  },
        { "EducationMilitarySwords",          ECategory::MILITARY,     ESchedule::SWORDS,         1, 1, 1, Setting(4)  },
        { "EducationMilitaryBlackMagics",     ECategory::MILITARY,     ESchedule::BLACKMAGIC,     1, 1, 1, Setting(5)  },
        { "EducationMilitaryWhiteMagics",     ECategory::MILITARY,     ESchedule::WHITEMAGIC,     1, 1, 1, Setting(6)  },
        { "EducationMilitaryMechanics",       ECategory::MILITARY,     ESchedule::SCIENCE,        1, 1, 1, Setting(7)  },
        { "EducationMilitaryStrategy",        ECategory::MILITARY,     ESchedule::MILITARY,       1, 1, 1, Setting(8)  },
        { "EducationIntellectualSocial",      ECategory::INTELLECTUAL, ESchedule::SOCIAL,         1, 1, 1, Setting(9)  },
        { "EducationIntellectualEconomy",     ECategory::INTELLECTUAL, ESchedule::ECONOMY,        1, 1, 1, Setting(10) },
        { "EducationIntellectualAgriculture", ECategory::INTELLECTUAL, ESchedule::AGRICULTURE,    1, 1, 1, Setting(11) },
        { "EducationIntellectualDiplomacy",   ECategory::INTELLECTUAL, ESchedule::DIPLOMACY,      1, 1, 1, Setting(12) },
        { "EducationIntellectualHistory",     ECategory::INTELLECTUAL, ESchedule::HISTORY,        1, 1, 1, Setting(13) },
        { "EducationIntellectualTheology",    ECategory::INTELLECTUAL, ESchedule::THEOLOGY,       1, 1, 1, Setting(14) },
        { "EducationIntellectualLaw",         ECategory::INTELLECTUAL, ESchedule::LAW,            1, 1, 1, Setting(15) },
        { "RestWalk",                         ECategory::REST,         ESchedule::WALK,           10000, 1, 1, Setting(16) },
        { "RestSubmission",                   ECategory::REST,         ESchedule::SUBMISSION,     10000, 1, 1, Setting(17) },
        { "RestArtViewing",                   ECategory::REST,         ESchedule::ARTVIEWING,     10000, 1, 1, Setting(18) },
        { "RestGameWatching",                 ECategory::REST,         ESchedule::GAMEWATCHING,   10000, 1, 1, Setting(19) },
        { "RestTravelMountain",               ECategory::REST,         ESchedule::TRAVELMOUNTAIN, 10000, 1, 1, Setting(20) },
        { "RestTravelSea",                    ECategory::REST,         ESchedule::TRAVELSEA,      10000, 1, 1, Setting(21) },
    };

    for (auto schedule : schedules) {
        s_table.insert(std::make_pair(schedule.id, std::make_shared<CSchedule>(schedule)));
    }
    s_initialized = true;
}

//=============================================================================
std::shared_ptr<ISchedule> GetSchedule (std::string scheduleId) {
    auto it = s_table.find(scheduleId);
    if (it != s_table.end())
        return it->second;

    assert(false);
    return nullptr;
}
