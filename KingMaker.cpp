#include <iostream>
#include <vector>
#include <cassert>
#include <random>
#include "KingMaker.h"
#include "Schedule.h"

static void GetSchedules (std::vector<std::shared_ptr<ISchedule>> & schedules) {
    // TODO: get schedules
    schedules.push_back(GetSchedule("EducationArtDrawing"));
    schedules.push_back(GetSchedule("RestWalk"));
    schedules.push_back(GetSchedule("EducationArtLiterature"));
    schedules.push_back(GetSchedule("EducationArtDelicacies"));
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

static EResult CalculateScheduleResult (std::shared_ptr<ISchedule> schedule) {
    EResult result{EResult::FAIL};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1,10000);

    if (schedule->GetSuccessRate() > dis(gen)) {
        if (schedule->GetCriticalSuccessRate() > dis(gen))
            result = EResult::CRITICAL_SUCCESS;
        else
            result = EResult::SUCCESS;
    }

    return result;
}

void CKingMaker::Schedule () {
    std::vector<std::shared_ptr<ISchedule>> schedules;
    GetSchedules(schedules);
    assert(schedules.size() == 4);

    std::cout<<"Scheduling...\n";
    for (auto schedule : schedules) {
        for (unsigned i = 0; i < 7; i++) {
            EResult result = CalculateScheduleResult(schedule);
            UpdateParameters(schedule, result);

            std::cout<<"Day of "<<i+1<<"...";
            std::cout<<"Id : "<<schedule->GetId()<<",";
            std::cout<<"Category : "<<int(schedule->GetCategory())<<",";
            std::cout<<"Result : "<<ResultToStr(result)<<"\n";
        }
    }
}

void CKingMaker::UpdateParameters (
    std::shared_ptr<ISchedule> schedule,
    EResult                    result
) {
    if (result == EResult::FAIL)
        return;

    if (result == EResult::SUCCESS) {

    } else {

    }
}

void ExecuteGame (std::unique_ptr<CKingMaker> kingMaker) {
    kingMaker->Schedule();
    kingMaker->Inventory();
    kingMaker->Call();
    kingMaker->LiegeManagement();
    kingMaker->Shop();
}
