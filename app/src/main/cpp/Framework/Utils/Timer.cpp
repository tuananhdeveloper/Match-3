#include "bits/timespec.h"
#include "linux/time.h"
#include "ctime"
#include "Timer.h"

namespace Framework {
    Timer::TimeUnits Timer::nanoTime() {
        timespec now{};
        return now.tv_sec * 1000000000 + now.tv_nsec;
    }

    bool Timer::start() {
        m_timeLastFrame = nanoTime();
        return true;
    }

    void Timer::onResume() {
        m_timeLastFrame = nanoTime();
    }

    void Timer::update() {
        TimeUnits currentTime = nanoTime();
        const float MULTIPLIER = 0.000000001f;
        m_frameDt = (float) (currentTime - m_timeLastFrame) * MULTIPLIER;
        m_timeLastFrame = currentTime;
        m_simDt = m_frameDt * m_simMultiplier;
    }
}