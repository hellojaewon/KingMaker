#include <string>
#include <memory>
#include "KingParameter.h"
#include "Schedule.h"
#include "KingMaker.h"

static KingParameter LoadKingParameter () {
    KingParameter params;

    // scheduleParams
    ScheduleParam scheduleParams[] = {
        { "Painting",    0,  0.1, 1, 0.05   },
        { "Music",       0,  0.1, 1, 0.05   },
        { "Literature",  0,  0.1, 1, 0.05   },
        { "Gourmet",     0,  0.1, 1, 0.05   },
        { "Swords",      0,  0.1, 1, 0.05   },
        { "BlackMagic",  0,  0.1, 1, 0.05   },
        { "WhiteMagic",  0,  0.1, 1, 0.05   },
        { "Science",     0,  0.1, 1, 0.05   },
        { "Military",    0,  0.1, 1, 0.05   },
        { "Social",      0,  0.1, 1, 0.05   },
        { "Economy",     0,  0.1, 1, 0.05   },
        { "Agriculture", 0,  0.1, 1, 0.05   },
        { "Diplomacy",   0,  0.1, 1, 0.05   },
        { "History",     0,  0.1, 1, 0.05   },
        { "Theology",    0,  0.1, 1, 0.05   },
        { "Law",         0,  0.1, 1, 0.05   }
    };
    for (auto p : scheduleParams)
        params.scheduleParams.push_back(p);

    return params;
}

int main () {
    auto params = LoadKingParameter();
    auto kingMaker = std::make_unique<CKingMaker>(params);
    ExecuteGame(std::move(kingMaker));
    return 0;
}
