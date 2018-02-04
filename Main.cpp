#include <string>
#include <memory>
#include "KingParameter.h"
#include "Schedule.h"
#include "KingMaker.h"

double s_settings[22][27] = {
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

static ScheduleSetting Setting (unsigned index) {
    ScheduleSetting setting;
    setting.stress = s_settings[index][0];
    setting.intellegence = s_settings[index][1];
    setting.politics = s_settings[index][2];
    setting.health = s_settings[index][3];
    setting.art = s_settings[index][4];
    setting.charm = s_settings[index][5];
    setting.dignity = s_settings[index][6];
    setting.character = s_settings[index][7];
    setting.charisma = s_settings[index][8];
    setting.faith = s_settings[index][9];
    setting.obesity = s_settings[index][10];
    setting.paintingComprehension = s_settings[index][11];
    setting.musicComprehension = s_settings[index][12];
    setting.literatureComprehension = s_settings[index][13];
    setting.gourmetComprehension = s_settings[index][14];
    setting.swordsComprehension = s_settings[index][15];
    setting.blackMagicComprehension = s_settings[index][16];
    setting.whiteMagicComprehension = s_settings[index][17];
    setting.scienceComprehension = s_settings[index][18];
    setting.militaryComprehension = s_settings[index][19];
    setting.socialComprehension = s_settings[index][20];
    setting.economyComprehension = s_settings[index][21];
    setting.agricultureComprehension = s_settings[index][22];
    setting.diplomacyComprehension = s_settings[index][23];
    setting.historyComprehension = s_settings[index][24];
    setting.theologyComprehension = s_settings[index][25];
    setting.lawComprehension = s_settings[index][26];

    return setting;
}

static KingParameter LoadKingParameter () {
    KingParameter params;

    // scheduleParams
    ScheduleParam scheduleParams[] = {
        { ESchedule::PAINTING,       "Painting",       0,  0.1, 1, 0.05, Setting(0)  },
        { ESchedule::MUSIC,          "Music",          0,  0.1, 1, 0.05, Setting(1)  },
        { ESchedule::LITERATURE,     "Literature",     0,  0.1, 1, 0.05, Setting(2)  },
        { ESchedule::GOURMET,        "Gourmet",        0,  0.1, 1, 0.05, Setting(3)  },
        { ESchedule::SWORDS,         "Swords",         0,  0.1, 1, 0.05, Setting(4)  },
        { ESchedule::BLACKMAGIC,     "BlackMagic",     0,  0.1, 1, 0.05, Setting(5)  },
        { ESchedule::WHITEMAGIC,     "WhiteMagic",     0,  0.1, 1, 0.05, Setting(6)  },
        { ESchedule::SCIENCE,        "Science",        0,  0.1, 1, 0.05, Setting(7)  },
        { ESchedule::MILITARY,       "Military",       0,  0.1, 1, 0.05, Setting(8)  },
        { ESchedule::SOCIAL,         "Social",         0,  0.1, 1, 0.05, Setting(9)  },
        { ESchedule::ECONOMY,        "Economy",        0,  0.1, 1, 0.05, Setting(10)  },
        { ESchedule::AGRICULTURE,    "Agriculture",    0,  0.1, 1, 0.05, Setting(11)  },
        { ESchedule::DIPLOMACY,      "Diplomacy",      0,  0.1, 1, 0.05, Setting(12)  },
        { ESchedule::HISTORY,        "History",        0,  0.1, 1, 0.05, Setting(13)  },
        { ESchedule::THEOLOGY,       "Theology",       0,  0.1, 1, 0.05, Setting(14)  },
        { ESchedule::LAW,            "Law",            0,  0.1, 1, 0.05, Setting(15)  },
        { ESchedule::WALK,           "Walk",           0,  0.1, 1, 0.05, Setting(16)  },
        { ESchedule::SUBMISSION,     "Submission",     0,  0.1, 1, 0.05, Setting(17)  },
        { ESchedule::ARTVIEWING,     "ArtViewing",     0,  0.1, 1, 0.05, Setting(18)  },
        { ESchedule::GAMEWATCHING,   "GameWatching",   0,  0.1, 1, 0.05, Setting(19)  },
        { ESchedule::TRAVELMOUNTAIN, "TravelMountain", 0,  0.1, 1, 0.05, Setting(20)  },
        { ESchedule::TRAVELSEA,      "TravelSea",      0,  0.1, 1, 0.05, Setting(21)  },
    };
    for (auto p : scheduleParams)
        params.scheduleParams.push_back(p);

    return params;
}

int main () {
    auto params = LoadKingParameter();
    auto kingMaker = std::make_unique<CKingMaker>(params);
    InitializeScheduleTable(params.scheduleParams);
    ExecuteGame(std::move(kingMaker));
    return 0;
}
