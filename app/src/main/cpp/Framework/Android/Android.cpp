#include "Android.h"

namespace Framework {
    bool Android::m_closing = false;
    bool Android::m_paused = false;

    static void android_handle_cmd(struct android_app* app, int32_t cmd) {
        switch (cmd) {
            case APP_CMD_RESUME: {
                Android::setPaused(false);
            }
                break;
            case APP_CMD_PAUSE: {
                Android::setPaused(true);
            }
                break;
        }
    }

    Android::Android(android_app *state, unsigned int priority): Task(priority) {
        m_state = state;
        m_state->onAppCmd = android_handle_cmd;
    }

    Android::~Android() {

    }

    bool Android::start() {
        return true;
    }

    void Android::onSuspend() {

    }

    void Android::update() {
        int events;
        struct android_poll_source* source;
        int ident = ALooper_pollOnce(0, 0, &events, (void**)&source);
        if (ident >= 0) {
            if (source) {
                source->process(m_state, source);
            }

            if (m_state->destroyRequested) {
                m_closing = true;
            }
        }
    }

    void Android::onResume() {

    }

    void Android::stop() {

    }
}