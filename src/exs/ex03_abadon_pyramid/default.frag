#version 330 core
// out vec4 FragColor;
out vec4 FragColor;

in vec2 texCoord;
uniform sampler2D tex0;
void main()
{
    // FragColor = vec4(.8f, .3f, .02f, 1.f);
    FragColor = texture(tex0, texCoord);
}

//  in vec3 Color;\n\
//     in vec2 texCoord;\n\
//     // out vec4 outColor;\n\
//     out vec4 FragColor;\n\
//     uniform sampler2D tex0;\n\
//     void main()\n\
//     {\n\
//         // FragColor = vec4(0.4f, 1.f, 0.f, 1.f);\n\
//         // FragColor = vec4(1.f, 0.7f, 0.f, 1.f);\n\
//         // outColor = vec4(1.0, 0.0, 0.0, 1.0);\n\
//         // outColor = vec4(Color, 1.0);\n\
//         FragColor = texture(tex0, texCoord);\n\
//     }";