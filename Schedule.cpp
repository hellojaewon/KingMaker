#include <string>
#include <unordered_map>
#include <cassert>
#include "Schedule.h"

class CEducationArt : public ISchedule {
public:
    CEducationArt (const ScheduleParam & param)
     : ISchedule(param)
    {}

    ECategory GetCategory () { return ECategory::ART; }
};

class CEducationMilitary : public ISchedule {
public:
    CEducationMilitary (const ScheduleParam & param)
     : ISchedule(param)
    {}

    ECategory GetCategory () { return ECategory::MILITARY; }
};

class CEducationIntellectual : public ISchedule {
public:
    CEducationIntellectual (const ScheduleParam & param)
     : ISchedule(param)
    {}

   ECategory GetCategory () { return ECategory::POLITICS; }
};

class CRest : public ISchedule {
public:
    CRest (const ScheduleParam & param)
     : ISchedule(param)
    {}

   ECategory GetCategory () { return ECategory::REST; }
};

class CDrawing : public CEducationArt {
public:
    CDrawing (const ScheduleParam & param) : CEducationArt(param) {}
    std::string GetId () { return "EducationArtDrawing"; }
};

class CMusic : public CEducationArt {
public:
    CMusic (const ScheduleParam & param) : CEducationArt(param) {}
    std::string GetId () { return "EducationArtMusic"; }

};

class CLiterature : public CEducationArt {
public:
    CLiterature (const ScheduleParam & param) : CEducationArt(param) {}
    std::string GetId () { return "EducationArtLiterature"; }

};

class CDelicacies : public CEducationArt {
public:
    CDelicacies (const ScheduleParam & param) : CEducationArt(param) {}
    std::string GetId () { return "EducationArtDelicacies"; }

};

class CSwords : public CEducationMilitary {
public:
    CSwords (const ScheduleParam & param) : CEducationMilitary(param) {}
    std::string GetId () { return "EducationMilitarySwords"; }

};

class CBlackMagics : public CEducationMilitary {
public:
    CBlackMagics (const ScheduleParam & param) : CEducationMilitary(param) {}
    std::string GetId () { return "EducationMilitaryBlackMagics"; }

};

class CWhiteMagics : public CEducationMilitary {
public:
    CWhiteMagics (const ScheduleParam & param) : CEducationMilitary(param) {}
    std::string GetId () { return "EducationMilitaryWhiteMagics"; }

};

class CMechanics : public CEducationMilitary {
public:
    CMechanics (const ScheduleParam & param) : CEducationMilitary(param) {}
    std::string GetId () { return "EducationMilitaryMechanics"; }

};

class CStrategy : public CEducationMilitary {
public:
    CStrategy (const ScheduleParam & param) : CEducationMilitary(param) {}
    std::string GetId () { return "EducationMilitaryStrategy"; }

};

class CSocial : public CEducationIntellectual {
public:
    CSocial (const ScheduleParam & param) : CEducationIntellectual(param) {}
    std::string GetId () { return "EducationIntellectualSocial"; }

};

class CEconomy : public CEducationIntellectual {
public:
    CEconomy (const ScheduleParam & param) : CEducationIntellectual(param) {}
    std::string GetId () { return "EducationIntellectualEconomy"; }

};

class CAgriculture : public CEducationIntellectual {
public:
    CAgriculture (const ScheduleParam & param) : CEducationIntellectual(param) {}
    std::string GetId () { return "EducationIntellectualAgriculture"; }

};

class CDiplomacy : public CEducationIntellectual {
public:
    CDiplomacy (const ScheduleParam & param) : CEducationIntellectual(param) {}
    std::string GetId () { return "EducationIntellectualDiplomacy"; }

};

class CHistory : public CEducationIntellectual {
public:
    CHistory (const ScheduleParam & param) : CEducationIntellectual(param) {}
    std::string GetId () { return "EducationIntellectualHistory"; }

};

