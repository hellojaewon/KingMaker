#pragma once

#include "KingParameter.h"

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
    KingParameter m_params;
};

void ExecuteGame (std::unique_ptr<CKingMaker> kingMaker);
