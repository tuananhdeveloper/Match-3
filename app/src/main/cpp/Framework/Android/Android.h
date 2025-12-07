#ifndef ANDROID_H_
#define ANDROID_H_

#include "android_native_app_glue.h"
#include "Framework/Kernel/Task.h"

namespace Framework {
    class Android: public Task {
    private:
        static bool m_closing;
        static bool m_paused;
        android_app* m_state;

    public:
        Android(android_app* state, unsigned int priority);
        virtual ~Android();

        android_app* getAppState() {
            return m_state;
        }

        virtual bool start();
        virtual void onSuspend();
        virtual void update();
        virtual void onResume();
        virtual void stop();

        static void clearClosing() {
            m_closing = true;
        }

        static bool isClosing() {
            return m_closing;
        }

        static void setPaused(const bool paused) {
            m_paused = paused;
        }

        static bool isPaused() {
            return m_paused;
        }
    };
}

#endif // ANDROID_H_