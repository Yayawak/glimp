#version 330 core

layout (location = 0) in vec3 position;
// layout (location = 1) in vec3 color;
layout (location = 1) in vec2 aTex;

// out vec3 Color;
out vec2 texCoord;
uniform float scale;

void main()
{
    // Color = color;
    texCoord = aTex;
    gl_Position = vec4(position, 1.0f);
}