#include "Shader.h"
#include "string"

using namespace std;
void Shader::loadShader(GLuint id, string& shaderCode) {
    static const uint32_t NUM_SHADERS = 1;
    const GLchar* code = shaderCode.c_str();
    GLint length = shaderCode.length();
    glShaderSource(id, NUM_SHADERS, &code, &length);
    glCompileShader(id);
    glAttachShader(m_programId, id);
}

void Shader::link() {
    m_programId = glCreateProgram();
    m_vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    loadShader(m_vertexShaderId, m_vertexShaderCode);
    m_fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    loadShader(m_fragmentShaderId, m_fragmentShaderCode);
    glLinkProgram(m_programId);
    m_isLinked = true;
}

void Shader::setup(Renderable& renderable) {
    glUseProgram(m_programId);
}