#version 330 core
// out vec4 FragColor;
in vec2 texCoord;
in vec3 Color;
out vec4 FragColor;

uniform sampler2D tex0;
void main()
{
    // FragColor = vec4(.8f, .3f, .02f, 1.f);
    // FragColor = vec4(Color, 1.0f) * texture(tex0, texCoord);
    FragColor = vec4(Color, 1.0f) * texture(tex0, texCoord);
}