#pragma once

#include <string>
#include <vector>

struct ScheduleParam {
    std::string name;
    double comprehension;
    double successRate;
    double riseRate;
    double criticalSuccessRate;
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
