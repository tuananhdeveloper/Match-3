#include "Geometry.h"
#include "Shader.h"

class Renderable {
private:
    Geometry* m_geometry;
    Shader* m_shader;

public:
    Renderable();
    ~Renderable();

    void setGeometry(Geometry* geometry);
    Geometry* getGeometry();

    void setShader(Shader* shader);
    Shader* getShader();
};
