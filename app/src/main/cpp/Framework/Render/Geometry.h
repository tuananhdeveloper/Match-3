#include "string.h"

class Geometry {
private:
    static const unsigned int NAME_MAX_LENGTH = 16;
    char m_name[NAME_MAX_LENGTH];
    int m_numVertices;
    int m_numIndices;
    void* m_vertices;
    void* m_indices;
    int m_numVertexPositionElements;
    int m_numColorElements;
    int m_numTexCoordElements;
    int m_vertexStride;

public:
    Geometry();
    virtual ~Geometry();

    void setName(const char* name) {
        strcpy(m_name, name);
    }

    void setNumVertices(const int numVertices) {
        m_numVertices = numVertices;
    }

    void setNumIndices(const int numIndices) {
        m_numIndices = numIndices;
    }

    const char* getName() const {
        return m_name;
    }

    const int getNumVertices() const {
        return m_numVertices;
    }

    const int getNumIndices() const {
        return m_numIndices;
    }

    void* getVertexBuffer() const {
        return m_vertices;
    }

    void* getIndexBuffer() const {
        return m_indices;
    }

    void setVertexBuffer(void* vertices) {
        m_vertices = vertices;
    }

    void setIndexBuffer(void* indices) {
        m_indices = indices;
    }

    void setNumVertexPositionElements(const int numVertexPositionElements);

    int getNumVertexPositionElements() const {
        return m_numVertexPositionElements;
    }

    void setNumColorElements(const int numColorElements);

    int getNumColorElements() const {
        return m_numColorElements;
    }

    void setNumTexCoordElements(const int numTexCoordElements);

    int getNumTexCoordElements() const {
        return m_numTexCoordElements;
    }

    void setVertexStride(const int vertexStride) {
        m_vertexStride = vertexStride;
    }

    int getVertexStride() const {
        return m_vertexStride;
    }
};