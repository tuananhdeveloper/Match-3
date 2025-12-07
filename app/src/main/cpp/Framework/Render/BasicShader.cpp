#include "BasicShader.h"
#include "cassert"

BasicShader::BasicShader() {
    m_vertexShaderCode =
            "attribute vec4 a_vPosition;\n"
            "void main() {\n"
            "   gl_Position = a_vPosition;\n"
            "}\n";

    m_fragmentShaderCode =
            "precision highp float;\n"
            "void main() {\n"
            "   gl_FragColor = vec4(0.2, 0.2, 0.2, 1.0);\n"
            "}\n";
}

void BasicShader::link() {
    Shader::link();
    m_positionAttributeHandle = glGetAttribLocation(m_programId, "a_vPosition");
}

void BasicShader::setup(Renderable& renderable) {
    Shader::setup(renderable);
    Geometry* geometry= renderable.getGeometry();
    assert(geometry);
    glVertexAttribPointer(
            m_positionAttributeHandle,
            geometry->getNumVertexPositionElements(),
            GL_FLOAT,
            GL_FALSE,
            geometry->getVertexStride(),
            geometry->getVertexBuffer());
    glEnableVertexAttribArray(m_positionAttributeHandle);
}