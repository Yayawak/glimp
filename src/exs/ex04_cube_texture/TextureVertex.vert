#version 330 core

// layout(location = 0) in vec3 vertexPos_modelspace;
layout(location = 0) in vec3 vertexPos;
layout(location = 1) in vec2 vertexUV;

out vec2 UV;

// stay constant
uniform mat4 cam;
uniform mat4 MVP;

void main()
{
    // clip space -> mvp * position;
    // gl_Position = MVP * vec4(vertexPos_modelspace, 1);
    gl_Position = MVP * vec4(vertexPos.x, vertexPos.y, sin(vertexPos.z), 1);
    // gl_Position = cam * vec4(vertexPos_modelspace, 1.0f);

    UV = vertexUV;
}
