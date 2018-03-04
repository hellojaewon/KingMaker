#pragma once

#include <vector>
#include <string>

enum class EGrade {
    NORMAL,
    RARE,
    UNIQUE,
    HERO,
    LEGEND
};

enum class ELiegeStatType {
    COMMERCE_DEVELOP,
    AGRICULTURE_DEVELOP,
    SCIENCE_DEVELOP,
    CULTURE_DEVELOP,
    MAGIC_DEVELOP,
    EDUCATION_DEVELOP,
    MILITARY_DEVELOP,
    TAX,
    PROPOGATION
};

enum class ELiegeResult {
    SUCCESS,
    GREAT_SUCCESS,
    FAIL,
    MONEY_EVASION,
};

struct LiegeStat {
    ELiegeStatType type;
    double         value;
};

class ILiege {
public:
    virtual ~ILiege () {}

    virtual ELiegeResult DoMeeting () const = 0;

    virtual unsigned GetId () const = 0;
    virtual std::string GetName () const = 0;
    virtual std::string GetOccupation () const = 0;
    virtual EGrade GetGrade () const = 0;
    virtual std::string GetDialogue (ELiegeResult result) const = 0;
    virtual const std::vector<LiegeStat> & GetStats () const = 0;
    virtual unsigned GetBonusCriticalPower () const = 0;
    virtual unsigned GetSelfishness () const = 0;
};

class ILiegeNotify {
public:
    virtual void OnLiegeMeetingCompleted (
        std::shared_ptr<ILiege> liege,
        ELiegeResult            result
    ) = 0;
};

void LoadLieges ();
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
);
std::vector<std::shared_ptr<ILiege>> ListLieges ();
std::vector<Stat> GetStats (ELiegeStatType type);
