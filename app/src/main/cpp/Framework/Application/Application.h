#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Framework/Kernel/Kernel.h"
#include "Framework/Android/Android.h"

namespace Framework {
    class Application {
    private:
        Kernel m_kernel;
        Android m_androidTask;

    public:
        Application(android_app* state);
        virtual ~Application();

        bool initialize();
        void run();
    };
}

#endif // APPLICATION_H_