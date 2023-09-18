#version 330 core

layout (location = 0) in vec3 position;
// layout (location = 1) in vec3 color;
// layout (location = 2) in vec2 aTex;

// out vec3 Color;
// out vec2 texCoord;
uniform vec3 scaleVec;


// "uniform mat4 view;\n"
// "uniform mat4 proj;\n"
uniform mat4 transf;
uniform mat4 camMatrix;

void main()
{
// "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    // Color = color;
    // texCoord = aTex;
// "   Color = sin(color);\n"
// "   Color = vec3(sin(color.x), color.y, color.z);\n"
// "   gl_Position = proj * view * trans * vec4(position, 1.0f);\n"
// "   gl_Position = camMatrix * vec4(position, 1.0f);\n"
    // gl_Position = transf * camMatrix * vec4(position, 1.0f);
    // gl_Position = transf *  vec4(position, 1.0f);
    // gl_Position = vec4(position, 1.0f);
    gl_Position = transf * camMatrix * vec4(position, 1.0f);
    // gl_Position = transf * camMatrix * vec4(position * scaleVec, 1.0f);
// "   gl_Position = vec4(position, 1.0f);\n"
// "   gl_Position = vec4(position * scale, 0.0f, 1.0f);\n"
}
