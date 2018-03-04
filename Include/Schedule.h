#pragma once

#include <string>
#include <vector>
#include <memory>
#include "KingParameter.h"

enum class EScheduleResult {
    SUCCESS,
    CRITICAL_SUCCESS,
    FAIL
};

class ISchedule {
public:
    virtual ~ISchedule () {}

    virtual EScheduleResult DoSchedule () const = 0;

    virtual std::string GetId () const = 0;
    virtual ECategory GetCategory () const = 0;
    virtual double GetRiseRate () const = 0;
    virtual const std::vector<ScheduleStat> & GetStats () const = 0;
};

class IScheduleNotify {
public:
    virtual void OnScheduleCompleted (
        std::shared_ptr<ISchedule> schedule,
        EScheduleResult            result
    ) = 0;
};

void LoadSchedules ();
std::shared_ptr<ISchedule> GetSchedule (std::string scheduleId);
