#include <vector>
#include <cassert>
#include <cmath>
#include "KingMaker.h"
#include "Schedule.h"
#include "Liege.h"

//=============================================================================
void CKingMaker::Schedule (
    std::vector<std::shared_ptr<ISchedule>> schedules,
    std::shared_ptr<IScheduleNotify>        notify
) {
    assert(schedules.size() == 4);

    for (auto schedule : schedules) {
        for (unsigned i = 0; i < 7; i++) {
            EScheduleResult result = schedule->DoSchedule();
            UpdateParameters(schedule, result);
            notify->OnScheduleCompleted(schedule, result);
        }
    }
}

//=============================================================================
void CKingMaker::UpdateParameters (
    std::shared_ptr<ISchedule> schedule,
    EScheduleResult            result
) {
    if (result == EScheduleResult::FAIL)
        return;

    unsigned riseFactor = 1;
    if (result == EScheduleResult::CRITICAL_SUCCESS)
        riseFactor = 2;

    auto & stats = schedule->GetStats();
    for (auto & stat : stats) {
        double delta = 0;
        if (stat.value < 0) {
            delta = stat.value;
        } else {
            delta = std::round(
                stat.value * (1+schedule->GetRiseRate()/1000) * riseFactor
            );
        }
        auto found = m_params->kingStats.find(stat.name);
        assert(found != m_params->kingStats.end());
        found->second += delta;
    }
}

//=============================================================================
void CKingMaker::LiegeMeeting (
    std::vector<std::shared_ptr<ILiege>> lieges,
    std::shared_ptr<ILiegeNotify>        notify
) {
    assert(lieges.size() <= 6);

    for (auto liege : lieges) {
        ELiegeResult result = liege->DoMeeting();
        UpdateParameters(liege, result);
        notify->OnLiegeMeetingCompleted(liege, result);
    }
}

//=============================================================================
void CKingMaker::UpdateParameters (
    std::shared_ptr<ILiege> liege,
    ELiegeResult            result
) {
    auto & liegeStats = liege->GetStats();
    assert(liegeStats.size() <= 3);

    for (auto & liegeStat : liegeStats) {
        if (result == ELiegeResult::FAIL)
            continue;

        if (result == ELiegeResult::SUCCESS) {
            auto stats = GetStats(liegeStat.type);
            for (auto stat : stats) {
                double delta = 0;
                if (stat.value < 0) {
                    delta = std::round(stat.value * liegeStat.value);
                } else {
                    auto develop = m_params->developRates.find(stat.name);
                    assert(develop != m_params->developRates.end());
                    double developRate = develop->second;
                    delta = std::round(
                        stat.value * liegeStat.value * (1+developRate/10000)
                    );
                }
                auto found = m_params->countryStats.find(stat.name);
                assert(found != m_params->countryStats.end());
                found->second += delta;
            }
        } else if (result == ELiegeResult::GREAT_SUCCESS) {
            auto stats = GetStats(liegeStat.type);
            for (auto stat : stats) {
                double delta = 0;
                if (stat.value < 0) {
                    delta = stat.value;
                } else {
                    auto develop = m_params->developRates.find(stat.name);
                    assert(develop != m_params->developRates.end());
                    double developRate = develop->second;
                    delta = std::round(
                        stat.value * (1+developRate/1000) * (1+liege->GetBonusCriticalPower()/10000)
                    );
                }
                auto found = m_params->countryStats.find(stat.name);
                assert(found != m_params->countryStats.end());
                found->second += delta;
            }
        } else if (result == ELiegeResult::MONEY_EVASION) {
            auto found = m_params->countryStats.find("stateCoffers");
            assert(found != m_params->countryStats.end());
            found->second -= liege->GetSelfishness();
        }
    }
}
