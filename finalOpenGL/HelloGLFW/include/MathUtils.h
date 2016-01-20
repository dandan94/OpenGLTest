#ifndef MATHUTILS_H
#define MATHUTILS_H

#define GLEW_STATIC
#include <GL/glew.h>

#include "glm/glm/glm.hpp"
#include "glm/glm/gtx/transform.hpp"
#include "glm/glm/gtc/type_ptr.hpp"
#include <math.h>
#include <iostream>

class MathUtils
{
    public:
        static glm::mat4 createTransformationMatrix(glm::vec3 translation, glm::vec3 rotation, GLfloat scale);
        static GLfloat* convertMatrixToArray(glm::mat4 matrix);
    protected:
    private:
};

#endif // MATHUTILS_H
