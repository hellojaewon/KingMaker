#include <string>
#include <unordered_map>
#include "Schedule.h"

class CEducationArt : public ISchedule {
public:
    ECategory GetCategory () { return ECategory::ART; }
    bool DoSchedule (std::vector<ScheduleParam> & params) { return false; }
};

class CEducationMilitary : public ISchedule {
public:
    ECategory GetCategory () { return ECategory::MILITARY; }
    bool DoSchedule (std::vector<ScheduleParam> & params) { return false; }
};

class CEducationIntellectual : public ISchedule {
public:
    ECategory GetCategory () { return ECategory::POLITICS; }
    bool DoSchedule (std::vector<ScheduleParam> & params) { return false; }
};

class CRest : public ISchedule {
public:
    ECategory GetCategory () { return ECategory::REST; }
    bool DoSchedule (std::vector<ScheduleParam> & params) { return false; }
};

class CDrawing : public CEducationArt {
public:
    std::string GetId () { return "EducationArtDrawing"; }
};

class CMusic : public CEducationArt {
public:
    std::string GetId () { return "EducationArtMusic"; }

};

class CLiterature : public CEducationArt {
public:
    std::string GetId () { return "EducationArtLiterature"; }

};

class CDelicacies : public CEducationArt {
public:
    std::string GetId () { return "EducationArtDelicacies"; }

};

class CSwords : public CEducationMilitary {
public:
    std::string GetId () { return "EducationMilitarySwords"; }

};

class CBlackMagics : public CEducationMilitary {
public:
    std::string GetId () { return "EducationMilitaryBlackMagics"; }

};

class CWhiteMagics : public CEducationMilitary {
public:
    std::string GetId () { return "EducationMilitaryWhiteMagics"; }

};

class CMechanics : public CEducationMilitary {
public:
    std::string GetId () { return "EducationMilitaryMechanics"; }

};

class CStrategy : public CEducationMilitary {
public:
    std::string GetId () { return "EducationMilitaryStrategy"; }

};

class CSocial : public CEducationIntellectual {
public:
    std::string GetId () { return "EducationIntellectualSocial"; }

};

class CEconomy : public CEducationIntellectual {
public:
    std::string GetId () { return "EducationIntellectualEconomy"; }

};

class CAgriculture : public CEducationIntellectual {
public:
    std::string GetId () { return "EducationIntellectualAgriculture"; }

};

class CDiplomacy : public CEducationIntellectual {
public:
    std::string GetId () { return "EducationIntellectualDiplomacy"; }

};

class CHistory : public CEducationIntellectual {
public:
    std::string GetId () { return "EducationIntellectualHistory"; }

};

class CTheology : public CEducationIntellectual {
public:
    std::string GetId () { return "EducationIntellectualTheology"; }

};

class CLaw : public CEducationIntellectual {
public:
    std::string GetId () { return "EducationIntellectualLaw"; }

};

class CWalk : public CRest {
public:
    std::string GetId () { return "RestWalk"; }

};

class CSubmission : public CRest {
public:
    std::string GetId () { return "RestSubmission"; }

};

class CArtViewing : public CRest {
public:
    std::string GetId () { return "RestArtViewing"; }

};

class CGameWatching : public CRest {
public:
    std::string GetId () { return "RestGameWatching"; }

};

class CTravelMountain : public CRest {
public:
    std::string GetId () { return "RestTravelMountain"; }

};

class CTravelSea : public CRest {
public:
    std::string GetId () { return "RestTravelSea"; }

};

static bool s_initialized = false;
static std::unordered_map<std::string, std::shared_ptr<ISchedule>> s_table;

void InitializeScheduleTable () {
    s_table["EducationArtDrawing"] = std::make_shared<CDrawing>();
    s_table["EducationArtMusic"] = std::make_shared<CMusic>();
    s_table["EducationArtLiterature"] = std::make_shared<CLiterature>();
    s_table["EducationArtDelicacies"] = std::make_shared<CDelicacies>();
    s_table["EducationMilitarySwords"] = std::make_shared<CSwords>();
    s_table["EducationMilitaryBlackMagics"] = std::make_shared<CBlackMagics>();
    s_table["EducationMilitaryWhiteMagics"] = std::make_shared<CWhiteMagics>();
    s_table["EducationMilitaryMechanics"] = std::make_shared<CMechanics>();
    s_table["EducationMilitaryStrategy"] = std::make_shared<CStrategy>();
    s_table["EducationIntellectualSocial"] = std::make_shared<CSocial>();
    s_table["EducationIntellectualEconomy"] = std::make_shared<CEconomy>();
    s_table["EducationIntellectualAgriculture"] = std::make_shared<CAgriculture>();
    s_table["EducationIntellectualDiplomacy"] = std::make_shared<CDiplomacy>();
    s_table["EducationIntellectualHistory"] = std::make_shared<CHistory>();
    s_table["EducationIntellectualTheology"] = std::make_shared<CTheology>();
    s_table["EducationIntellectualLaw"] = std::make_shared<CLaw>();
    s_table["RestWalk"] = std::make_shared<CWalk>();
    s_table["RestSubmission"] = std::make_shared<CSubmission>();
    s_table["RestArtViewing"] = std::make_shared<CArtViewing>();
    s_table["RestGameWatching"] = std::make_shared<CGameWatching>();
    s_table["RestTravelMountain"] = std::make_shared<CTravelMountain>();
    s_table["RestTravelSea"] = std::make_shared<CTravelSea>();
}

std::shared_ptr<ISchedule> GetSchedule (std::string scheduleId) {
    if (!s_initialized) {
        InitializeScheduleTable();
        s_initialized = true;
    }

    auto it = s_table.find(scheduleId);
    if (it != s_table.end())
        return it->second;

    return nullptr;
}
