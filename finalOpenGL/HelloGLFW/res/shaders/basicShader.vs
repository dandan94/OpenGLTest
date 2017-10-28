#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

uniform mat4 model;
uniform mat4 camera;

out vec3 nor;
out vec2 uv;

void main()
{
    nor = normal;
    uv = texCoord;
    gl_Position = camera * model * vec4(position, 1.0);
}
