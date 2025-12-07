#include "Framework/Kernel/Task.h"

namespace Framework {
    class Timer: public Task {
    public:
        typedef long long TimeUnits;

    private:
        TimeUnits nanoTime();
        TimeUnits m_timeLastFrame;

        float m_frameDt;
        float m_simDt;
        float m_simMultiplier;

    public:
        Timer(const unsigned int priority);
        ~Timer();

        float getTimeFrame() const;
        float getTimeSim() const;
        void setSimMultiplier(const float simMultiplier);

        virtual bool start();
        virtual void onSuspend();
        virtual void update();
        virtual void onResume();
        virtual void stop();
    };
}