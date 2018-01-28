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


// Interface
class ISchedule {
public:
    virtual std::string GetId () = 0;
    virtual ECategory GetCategory () = 0;
    virtual bool DoSchedule (std::vector<ScheduleParam> & params) = 0;
};

std::shared_ptr<ISchedule> GetSchedule (std::string scheduleId);
