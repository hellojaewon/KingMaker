#pragma once

#include "KingParameter.h"
#include "Schedule.h"

class CKingMaker {
public:
    CKingMaker (const KingParameter & params) : m_params(params) {}
    ~CKingMaker () {}

    void Schedule ();
    void Inventory () {}
    void Call () {}
    void LiegeManagement () {}
    void Shop () {}

private:
    void UpdateParameters (
        std::shared_ptr<ISchedule> schedule,
        EResult                    result
    );

    KingParameter m_params;
};

void ExecuteGame (std::unique_ptr<CKingMaker> kingMaker);
