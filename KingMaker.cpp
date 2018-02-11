#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include "KingMaker.h"
#include "Schedule.h"

static void GetSchedules (std::vector<std::shared_ptr<ISchedule>> & schedules) {
    // TODO: get schedules
    schedules.push_back(GetSchedule("EducationArtDrawing"));
    schedules.push_back(GetSchedule("RestWalk"));
    schedules.push_back(GetSchedule("EducationArtLiterature"));
    schedules.push_back(GetSchedule("EducationArtDelicacies"));
}

static std::string CategoryToStr (ECategory category) {
    switch (category) {
        case ECategory::ART:
            return "Art";
        case ECategory::MILITARY:
            return "Military";
        case ECategory::INTELLECTUAL:
            return "Intellectual";
        case ECategory::REST:
            return "Rest";
    }
}

static std::string ResultToStr (EResult result) {
    switch (result) {
        case EResult::SUCCESS:
            return "success";
        case EResult::CRITICAL_SUCCESS:
            return "critical success";
        case EResult::FAIL:
            return "fail";
    }
}

void CKingMaker::Schedule () {
    std::vector<std::shared_ptr<ISchedule>> schedules;
    GetSchedules(schedules);
    assert(schedules.size() == 4);

    std::cout<<"Scheduling...\n";
    for (auto schedule : schedules) {
        for (unsigned i = 0; i < 7; i++) {
            EResult result = schedule->DoSchedule();
            UpdateParameters(schedule, result);

            std::cout<<"Day of "<<i+1<<"..., ";
            std::cout<<"Id: "<<schedule->GetId()<<", ";
            std::cout<<"Category: "<<CategoryToStr(schedule->GetCategory())<<", ";
            std::cout<<"Result: "<<ResultToStr(result)<<"\n";
            DebugDisplay(m_params.stats);
        }
    }
}

void CKingMaker::UpdateParameters (
    std::shared_ptr<ISchedule> schedule,
    EResult                    result
) {
    if (result == EResult::FAIL)
        return;

    unsigned riseFactor = 1;
    if (result == EResult::CRITICAL_SUCCESS)
        riseFactor = 2;

    auto stats = schedule->GetStats();
    for (auto & stat : stats) {
        double delta = 0;
        if (stat.value < 0) {
            delta = stat.value;
        } else {
            delta = std::round(stat.value * (1+schedule->GetRiseRate()/1000) * riseFactor);
        }
        auto found = m_params.stats.find(stat.name);
        assert(found != m_params.stats.end());
        found->second += delta;
    }
}

void ExecuteGame (std::unique_ptr<CKingMaker> kingMaker) {
    kingMaker->Schedule();
    kingMaker->Inventory();
    kingMaker->Call();
    kingMaker->LiegeManagement();
    kingMaker->Shop();
}
