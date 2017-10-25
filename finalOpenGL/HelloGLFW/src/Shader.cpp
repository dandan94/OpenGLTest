#include "Shader.h"

Shader::Shader(const std::string &fileName)
{
    //Reading shader from files
    std::string vertexShaderSource = FileUtils::read_file(fileName + ".vs");
    std::string fragmentShaderSource = FileUtils::read_file(fileName + ".fs");

    //Compiling shaders
    vertexShader = Shader::compileShader(vertexShaderSource, GL_VERTEX_SHADER);
    fragmentShader = Shader::compileShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

    compileProgram();
}

Shader::~Shader()
{
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glDeleteProgram(shaderProgram);
}

void Shader::Bind()
{
    glUseProgram(shaderProgram);
}

void Shader::compileProgram()
{
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}


GLuint Shader::compileShader(std::string shaderSource, GLenum shaderType)
{
    GLuint shader;

    const GLchar* shaderSourceC = shaderSource.c_str();

    shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSourceC, NULL);
    glCompileShader(shader);


    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);

        if(shaderType == GL_VERTEX_SHADER)
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        else if(shaderType == GL_FRAGMENT_SHADER)
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    return shader;
}

GLint Shader::getUniformLocation(std::string attrName)
{
    Bind();
    return glGetUniformLocation(shaderProgram, attrName.c_str());
}

void Shader::setUniform1i(std::string attrName, GLuint attrValue)
{
    GLint attrLocation = getUniformLocation(attrName);
    glUniform1i(attrLocation, attrValue);
}

void Shader::setUniform2f(std::string attrName, glm::vec2 attrValue)
{
    GLint attrLocation = getUniformLocation(attrName);
    glUniform2f(attrLocation, attrValue.x, attrValue.y);
}

void Shader::setUniform3f(std::string attrName, glm::vec3 attrValue)
{
    GLint attrLocation = getUniformLocation(attrName);
    glUniform3f(attrLocation, attrValue.x, attrValue.y, attrValue.z);
}

void Shader::setUniform4f(std::string attrName, glm::vec4 attrValue)
{
    GLint attrLocation = getUniformLocation(attrName);
    glUniform4f(attrLocation, attrValue.x, attrValue.y, attrValue.z, attrValue.w);
}

void Shader::setUniformMat4f(std::string attrName, glm::mat4 attrValue)
{
    GLint attrLocation = getUniformLocation(attrName);

    glUniformMatrix4fv(attrLocation, 1, GL_FALSE, glm::value_ptr(attrValue));
}
