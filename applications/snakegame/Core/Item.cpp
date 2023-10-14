#include "../includes/item.hpp"

Item::Item(glm::vec4 rect, std::string imageName, std::string _pathToImage, 
    GLenum imageFormat)
    : Panel(glm::vec3(1, 1, 1), rect, imageName),
    imageFormat(imageFormat)
{
        // src/resources/duals/basicRectImage/default.vert
    shaderProgram = useShaderProgram(
        "/Users/rio/Desktop/glgl/src/resources/duals/basicRectImage/default.vert",
        "/Users/rio/Desktop/glgl/src/resources/duals/basicRectImage/default.frag"
    );
    changeItemImage(_pathToImage);
}

void Item::changeItemImage(std::string path)
{
    pathToImage = path;
}

void Item::draw()
{
    GLfloat tempV[] = 
    {
        //*  position                        |  texture coordinates
        // rect.x         , rect.y,          0.0f,   1.,  1.,
        // rect.x + rect.z, rect.y,          0.0f,  -1.,  1.,
        // rect.x + rect.z, rect.y - rect.w, 0.0f,   1.,  -1.,
        // rect.x         , rect.y - rect.w, 0.0f,  -1.,  -1.

        rect.x         , rect.y,          0.0f,  0, 1,
        rect.x + rect.z, rect.y,          0.0f,  1, 1,
        rect.x + rect.z, rect.y - rect.w, 0.0f,  1, 0,
        rect.x         , rect.y - rect.w, 0.0f,  0, 0
    };
    *vertices = tempV;

    // GLuint indices[] = {
    //     0, 1, 2,
    //     2, 3, 0
    // };
    // VAO vao;
    // vao.Bind();

    // // VBO vbo(vertices, sizeof(vertices));
    vbo = new VBO(*vertices, sizeof(vertices));
    ebo = new EBO(indices, sizeof(indices));


    vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, 5 * sizeof(float), (void *)(0));
    vao->LinkAttrib(*vbo, 1, 2, GL_FLOAT, 5 * sizeof(float), (void *)(3 * sizeof(float)));

    Texture tex((const char *)pathToImage.c_str(),
    // static const char *texPath = "../../../img/abadon.png";
    // Texture tex(texPath,
        GL_TEXTURE_2D, GL_TEXTURE0,
        // GL_RGB, GL_UNSIGNED_BYTE
        imageFormat, GL_UNSIGNED_BYTE,
        false
    );
    tex.texUnit(shaderProgram, "tex0", 0);

    // * real draw (must be inside while loop)
    tex.Bind();

    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), 
        GL_UNSIGNED_INT, 0
    );

    vbo->Delete();
    ebo->Delete();
    tex.Delete();
}

