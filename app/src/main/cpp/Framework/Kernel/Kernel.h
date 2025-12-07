#ifndef KERNEL_H_
#define KERNEL_H_

#include "list"
#include "Task.h"

namespace Framework {
    class Kernel {
    private:
        typedef std::list<Task*> TaskList;
        typedef std::list<Task*>::iterator TaskListIterator;

        TaskList m_tasks;
        TaskList m_pausedTasks;

        void priorityAdd(Task* task);

    public:
        Kernel();
        virtual ~Kernel();

        void execute();
        bool addTask(Task* task);
        void suspendTask(Task* task);
        void resumeTask(Task* task);
        void removeTask(Task* task);
        void killAllTasks();

        bool hasTasks() {
            return m_tasks.size();
        }
    };
}

#endif // KERNEL_H_