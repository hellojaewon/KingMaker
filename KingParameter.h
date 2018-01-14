#pragma once

struct KingComprehension {
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

struct KingComprehensionSuccessRate {
    double paintingComprehensionSuccessRate;
    double musicComprehensionSuccessRate;
    double literatureComprehensionSuccessRate;
    double gourmetComprehensionSuccessRate;
    double swordsComprehensionSuccessRate;
    double blackMagicComprehensionSuccessRate;
    double whiteMagicComprehensionSuccessRate;
    double scienceComprehensionSuccessRate;
    double militaryComprehensionSuccessRate;
    double socialComprehensionSuccessRate;
    double economyComprehensionSuccessRate;
    double agricultureComprehensionSuccessRate;
    double diplomacyComprehensionSuccessRate;
    double historyComprehensionSuccessRate;
    double theologyComprehensionSuccessRate;
    double lawComprehensionSuccessRate;
};

struct KingComprehensionRiseRate {
    double paintingComprehensionRiseRate;
    double musicComprehensionRiseRate;
    double literatureComprehensionRiseRate;
    double gourmetComprehensionRiseRate;
    double swordsComprehensionRiseRate;
    double blackMagicComprehensionRiseRate;
    double whiteMagicComprehensionRiseRate;
    double scienceComprehensionRiseRate;
    double militaryComprehensionRiseRate;
    double socialComprehensionRiseRate;
    double economyComprehensionRiseRate;
    double agricultureComprehensionRiseRate;
    double diplomacyComprehensionRiseRate;
    double historyComprehensionRiseRate;
    double theologyComprehensionRiseRate;
    double lawComprehensionRiseRate;
};

struct KingComprehensionCriticalRate {
    double paintingComprehensionCriticalRate;
    double musicComprehensionCriticalRate;
    double literatureComprehensionCriticalRate;
    double gourmetComprehensionCriticalRate;
    double swordsComprehensionCriticalRate;
    double blackMagicComprehensionCriticalRate;
    double whiteMagicComprehensionCriticalRate;
    double scienceComprehensionCriticalRate;
    double militaryComprehensionCriticalRate;
    double socialComprehensionCriticalRate;
    double economyComprehensionCriticalRate;
    double agricultureComprehensionCriticalRate;
    double diplomacyComprehensionCriticalRate;
    double historyComprehensionCriticalRate;
    double theologyComprehensionCriticalRate;
    double lawComprehensionCriticalRate;
};

struct KingComprehensionDevelopRate {
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

    KingComprehension kingComprehension;
    KingComprehensionSuccessRate kingComprehensionSuccessRate;
    KingComprehensionRiseRate kingComPrehensionRiseRate;
    KingComprehensionCriticalRate kingComprehensionCriticalRate;
    KingComprehensionDevelopRate kingComprehensionDevelopRate;
};
