#version 330 core

in vec3 nor;
in vec2 uv;

out vec4 color;

uniform vec4 ourColor;
uniform sampler2D tex;

void main()
{
    color.rgb = ourColor.rgb + texture(tex, uv).rgb;
}
