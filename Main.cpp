#include <memory>
#include "KingParameter.h"
#include "Schedule.h"
#include "KingMaker.h"

KingParameter LoadKingParameter () {
    KingParameter params;
    return params;
}

int main () {
    auto params = LoadKingParameter();
    auto kingMaker = std::make_unique<CKingMaker>(params);
    kingMaker->Execute();
    return 0;
}
