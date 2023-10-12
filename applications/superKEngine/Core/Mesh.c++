#include "../includes/Mesh.hpp"

void Mesh::callthisfakeconstructor(
    Vertex *vertexArray,
    const unsigned& noOfVertices,
    GLuint *indexArray,
    const unsigned& noOfIndices,
    glm::vec3 position,
    glm::vec3 rotation,
    glm::vec3 scale
)
{
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
    texture = NULL; // must have

    initVertexData(vertexArray, noOfVertices, indexArray, noOfIndices);
    initVAO();

    physics = new Physics(this);
    physics->simulatePhysics(false);
}

// ! must be called before initVAO (must have data in vertices variable before initialization)
void Mesh::initVertexData(Vertex *vertexArray,
    const unsigned& noOfVertices,
    GLuint *indexArray,
    const unsigned& noOfIndices
)
{
    this->noOfIndices = noOfIndices;
    this->noOfVertices = noOfVertices;

    for (size_t i = 0; i < noOfVertices; i++)
    {
        this->vertices.push_back(vertexArray[i]);
    }
    for (size_t i = 0; i < noOfIndices; i++)
    {
        this->indices.push_back(indexArray[i]);
    }

}

void Mesh::initVAO()
{
    assert(noOfVertices != 0);
    assert(noOfIndices != 0);

    vao = new VAO();
    vao->Bind();
    
    // vbo = new VBO(vertices);
    vbo = new VBO(vertices.data(), vertices.size() * sizeof(Vertex));
    // vertices.data();
    // glGe
    // glGenBuffers(1, &this->vbo->Id);
    // glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data())
    ebo = new EBO(indices);


    // position, color, texcoord, normal
    // 3 + 3 + 2 + 3 = 11
    GLsizeiptr stride = 11 * sizeof(float);
    vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, stride, (void *)(0 * sizeof(float)));
    vao->LinkAttrib(*vbo, 1, 3, GL_FLOAT, stride, (void *)(3 * sizeof(float)));
    vao->LinkAttrib(*vbo, 2, 2, GL_FLOAT, stride, (void *)(6 * sizeof(float)));
    vao->LinkAttrib(*vbo, 3, 3, GL_FLOAT, stride, (void *)(8 * sizeof(float)));

    vao->Unbind();
}


void Mesh::updateModelMatrix()
{
    ModelMatrix = glm::mat4(1.f);
    ModelMatrix = glm::translate(ModelMatrix, position);
    ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
    ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));
    ModelMatrix = glm::scale(ModelMatrix, scale);
}


void Mesh::updateUniform(Shader* shader)
{
    shader->setMat4fv(this->ModelMatrix, "ModelMatrix");
}

void Mesh::setNewTexture(std::string texturePath, GLenum format)
{
    texture = new Texture(
        texturePath.c_str(),
        GL_TEXTURE_2D, GL_TEXTURE0,
        // GL_RGB, GL_UNSIGNED_BYTE
        // GL_RGBA, GL_UNSIGNED_BYTE
        format, GL_UNSIGNED_BYTE
    );
}

// inline Mesh() { printf("This is base naked constructor of Mesh class.\n"); }

Mesh::Mesh(
    Primitive *primitive,
    const char *texturePath
)
{
    this->position = glm::vec3(0);
    this->rotation = glm::vec3(0);
    this->scale = glm::vec3(1);

    setNewTexture(texturePath);

    initVertexData(primitive->getVertices(), primitive->getNoOfVertices(),
        primitive->getIndices(), primitive->getNoOfIndices()
    );
    initVAO();
}

Mesh::Mesh(
    Primitive *primitive,
    glm::vec3 position,
    glm::vec3 rotation,
    glm::vec3 scale
)
{
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;

    texture = NULL;
    initVertexData(primitive->getVertices(), primitive->getNoOfVertices(),
        primitive->getIndices(), primitive->getNoOfIndices()
    );
    initVAO();
}

Mesh::Mesh(
    Vertex *vertexArray,
    const unsigned& noOfVertices,
    GLuint *indexArray,
    const unsigned& noOfIndices,
    glm::vec3 position,
    glm::vec3 rotation,
    glm::vec3 scale
)
{
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;

    initVertexData(vertexArray, noOfVertices, indexArray, noOfIndices);
    initVAO();
}

Mesh::~Mesh()
{
    vao->Delete();
    vbo->Delete();
    ebo->Delete();
}


