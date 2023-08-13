#version 330 core
in vec3 Color;
in vec2 texCoord;
out vec4 FragColor;
uniform sampler2D tex0;
void main()
{
    // FragColor = vec4(0.4f, 1.f, 0.f, 1.f);
    // FragColor = vec4(1.f, 0.7f, 0.f, 1.f);
    // outColor = vec4(1.0, 0.0, 0.0, 1.0);
    // outColor = vec4(Color, 1.0);
    FragColor = texture(tex0, texCoord);
}