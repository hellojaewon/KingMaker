#pragma once

#include <string>
#include <vector>
#include <memory>
#include "KingParameter.h"

enum class EResult {
    SUCCESS,
    CRITICAL_SUCCESS,
    FAIL
};

// Interface
class ISchedule {
public:
    virtual ~ISchedule () {}

    virtual EResult DoSchedule () const = 0;

    virtual std::string GetId () const = 0;
    virtual ECategory GetCategory () const = 0;
    virtual double GetRiseRate () const = 0;
    virtual const std::vector<ScheduleStat> & GetStats () const = 0;
};

void LoadSchedules ();
std::shared_ptr<ISchedule> GetSchedule (std::string scheduleId);
