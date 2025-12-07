#include "android_native_app_glue.h"
#include "Framework/Application/Application.h"

void android_main(struct android_app* state) {
    Framework::Application app(state);

    if (app.initialize()) {
        app.run();
    }
}