#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <iostream>
#include <fstream>
#include "FileUtils.h"
#include <GL/glew.h>
#include "glm/glm/glm.hpp"
#include "MathUtils.h"

class Shader
{
    private:
        GLuint shaderProgram, vertexShader, fragmentShader;
    public:
        Shader(const std::string &fileName);
        virtual ~Shader();
    protected:
    private:
        GLuint compileShader(std::string shaderSource, GLuint shaderType);
        void compileProgram();
        GLint getUniformLocation(std::string attrName);
    public:
        void Bind();
        void setUniform1i(std::string attrName, GLuint attrValue);
        void setUniform2f(std::string attrName, glm::vec2 attrValue);
        void setUniform3f(std::string attrName, glm::vec3 attrValue);
        void setUniform4f(std::string attrName, glm::vec4 attrValue);
        void setUniformMat4f(std::string attrName, glm::mat4 attrValue);
};

#endif // SHADER_H
