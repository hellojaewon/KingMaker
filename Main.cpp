#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include "KingParameter.h"
#include "Schedule.h"
#include "KingMaker.h"

static KingParameter LoadKingParameter () {
    KingParameter params;
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
        params.stats.insert(std::make_pair(s.name, s.value));

    return params;
}

void DebugDisplay (const StatTable & stats) {
    std::cout<<"------------------------------\n";
    std::cout<<"ScheduleStats...\n";
    std::cout<<"------------------------------\n";
    for (auto & stat : stats)
        std::cout<<stat.first<<": "<<stat.second<<"\n";
}

void DebugDisplay (const std::vector<ScheduleStat> & stats) {
    std::cout<<"------------------------------\n";
    std::cout<<"ScheduleStats...\n";
    std::cout<<"------------------------------\n";
    for (auto & stat : stats)
        std::cout<<stat.name<<": "<<stat.value<<"\n";
}

void DebugDisplay (const KingParameter & params) {
    std::cout<<"------------------------------\n";
    std::cout<<"KingParameter...\n";
    std::cout<<"------------------------------\n";
    std::cout<<"age: "<<params.age<<"\n";
    std::cout<<"birthday: "<<params.birthday<<"\n";
    std::cout<<"body: "<<static_cast<int>(params.body)<<"\n";
    std::cout<<"condition: "<<static_cast<int>(params.condition)<<"\n";
    std::cout<<"healthy: "<<static_cast<int>(params.healthy)<<"\n";
    DebugDisplay(params.stats);
}

int main () {
    auto params = LoadKingParameter();
//    DebugDisplay(params);
    auto kingMaker = std::make_unique<CKingMaker>(params);
    LoadSchedules();
    ExecuteGame(std::move(kingMaker));
    return 0;
}
