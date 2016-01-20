#include "MathUtils.h"
void displayMatrix(glm::mat4 matrix)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            std::cout<<matrix[j][i]<<" ";
        }
        std::cout<<std::endl;
    }
}

glm::mat4 MathUtils::createTransformationMatrix(glm::vec3 translation, glm::vec3 rotation, GLfloat scale)
{
    glm::mat4 finalMatrix;

    finalMatrix = glm::translate(finalMatrix, translation);
    finalMatrix = glm::rotate(finalMatrix, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    finalMatrix = glm::rotate(finalMatrix, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    finalMatrix = glm::rotate(finalMatrix, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

    finalMatrix = glm::scale(finalMatrix, glm::vec3(scale, scale, scale));

    return finalMatrix;
}
