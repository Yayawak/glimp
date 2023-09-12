#version 330 core
// in vec4 Color;
in vec3 Color;

out vec4 FragColor;
void main()
{
    FragColor = vec4(Color, 1);
    // FragColor = vec4(1, 0, 0, 1);
}