void Mesh::render(Shader* shader)
{
    update();

    // NOTE : camera must derived from world 
    // (ThisMesh class must come from world's addMeshObject method api )
    // assert(camera);
    // updateProjectionMatrix();
    // updateViewMatrix();
    updateModelMatrix();
    // camera->updateUniform();
    
    updateUniform(shader);


    shader->Activate(); // must active after updateUniform


    // if (texture != NULL)
    // {
    //     // texture->texUnit(*shader, "tex0", 0);
    //     // texture->Bind();
    // }
    // else{
    //     std::cout << "im real null texture\n";
    // }

    vao->Bind();


    // #define JTest
    // #ifndef JTest
    // Texture *texture = new Texture(
    //     // texturePath,
    //     // "img/abadon.png",
    //     "/Users/rio/Desktop/glgl/img/abadon.png",
    //     GL_TEXTURE_2D, GL_TEXTURE0,
    //     GL_RGB, GL_UNSIGNED_BYTE
    // );
    // texture->texUnit(*shader, "tex0", 0);
    if (texture != NULL)
    {
        GLint loc = glGetUniformLocation(shader->shaderProgramId, "isHasTexture");
        glUniform1i(loc, 1);

        // texture->texUnit(*shader, "tex0", 0);
        texture->Bind();
    }
    // meshes with no textures path file
    else
    {
        GLint loc = glGetUniformLocation(shader->shaderProgramId, "isHasTexture");
        glUniform1i(loc, 0);
    }

    // #endif

    // if (this->indices.empty())
    //     glDrawArrays(GL_TRIANGLES, 0, noOfVertices);
    // else
    // glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    // glDrawElements(GL_TRIANGLES, noOfIndices, GL_UNSIGNED_BYTE, 0);
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glDrawElements(GL_TRIANGLES, noOfIndices, GL_UNSIGNED_INT, 0);
    // glDrawArrays(GL_TRIANGLES, 0, noOfVertices);

    // texture->Delete();
    // shader->Deactivate();
}

void Mesh::setPosition(const glm::vec3 newCenter)
{
    // if (!canMove) return;
    glm::vec3 oldCenter = this->position;
    for (int i = 0; i < this->noOfVertices; i++)
    {
        // glm::vec3 delta = pos - oldPos;
        glm::vec3 vectorDirection = vertices[i].position - oldCenter;
        // vertices[i].position += pos;
        vertices[i].position = newCenter + vectorDirection;
        // vertices[i].normal += pos;
    }
    this->position = newCenter;
}

void Mesh::setRotation(const glm::vec3 rotation)
{
    this->rotation = rotation;
}

void Mesh::setScale(const glm::vec3 scale)
{
    this->scale = scale;
    for (int i = 0; i < this->noOfVertices; i++)
    {
        vertices[i].position *= scale;
        // vertices[i].normal *= scale;
    }
}

void Mesh::move(const glm::vec3 shiftVector)
{
    // if (!canMove) return;
    setPosition(position + shiftVector);
    // this->position += shiftVector;
    // for (int i = 0; i < this->noOfVertices; i++)
    // {
    //     vertices[i].position += shiftVector;
    //     vertices[i].normal += shiftVector;
    // }
}

void Mesh::rotate(const glm::vec3 rotation)
{
    this->rotation += rotation;
    if (this->rotation.x > 360)    
        this->rotation.x = 0;
}

void Mesh::scaleMesh(const glm::vec3 scale)
{
    this->scale *= scale;
    for (int i = 0; i < this->noOfVertices; i++)
    {
        vertices[i].position *= scale;
        // vertices[i].normal *= scale;
    }
}

// void setColor()
// {
//     for (size_t i = 0; i < this->noOfVertices; i++)
//     {
//         printf("vertice %lu\n", i);
//         vertices[i].color = glm::vec3(1);
//     }
// }


// inline std::vector<Vertex> getVertices() { return vertices; }
// inline std::vector<GLuint> getIndices() { return indices; }
// // inline GLuint* getIndices() { return indices.data(); }
// // inline GLuint* getIndices() { return indices.data(); }
// inline GLuint getNoOfVertices() {return noOfVertices; }
// inline GLuint getNoOfIndices() {return noOfIndices; }

// inline glm::vec3 getPosition() { return position; }
// inline glm::vec3 getRotation() { return rotation; }
// inline glm::vec3 getScale() { return scale; }

void Mesh::meshShow()
{
    // printf("position | scale | rotation | noV | noIdx       ->        ");
    printf("position | scale | rotation       ->        ");
    vecshow(position, false);
    vecshow(scale, false);
    vecshow(rotation, true);
    // printf(" %lu, %lu\n", noOfVertices, noOfIndices);
    // printf("")
}

// void Mesh::enabePhysic(bool enable)
// {
//     physicOn = enable;
// }

void Mesh::update()
{
    // printf("kkk");
    // if (physicOn)
    // {
    physics->update();
    // }
}
