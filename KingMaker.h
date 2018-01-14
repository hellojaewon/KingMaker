#pragma once

class CKingMaker {
public:
    CKingMaker (const KingParameter & params) : m_params(params) {}
    void Execute () {}

private:
    KingParameter m_params;
};
