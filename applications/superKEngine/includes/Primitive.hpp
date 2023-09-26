#ifndef Prim_H
#define Prim_H

#include "../../../src/structure/headers/stdgl.hpp"

class Primitive
{
private:
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    size_t noOfVertices;
    size_t noOfIndices;

protected:
    void set(const Vertex *vertexArray,
        const unsigned& noOfVertices,
        const GLuint *indexArray,
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


public:
    Primitive() { }
    virtual ~Primitive() {}


    inline Vertex* getVertices() {return vertices.data(); }
    inline GLuint* getIndices() {return indices.data(); }
    inline GLuint getNoOfVertices() {return noOfVertices; }
    inline GLuint getNoOfIndices() {return noOfIndices; }
};


#endif