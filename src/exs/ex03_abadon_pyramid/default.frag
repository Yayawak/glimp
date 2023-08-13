#version 330 core
// out vec4 FragColor;
out vec4 FragColor;

uniform sampler2D texture;
void main()
{
    // FragColor = vec4(.8f, .3f, .02f, 1.f);
    FragColor = texture(texture);
}
