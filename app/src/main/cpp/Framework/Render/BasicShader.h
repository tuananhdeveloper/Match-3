#include "Shader.h"
#include "Renderable.h"

class BasicShader: public Shader {
private:
    GLint m_positionAttributeHandle;
public:
    BasicShader();
    virtual ~BasicShader();

    virtual void link();
    virtual void setup(Renderable& renderable);
};