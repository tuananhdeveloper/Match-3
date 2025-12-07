#include "Renderable.h"

inline Renderable::Renderable(): m_geometry(nullptr), m_shader(nullptr) {

}

inline Renderable::~Renderable() {

}

inline void Renderable::setGeometry(Geometry* geometry) {
    m_geometry = geometry;
}

inline Geometry* Renderable::getGeometry() {
    return m_geometry;
}

inline void Renderable::setShader(Shader* shader) {
    m_shader = shader;
}

inline Shader* Renderable::getShader() {
    return m_shader;
}