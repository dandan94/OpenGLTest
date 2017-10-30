#ifndef ENTITY_H
#define ENTITY_H

#ifndef GLEW_STATIC
#define GLEW_STATIC
#include <GL/glew.h>
#endif

#include "glm/glm/glm.hpp"
#include "glm/glm/gtx/transform.hpp"
#include "glm/glm/gtc/type_ptr.hpp"

#include "Mesh.h"


class Entity
{
    public:
        virtual void update(GLfloat delta) = 0;
        virtual void render() = 0;
    protected:
    private:
};

#endif // ENTITY_H
