#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

uniform mat4 transform;
uniform mat4 projection;

out vec3 nor;

void main()
{
    nor = normal;
    gl_Position = projection * transform * vec4(position, 1.0);
}
