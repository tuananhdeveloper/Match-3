#include <android_native_app_glue.h>
#include "Framework/Kernel/Task.h"
#include "EGL/egl.h"
#include "Renderable.h"
#include "vector"

namespace Framework {
    class Renderer: public Task {
    private:
        android_app* m_state;
        EGLDisplay m_display;
        EGLContext m_context;
        EGLSurface m_surface;
        int m_width;
        int m_height;
        bool m_initialized;

        typedef std::vector<Renderable*> RenderableVector;
        typedef RenderableVector::iterator RenderableVectorIterator;
        RenderableVector m_renderables;

        void draw(Renderable* renderable);

    public:
        explicit Renderer(android_app* state, const unsigned int priority);
        virtual ~Renderer();

        void init();
        void destroy();
        void addRenderable(Renderable* renderable);
        void removeRenderable(Renderable* renderable);

        virtual bool start();
        virtual void onSuspend();
        virtual void update();
        virtual void onResume();
        virtual void stop();

        bool isInitialized() {
            return m_initialized;
        }
    };
}
