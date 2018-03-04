#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "KingMaker.h"

static std::string CategoryToStr (ECategory category) {
    switch (category) {
        case ECategory::ART:
            return "Art";
        case ECategory::MILITARY:
            return "Military";
        case ECategory::INTELLECTUAL:
            return "Intellectual";
        case ECategory::REST:
            return "Rest";
    }
}

static std::string ResultToStr (EScheduleResult result) {
    switch (result) {
        case EScheduleResult::SUCCESS:
            return "success";
        case EScheduleResult::CRITICAL_SUCCESS:
            return "critical success";
        case EScheduleResult::FAIL:
            return "fail";
    }
}

static std::string ResultToStr (ELiegeResult result) {
    switch (result) {
        case ELiegeResult::SUCCESS:
            return "success";
        case ELiegeResult::GREAT_SUCCESS:
            return "great success";
        case ELiegeResult::FAIL:
            return "fail";
        case ELiegeResult::MONEY_EVASION:
            return "money evasion";
    }
}


static std::shared_ptr<KingParameter> LoadKingParameter () {
    auto params = std::make_shared<KingParameter>();

    params->age = 20;
//    strcpy(params.birthday, "0302", 5);
    params->body = EBody::BODY1;
    params->condition = ECondition::CONDITION1;
    params->healthy = EHealthy::HEALTHY1;

    ScheduleStat scheduleStats[] = {
        { "Stress",                   0 },
        { "Intellegence",             0 },
        { "Politics",                 0 },
        { "Health",                   0 },
        { "Art",                      0 },
        { "Charm",                    0 },
        { "Dignity",                  0 },
        { "Character",                0 },
        { "Charisma",                 0 },
        { "Faith",                    0 },
        { "Obesity",                  0 },
        { "PaintingComprehension",    0 },
        { "MusicComprehension",       0 },
        { "LiteratureComprehension",  0 },
        { "GourmetComprehension",     0 },
        { "SwordsComprehension",      0 },
        { "BlackMagicComprehension",  0 },
        { "WhiteMagicComprehension",  0 },
        { "ScienceComprehension",     0 },
        { "MilitaryComprehension",    0 },
        { "SocialComprehension",      0 },
        { "EconomyComprehension",     0 },
        { "AgricultureComprehension", 0 },
        { "DiplomacyComprehension",   0 },
        { "HistoryComprehension",     0 },
        { "TheologyComprehension",    0 },
        { "LawComprehension",         0 },
    };
    for (auto s : scheduleStats)
        params->kingStats.insert(std::make_pair(s.name, s.value));

    struct CountryStat {
        std::string name;
        double      value;
    };

    CountryStat countryStats[] = {
        { "commerce",     0 },
        { "agriculture",  0 },
        { "science",      0 },
        { "culture",      0 },
        { "magic",        0 },
        { "military",     0 },
        { "education",    0 },
        { "approval",     0 },
        { "faith",        0 },
        { "stateCoffers", 0 },
    };
    for (auto s : countryStats)
        params->countryStats.insert(std::make_pair(s.name, s.value));

    for (auto s : countryStats)
        params->developRates.insert(std::make_pair(s.name, 1));

    return params;
}
static void AddTestLieges () {
    std::vector<LiegeStat> stats;
    LiegeStat stat1;
    stat1.type = ELiegeStatType::COMMERCE_DEVELOP;
    stat1.value = 10;
    stats.push_back(stat1);
    std::vector<std::string> dialogues = { "hello", "world" };
    CreateLiege(
        "Liege1",
        "job1",
        EGrade::NORMAL,
        stats,
        dialogues,
        "success dialogue",
        "great success dialogue",
        "money evasion dialogue",
        10,
        10,
        10,
        10
    );

    std::vector<LiegeStat> stats2;
    LiegeStat stat2_1;
    stat2_1.type = ELiegeStatType::SCIENCE_DEVELOP;
    stat2_1.value = 10;
    LiegeStat stat2_2;
    stat2_2.type = ELiegeStatType::CULTURE_DEVELOP;
    stat2_2.value = 10;
    stats2.push_back(stat2_1);
    stats2.push_back(stat2_2);
    CreateLiege(
        "Liege2",
        "job2",
        EGrade::HERO,
        stats,
        dialogues,
        "success dialogue",
        "great success dialogue",
        "money evasion dialogue",
        10,
        10,
        10,
        10
    );
}

void DebugDisplay (std::string title, const StatTable & stats) {
    std::cout<<"------------------------------\n";
    std::cout<<title<<"\n";
    std::cout<<"------------------------------\n";
    for (auto & stat : stats)
        std::cout<<stat.first<<": "<<stat.second<<"\n";
}

void DebugDisplay (std::shared_ptr<KingParameter> params) {
    std::cout<<"------------------------------\n";
    std::cout<<"KingParameter...\n";
    std::cout<<"------------------------------\n";
    std::cout<<"age: "<<params->age<<"\n";
    std::cout<<"birthday: "<<params->birthday<<"\n";
    std::cout<<"body: "<<static_cast<int>(params->body)<<"\n";
    std::cout<<"condition: "<<static_cast<int>(params->condition)<<"\n";
    std::cout<<"healthy: "<<static_cast<int>(params->healthy)<<"\n";
    DebugDisplay("KingStats...", params->kingStats);
}

class CScheduleNotify : public IScheduleNotify {
public:
    // IScheduleNotify interface
    void OnScheduleCompleted (
        std::shared_ptr<ISchedule> schedule,
        EScheduleResult            result
    ) override {
        std::cout<<"Id: "<<schedule->GetId()<<", ";
        std::cout<<"Category: "<<CategoryToStr(schedule->GetCategory())<<", ";
        std::cout<<"Result: "<<ResultToStr(result)<<"\n";
    }
};

class CLiegeNotify : public ILiegeNotify {
public:
    // ILiegeNotify interface
    void OnLiegeMeetingCompleted (
        std::shared_ptr<ILiege> liege,
        ELiegeResult            result
    ) override {
        std::cout<<"liegeId: "<<liege->GetId()<<", ";
        std::cout<<"liegeName: "<<liege->GetName()<<", ";
        std::cout<<"liegeOccupation: "<<liege->GetOccupation()<<", ";
        std::cout<<"liegeGrade: "<<static_cast<int>(liege->GetGrade())<<", ";
        std::cout<<"Result: "<<ResultToStr(result)<<"\n";
    }
};

int main () {
    auto params = LoadKingParameter();
    auto kingMaker = std::make_unique<CKingMaker>(params);
    LoadSchedules();
    LoadLieges();

    auto scheduleNotify = std::make_shared<CScheduleNotify>();
    std::vector<std::shared_ptr<ISchedule>> schedules;
    schedules.push_back(GetSchedule("EducationArtDrawing"));
    schedules.push_back(GetSchedule("RestWalk"));
    schedules.push_back(GetSchedule("EducationArtLiterature"));
    schedules.push_back(GetSchedule("EducationArtDelicacies"));
    kingMaker->Schedule(schedules, scheduleNotify);
    DebugDisplay(params);

    AddTestLieges();
    auto lieges = ListLieges();
    auto liegeNotify = std::make_shared<CLiegeNotify>();
    kingMaker->LiegeMeeting(lieges, liegeNotify);
    DebugDisplay("CountryStats...", params->countryStats);

    return 0;
}
