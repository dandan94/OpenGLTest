#version 330 core

in vec3 nor;

out vec4 color;

uniform vec4 ourColor;

void main()
{
    color.rgb = 0.5 + 0.5 * nor;
}
