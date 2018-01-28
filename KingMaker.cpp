#include <iostream>
#include <vector>
#include "KingMaker.h"
#include "Schedule.h"

void CKingMaker::Schedule () {
    // TODO: get schedules
    std::vector<std::shared_ptr<ISchedule>> schedules;
    schedules.push_back(GetSchedule("EducationArtDrawing"));
    schedules.push_back(GetSchedule("EducationArtMusic"));
    schedules.push_back(GetSchedule("EducationArtLiterature"));
    schedules.push_back(GetSchedule("EducationArtDelicacies"));
    std::cout<<"Scheduling...\n";
    for (auto schedule : schedules) {
        std::cout<<"Id : "<<schedule->GetId()<<",";
        std::cout<<"Category : "<<int(schedule->GetCategory())<<",";
        std::cout<<"Result : "<<schedule->DoSchedule(m_params.scheduleParams)<<"\n";
    }
}

void ExecuteGame (std::unique_ptr<CKingMaker> kingMaker) {
    kingMaker->Schedule();
    kingMaker->Inventory();
    kingMaker->Call();
    kingMaker->LiegeManagement();
    kingMaker->Shop();
}
