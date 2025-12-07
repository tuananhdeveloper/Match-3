#include "Application.h"

namespace Framework {
    Application::Application(android_app* state): m_androidTask(state, Task::PLATFORM_PRIORITY) {

    }

    Application::~Application() {

    }

    bool Application::initialize() {
        bool ret = true;
        m_kernel.addTask(&m_androidTask);
        return ret;
    }

    void Application::run() {
        m_kernel.execute();
    }
}