#include "Kernel.h"
#include "Framework/Android/Android.h"

namespace Framework {
    Kernel::Kernel() {

    }

    Kernel::~Kernel() {

    }

    void Kernel::priorityAdd(Task* task) {
        TaskListIterator iterator;
        for (iterator = m_tasks.begin(); iterator != m_tasks.end(); ++iterator) {
            Task* currentTask = (*iterator);
            if (currentTask->priority() > task->priority()) {
                break;
            }
        }
        m_tasks.insert(iterator, task);
    }

    bool Kernel::addTask(Task* task) {
        bool started = task->start();
        if (started) {
            priorityAdd(task);
        }
        return started;
    }

    void Kernel::removeTask(Task* task) {
        if (std::find(m_tasks.begin(), m_tasks.end(), task) != m_tasks.end()) {
            task->setCanKill(true);
        }
    }

    void Kernel::suspendTask(Task* task) {
        if (std::find(m_tasks.begin(), m_tasks.end(), task) != m_tasks.end()) {
            task->onSuspend();
            m_tasks.remove(task);
            m_pausedTasks.push_back(task);
        }
    }

    void Kernel::resumeTask(Task* task) {
        if (std::find(m_pausedTasks.begin(), m_pausedTasks.end(), task) != m_tasks.end()) {
            task->onResume();
            m_pausedTasks.remove(task);
            priorityAdd(task);
        }
    }

    void Kernel::killAllTasks() {
        for (TaskListIterator iterator = m_tasks.begin(); iterator != m_tasks.end(); ++iterator) {
            (*iterator)->setCanKill(true);
        }
    }

    void Kernel::execute() {
        while (!m_tasks.empty()) {
            if (Android::isClosing()) {
                killAllTasks();
            }
            TaskListIterator iterator;
            for (iterator = m_tasks.begin(); iterator != m_tasks.end(); ++iterator) {
                Task* task = (*iterator);
                if (!task->canKill()) {
                    task->update();
                }
                else {
                    task->stop();
                    m_tasks.remove(task);
                    task = nullptr;
                }
            }
        }
        Android::clearClosing();
    }
}