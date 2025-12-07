#include "Renderer.h"
#include "EGL/egl.h"
#include "cassert"

namespace Framework {
    bool Renderer::start() {
        return true;
    }

    void Renderer::init() {
        const EGLint attribs[] = {
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_BLUE_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_RED_SIZE, 8,
            EGL_NONE
        };

        EGLint format;
        EGLint numConfigs;
        EGLConfig config;

        m_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        eglInitialize(m_display, nullptr, nullptr);
        eglChooseConfig(m_display,attribs,&config,1,&numConfigs);
        eglGetConfigAttrib(m_display, config, EGL_NATIVE_VISUAL_ID, &format);
        ANativeWindow_setBuffersGeometry(m_state->window, 0, 0, format);
        m_surface = eglCreateWindowSurface(m_display, config, m_state->window, nullptr);
        EGLint contextAttribs[] = {
                EGL_CONTEXT_CLIENT_VERSION, 2,
                EGL_NONE
        };
        m_context = eglCreateContext(m_display, config, nullptr, contextAttribs);
        eglMakeCurrent(m_display, m_surface, m_surface, m_context);
        eglQuerySurface(m_display, m_surface, EGL_WIDTH, &m_width);
        eglQuerySurface(m_display, m_surface, EGL_HEIGHT, &m_height);
        m_initialized = true;
    }

    void Renderer::destroy() {
        m_initialized = false;

        if (m_display != EGL_NO_DISPLAY) {
            eglMakeCurrent(m_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
            if (m_context != EGL_NO_CONTEXT) {
                eglDestroyContext(m_display, m_context);
            }
            if (m_surface != EGL_NO_SURFACE) {
                eglDestroySurface(m_display, m_surface);
            }
            eglTerminate(m_display);
        }
        m_display = EGL_NO_DISPLAY;
        m_context = EGL_NO_CONTEXT;
        m_surface = EGL_NO_SURFACE;
    }

    void Renderer::addRenderable(Renderable* renderable) {
        m_renderables.push_back(renderable);
    }

    void Renderer::removeRenderable(Renderable* renderable) {
        for (RenderableVectorIterator it = m_renderables.begin();
            it != m_renderables.end(); ++it) {
            Renderable* current = *it;
            if (current == renderable) {
                m_renderables.erase(it);
                break;
            }
        }
    }

    void Renderer::update() {
        if (m_initialized) {
            glClearColor(0.95f, 0.95f, 0.95f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            for (RenderableVectorIterator it = m_renderables.begin();
                it != m_renderables.end(); ++it) {
                Renderable* renderable = *it;
                if (renderable) {
                    draw(renderable);
                }
            }

            eglSwapBuffers(m_display, m_surface);
        }
    }

    void Renderer::draw(Renderable* renderable) {
        assert(renderable);
        if (renderable) {
            Geometry* geometry = renderable->getGeometry();
            Shader* shader = renderable->getShader();
            assert(shader && geometry);
            shader->setup(*renderable);
            glDrawElements(
                    GL_TRIANGLES,
                    geometry->getNumIndices(),
                    GL_UNSIGNED_SHORT,
                    geometry->getIndexBuffer());
        }
    }
}