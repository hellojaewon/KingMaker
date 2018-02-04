#pragma once

#include <string>
#include <vector>

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

struct ScheduleSetting {
    double stress;
    double intellegence;
    double politics;
    double health;
    double art;
    double charm;
    double dignity;
    double character;
    double charisma;
    double faith;
    double obesity;
    double paintingComprehension;
    double musicComprehension;
    double literatureComprehension;
    double gourmetComprehension;
    double swordsComprehension;
    double blackMagicComprehension;
    double whiteMagicComprehension;
    double scienceComprehension;
    double militaryComprehension;
    double socialComprehension;
    double economyComprehension;
    double agricultureComprehension;
    double diplomacyComprehension;
    double historyComprehension;
    double theologyComprehension;
    double lawComprehension;
};

struct ScheduleParam {
    ESchedule schedule;
    std::string name;
    double comprehension;
    double successRate;
    double riseRate;
    double criticalSuccessRate;

    ScheduleSetting scheduleSetting;
};

struct DevelopRate {
    double commerceDevelopRate;
    double agricultureDevelopRate;
    double scienceDevelopRate;
    double cultureDevelopRate;
    double magicDevelopRate;
    double militaryDevelopRate;
    double educationDevelopRate;
    double approvalBonusRate;
    double faithDevelopRate;
    double stateCoffersRate;
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

struct KingParameter {
    double intelligence;
    double politics;
    double strength;
    double charm;
    double art;
    double dignity;
    double personality;
    double faith;
    double charisma;
    double stress;
    unsigned age;
    char birthday[4 + 1];   // yymm
    EBody body;
    double obesity;
    ECondition condition;
    EHealthy healthy;

    std::vector<ScheduleParam> scheduleParams;
    DevelopRate developRate;
};
