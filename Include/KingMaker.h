#pragma once

#include "KingParameter.h"
#include "Schedule.h"
#include "Liege.h"

class CKingMaker {
public:
    CKingMaker (std::shared_ptr<KingParameter> params) : m_params(params) {}
    ~CKingMaker () {}

    void Schedule (
        std::vector<std::shared_ptr<ISchedule>> schedules,
        std::shared_ptr<IScheduleNotify>        notify
    );
    void Inventory () {}
    void Call () {}
    void LiegeMeeting (
        std::vector<std::shared_ptr<ILiege>> lieges,
        std::shared_ptr<ILiegeNotify>        notify
    );
    void Shop () {}

private:
    void UpdateParameters (
        std::shared_ptr<ISchedule> schedule,
        EScheduleResult            result
    );
    void UpdateParameters (
        std::shared_ptr<ILiege> schedule,
        ELiegeResult            result
    );

    std::shared_ptr<KingParameter> m_params;
};
