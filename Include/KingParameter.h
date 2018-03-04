#pragma once

#include <string>
#include <vector>
#include <unordered_map>

enum class ECategory {
    ART,
    MILITARY,
    INTELLECTUAL,
    REST
};

enum class ESchedule {
    PAINTING,
    MUSIC,
    LITERATURE,
    GOURMET,
    SWORDS,
    BLACKMAGIC,
    WHITEMAGIC,
    SCIENCE,
    MILITARY,
    SOCIAL,
    ECONOMY,
    AGRICULTURE,
    DIPLOMACY,
    HISTORY,
    THEOLOGY,
    LAW,
    WALK,
    SUBMISSION,
    ARTVIEWING,
    GAMEWATCHING,
    TRAVELMOUNTAIN,
    TRAVELSEA,
};

struct Stat {
    std::string name;
    double value;
};

using ScheduleStat = Stat;

struct ScheduleParam {
    std::string id;
    ECategory category;
    ESchedule schedule;
    double successRate;
    double riseRate;
    double criticalSuccessRate;
    std::vector<ScheduleStat> stats;
};

enum class EBody {
    BODY1,
    BODY2,
    BODY3
};

enum class ECondition {
    CONDITION1,
    CONDITION2,
    CONDITION3,
    CONDITION4,
    CONDITION5,
    CONDITION6,
};

enum class EHealthy {
    HEALTHY1,
    HEALTHY2,
    HEALTHY3,
    HEALTHY4,
};

using StatTable = std::unordered_map<std::string, double>;
using DevelopTable = std::unordered_map<std::string, double>;

struct KingParameter {
    unsigned age;
    char birthday[4 + 1];   // mmdd
    EBody body;
    ECondition condition;
    EHealthy healthy;

    StatTable kingStats;
    StatTable countryStats;
    DevelopTable developRates;
};

void DebugDisplay (const StatTable & stats);
