#include "Geometry.h"

inline void Geometry::setNumVertexPositionElements(const int numVertexPositionElements) {
    m_numVertexPositionElements = numVertexPositionElements;
}

inline void Geometry::setNumColorElements(const int numColorElements) {
    m_numColorElements = numColorElements;
}

inline void Geometry::setNumTexCoordElements(const int numTexCoordElements) {
    m_numTexCoordElements = numTexCoordElements;
}