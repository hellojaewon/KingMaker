#pragma once

#include <string>
#include <vector>
#include <memory>
#include "KingParameter.h"

enum class ECategory {
    ART,
    MILITARY,
    POLITICS,
    REST
};

enum class EResult {
    SUCCESS,
    CRITICAL_SUCCESS,
    FAIL
};

// Interface
class ISchedule {
public:
    ISchedule (const ScheduleParam & param)
     : m_successRate(param.successRate)
     , m_criticalSuccessRate(param.criticalSuccessRate)
    {}
    virtual std::string GetId () = 0;
    virtual ECategory GetCategory () = 0;
    double GetSuccessRate () { return m_successRate; }
    double GetCriticalSuccessRate () { return m_criticalSuccessRate; }
    ScheduleSetting GetScheduleSetting () { return m_scheduleSetting; }

protected:
    double          m_successRate;
    double          m_criticalSuccessRate;
    ScheduleSetting m_scheduleSetting;
};

void InitializeScheduleTable (std::vector<ScheduleParam> & schedule);
std::shared_ptr<ISchedule> GetSchedule (std::string scheduleId);