class CTheology : public CEducationIntellectual {
public:
    CTheology (const ScheduleParam & param) : CEducationIntellectual(param) {}
    std::string GetId () { return "EducationIntellectualTheology"; }

};

class CLaw : public CEducationIntellectual {
public:
    CLaw (const ScheduleParam & param) : CEducationIntellectual(param) {}
    std::string GetId () { return "EducationIntellectualLaw"; }

};

class CWalk : public CRest {
public:
    CWalk (const ScheduleParam & param) : CRest(param) {}
    std::string GetId () { return "RestWalk"; }

};

class CSubmission : public CRest {
public:
    CSubmission (const ScheduleParam & param) : CRest(param) {}
    std::string GetId () { return "RestSubmission"; }

};

class CArtViewing : public CRest {
public:
    CArtViewing (const ScheduleParam & param) : CRest(param) {}
    std::string GetId () { return "RestArtViewing"; }

};

class CGameWatching : public CRest {
public:
    CGameWatching (const ScheduleParam & param) : CRest(param) {}
    std::string GetId () { return "RestGameWatching"; }

};

class CTravelMountain : public CRest {
public:
    CTravelMountain (const ScheduleParam & param) : CRest(param) {}
    std::string GetId () { return "RestTravelMountain"; }

};

class CTravelSea : public CRest {
public:
    CTravelSea (const ScheduleParam & param) : CRest(param) {}
    std::string GetId () { return "RestTravelSea"; }

};

static bool s_initialized = false;
static std::unordered_map<std::string, std::shared_ptr<ISchedule>> s_table;

void InitializeScheduleTable (std::vector<ScheduleParam> & params) {
    if (s_initialized)
        return;

    assert(params.size() == 22);
    s_table["EducationArtDrawing"] = std::make_shared<CDrawing>(params[0]);
    s_table["EducationArtMusic"] = std::make_shared<CMusic>(params[1]);
    s_table["EducationArtLiterature"] = std::make_shared<CLiterature>(params[2]);
    s_table["EducationArtDelicacies"] = std::make_shared<CDelicacies>(params[3]);
    s_table["EducationMilitarySwords"] = std::make_shared<CSwords>(params[4]);
    s_table["EducationMilitaryBlackMagics"] = std::make_shared<CBlackMagics>(params[5]);
    s_table["EducationMilitaryWhiteMagics"] = std::make_shared<CWhiteMagics>(params[6]);
    s_table["EducationMilitaryMechanics"] = std::make_shared<CMechanics>(params[7]);
    s_table["EducationMilitaryStrategy"] = std::make_shared<CStrategy>(params[8]);
    s_table["EducationIntellectualSocial"] = std::make_shared<CSocial>(params[9]);
    s_table["EducationIntellectualEconomy"] = std::make_shared<CEconomy>(params[10]);
    s_table["EducationIntellectualAgriculture"] = std::make_shared<CAgriculture>(params[11]);
    s_table["EducationIntellectualDiplomacy"] = std::make_shared<CDiplomacy>(params[12]);
    s_table["EducationIntellectualHistory"] = std::make_shared<CHistory>(params[13]);
    s_table["EducationIntellectualTheology"] = std::make_shared<CTheology>(params[14]);
    s_table["EducationIntellectualLaw"] = std::make_shared<CLaw>(params[15]);
    s_table["RestWalk"] = std::make_shared<CWalk>(params[16]);
    s_table["RestSubmission"] = std::make_shared<CSubmission>(params[17]);
    s_table["RestArtViewing"] = std::make_shared<CArtViewing>(params[18]);
    s_table["RestGameWatching"] = std::make_shared<CGameWatching>(params[19]);
    s_table["RestTravelMountain"] = std::make_shared<CTravelMountain>(params[20]);
    s_table["RestTravelSea"] = std::make_shared<CTravelSea>(params[21]);
    s_initialized = true;
}

std::shared_ptr<ISchedule> GetSchedule (std::string scheduleId) {
    auto it = s_table.find(scheduleId);
    if (it != s_table.end())
        return it->second;

    return nullptr;
}
