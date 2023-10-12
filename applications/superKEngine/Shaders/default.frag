#version 330 core
// out vec4 FragColor;
in vec2 texCoord;
in vec3 Color; // object color
in vec3 FragPos;
in vec3 Normal;

out vec4 FragColor;

vec3 green = vec3(0, 1, 0);
uniform sampler2D tex0;
uniform int isHasTexture;

uniform vec3 lightPos = vec3(-2, 2, 1);
// #f7e77c dawn yellow -> below line use dawn yellow
// vec3 lightColor = vec3(247.f, 231.f, 124.f) / 256.f;
vec3 lightColor = vec3(1, 1, 1);
// #ffff00 real yellow

vec3 viewPos = vec3(0, 0, 1);

vec4 calculateProneLight()
{
    // * ambient light
    float ambientStrength = 0.7f;
    vec3 ambient = ambientStrength * lightColor;

    // * diffuse light
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diffuseStrength = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diffuseStrength * lightColor;

    // * specular
    float specularStrength = 0.5f;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse + specular) * Color;
    return (vec4(result, 1.0));
}

int is3D = 0;

void main()
{
    // FragColor = vec4(.8f, .3f, .02f, 1.f);
    // FragColor = vec4(green, 1.f);
    // FragColor = vec4(Color, 1.0f);
    // if (tex0)
    //     FragColor = vec4(Color, 1.0f) * texture(tex0, texCoord);
    // else
        // FragColor = vec4(Color, 1.0f);

    if (is3D == 1) 
    {
        if (isHasTexture == 1)
        {
            // FragColor = vec4(Color, 1.0f) * texture(tex0, texCoord);
            FragColor = calculateProneLight() * texture(tex0, texCoord);
        }
        else
        {
            // FragColor = vec4(Color, 1.0f);
            FragColor = calculateProneLight();
        }
    }
    else
    {
        if (isHasTexture == 1)
        {
            FragColor = vec4(Color, 1.0f) * texture(tex0, texCoord);
            // FragColor = texture(tex0, texCoord);
        }
        else
        {
            FragColor = vec4(Color, 1.0f);
        }
    }


    // FragColor = vec4(Color, 1.0f) * texture(tex0, texCoord);




}