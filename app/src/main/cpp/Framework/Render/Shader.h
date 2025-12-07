#include "GLES2/gl2.h"
#include "GLES/gl.h"
#include "string"

using namespace std;
class Shader {
private:
    void loadShader(GLenum shaderType, string& shaderCode);
protected:
    GLuint m_vertexShaderId;
    GLuint m_fragmentShaderId;
    GLuint m_programId;

    string m_vertexShaderCode;
    string m_fragmentShaderCode;

    bool m_isLinked;

public:
    Shader();
    virtual ~Shader();

    virtual void link();
    virtual void setup(Renderable& renderable);

    bool isLinked() {
        return m_isLinked;
    }
};