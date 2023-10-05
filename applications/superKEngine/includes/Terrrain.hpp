#ifndef Terrain_H
#define Terrain_H

#include "Mesh.hpp"
#include <vector>
#include "TerrainGenerator.hpp"
#include "stdEngine.hpp"

class Terrain : public Mesh
{
public:
    int width;
    int height;

    void initIndices()
    {
        // indices
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                TripleIndex triplet = getIndicesOfTriangle(i, j, true);
                indices.push_back(triplet.a);
                indices.push_back(triplet.b);
                indices.push_back(triplet.c);

                triplet = getIndicesOfTriangle(i, j, false);
                indices.push_back(triplet.a);
                indices.push_back(triplet.b);
                indices.push_back(triplet.c);
            }
        }
        noOfIndices = indices.size();
    }

    TripleIndex getIndicesOfTriangle(int ringIndex, int vertexInThatRingIndex, bool isATriangleOrB)
    {
        // int secondIndex = 12 * (ringIndex + 1) + vertexInThatRingIndex;
        int secondIndex = width * (ringIndex + 1) + vertexInThatRingIndex;
        TripleIndex ret;
        if (isATriangleOrB)
        {
            // ret.a = 12 * (ringIndex) + vertexInThatRingIndex;
            ret.a = width * (ringIndex) + vertexInThatRingIndex;
            ret.b = secondIndex;
            ret.c = secondIndex + 1;
        }
        else
        {
            // ret.a = 12 * ringIndex + vertexInThatRingIndex;
            ret.a = width * ringIndex + vertexInThatRingIndex;
            ret.b = ret.a + 1;
            ret.c = secondIndex + 1;
        }

        return (ret);
    }

    Terrain(int width, int height) : Mesh()
    {
        this->width = width;
        this->height = height;
        std::vector<std::vector<Vertex> > vertexMatrix = TerrainGenerator::generateTerrain(width, height);
        // vertices.
        TerrainGenerator::showMatrix(vertexMatrix);
        // printf("HERE\n");
        vertices = TerrainGenerator::flatten2DTo1D(vertexMatrix);
        noOfVertices = vertices.size();
        // vertices.
        initIndices();

        callthisfakeconstructor(vertices.data(), noOfVertices, indices.data(), noOfIndices);

    }

    // void redraw()
    // {
    //     vertices.clear();
    //     indices.clear();

    //     std::vector<std::vector<Vertex> > vertexMatrix = TerrainGenerator::generateTerrain(width, height);
    //     vertices = TerrainGenerator::flatten2DTo1D(vertexMatrix);
    //     noOfVertices = vertices.size();
    //     // vertices.
    //     initIndices();

    //     callthisfakeconstructor(vertices.data(), noOfVertices, indices.data(), noOfIndices);
    // }

    bool isCollideWith(Mesh& mesh)
    {
        return false;
    }
};

#endif