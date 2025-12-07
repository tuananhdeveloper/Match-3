#ifndef TASK_H_
#define TASK_H_

namespace Framework {
    class Task {
    private:
        unsigned int m_priority;
        bool m_canKill;

    public:
        explicit Task(const unsigned int priority);
        virtual ~Task();

        virtual bool start() = 0;
        virtual void onSuspend() = 0;
        virtual void update() = 0;
        virtual void onResume() = 0;
        virtual void stop() = 0;

        void setCanKill(const bool canKill);
        bool canKill() const;
        unsigned int priority() const;

        static const unsigned int PLATFORM_PRIORITY = 1000;
    };

    inline Task::Task(const unsigned int priority) {
        m_priority = priority;
        m_canKill = false;
    }

    inline Task::~Task() {

    }

    inline void Task::setCanKill(const bool canKill) {
        m_canKill = canKill;
    }

    inline bool Task::canKill() const {
        return m_canKill;
    }

    inline unsigned int Task::priority() const {
        return m_priority;
    }
}

#endif // TASK_H_