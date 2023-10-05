#ifndef Sphere_H
#define Sphere_H
// use trig to init vertices
#include "Mesh.hpp"
#include "glm/fwd.hpp"
#include "glm/geometric.hpp"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/trigonometric.hpp"
#include <algorithm>
#include <cassert>
#include <cstdbool>
#include <ostream>
#include <vector>



// struct SVerticesAndIndices
// {
//     std::vector<Vertex> vertices;
//     std::vector<GLuint> indices;
// };

class Sphere : public Mesh
{
private:
    // glm::vec3 position;        
    float radius;
    unsigned int noOfRings;
    unsigned int noVerticesEachRing;
    float pollAngle;


    // float getRadiasEachRing(int ringIndex) 
    // {
    //     // NOTE linear interpolation
    //     // float midRingWithMaxRadius = noOfRings / 2.f;
    //     // float slope = (ringIndex <= midRingWithMaxRadius) ? (radius / midRingWithMaxRadius) : (-radius / midRingWithMaxRadius);
    //     // float interception = (ringIndex <= midRingWithMaxRadius) ? (0) : (radius);
    //     // // float interception = (ringIndex > midRingWithMaxRadius) ? (0) : (radius);
    //     // // 0.1 prevent sub radius will be 0
    //     // float ret =  0.1 + ((slope * ringIndex) + interception);

    //     // printf("sub radius = %f\n", ret);
    //     // assert(ret > 0);
    //     // return ret;

    //     // NOTE linear interpolation v 2
    //     // float valueNegOneToPosOne = lerp(0, noOfRings, -1, 1, ringIndex);
    //     // float valueZeroToOne = sin(valueNegOneToPosOne);
    //     // // float valueZeroToOne = valueNegOneToPosOne;
    //     // // float amplifiedZeroToRadius = valueZeroToOne * radius;
    //     // float amplifiedZeroToRadius = valueZeroToOne;
    //     // printf("sub radius = %f\n", amplifiedZeroToRadius);
    //     // return amplifiedZeroToRadius;
        

    //     // NOTE : use sin fn (but not good enough)
    //     // float val = lerp(0, noOfRings, 0, 180, ringIndex);
    //     // val = sin(glm::radians(val)); // val *= radius; // this is worked but it's sin (not really real circle)
    //     // float 

    //     printf("sub radius = %f\n", val);
    //     return val;

    //     // NOTE parabolic
    //     // float p = (-4.f / 3) * 10;
    //     // return ( 1 / (4 * p)) * pow((ringIndex - midRingWithMaxRadius), 2) + radius;
    // }

    std::vector<Vertex> getRing(int ringIndex)
    {
        std::vector<Vertex> verticesInRing;
        // // float pollAngle = 30;
        // // int noVerticesInARing = (int)(360 / pollAngle);
        // // glm::vec3 initPoint = position + glm::vec3(radius, 0.0f, (0.1)*ringIndex);
        // float subRadius = getRadiasEachRing(ringIndex);
        // float deltaZ = (2 * radius) / noOfRings;
        // glm::vec3 initPoint = position 
        //     + glm::vec3(subRadius, 0.0f, (deltaZ)*ringIndex);
        // // glm::vec3 initPoint = glm::vec3(position.x + radius, position.y, (position.z + (0.1)*ringIndex) - radius);
        // // glm::vec3 initPoint = glm::vec3(position.x + (radius / ringIndex), position.y, (position.z + (0.1)*ringIndex) - radius);

        // for (int i = 0; i < noVerticesEachRing; i++)
        // // for (int i = 1; i < 12; i++)
        // {
        //     glm::vec3 rotatedVec = glm::rotateZ(initPoint, (float)glm::radians(-pollAngle * i));
        //     Vertex v = {
        //         rotatedVec,
        //         // glm::vec3(0.3, 0.3, 0.4), // color
        //         glm::vec3((ringIndex % 2 ? 0 : 0.5), 0, 0.1 * sin(i)), // color
        //         glm::vec3(1, 1, 0), // texcoord
        //         glm::normalize(rotatedVec)
        //     };
        //     verticesInRing.push_back(v);
        // }
        // return verticesInRing;

        float pitchAngle = pollAngle;

        float angleToRotateYAxis = lerp(0, noOfRings, -90, 90, ringIndex);
        // * VERSION 2
        for (int i = 0; i < noVerticesEachRing; i++)
        {
            glm::vec3 initPoint = position + glm::vec3(radius, 0, 0);
            // glm::vec3 rotatedVec = glm::rotateY(initPoint, glm::radians(-pitchAngle * ringIndex));
            glm::vec3 rotatedVec = glm::rotateY(initPoint, glm::radians(angleToRotateYAxis));
            rotatedVec = glm::rotateZ(rotatedVec, glm::radians(pollAngle * i));
            glm::vec3 normalSurfaceVec = glm::normalize(rotatedVec - position);
            Vertex v = {
                rotatedVec,
                // glm::vec3(0.3, 0.3, 0.4), // color
                glm::vec3((ringIndex % 2 ? 0.4 : 0.5), 0, 0.1 * sin(i)), // color
                // glm::vec3(0, 0.2, 0.4), // color

                glm::vec3(1, 1, 0), // texcoord
                // glm::normalize(rotatedVec)
                normalSurfaceVec
            };
            // vecshow(rotatedVec);
            // std::cout << std::endl;
            verticesInRing.push_back(v);
        }
        return verticesInRing;
    }

    // std::array<int, 3> getIndicesOfTriangle(int ringIndex, int vertexInThatRingIndex)
    TripleIndex getIndicesOfTriangle(int ringIndex, int vertexInThatRingIndex, bool isATriangleOrB)
    {
        // int secondIndex = 12 * (ringIndex + 1) + vertexInThatRingIndex;
        int secondIndex = noVerticesEachRing * (ringIndex + 1) + vertexInThatRingIndex;
        TripleIndex ret;
        if (isATriangleOrB)
        {
            // ret.a = 12 * (ringIndex) + vertexInThatRingIndex;
            ret.a = noVerticesEachRing * (ringIndex) + vertexInThatRingIndex;
            ret.b = secondIndex;
            ret.c = secondIndex + 1;
        }
        else
        {
            // ret.a = 12 * ringIndex + vertexInThatRingIndex;
            ret.a = noVerticesEachRing * ringIndex + vertexInThatRingIndex;
            ret.b = ret.a + 1;
            ret.c = secondIndex + 1;
        }

        // int allIndices = noOfRings * noOfVertices;
        // ret.a %= allIndices;
        // ret.b %= allIndices;
        // ret.c %= allIndices;

        // return {ringIndex + vertexInThatRingIndex, secondIndex, secondIndex + 1};
        return (ret);
    }

    void initializeVerticesAndIndicesDataOfSphere()
    {
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;
        noOfRings = 12;
        // noOfRings = 64;
        // noOfRings = 7;
        // noOfRings = pow(2, 8);
        // pollAngle = 15.f / 8;
        pollAngle = 30;
        noVerticesEachRing = 360 / pollAngle;

        // noVerticesEachRing = 30;

        for (int r = 0; r < noOfRings; r++)
        {
            std::vector<Vertex> ring = getRing(r);
            for (int vi = 0; vi < ring.size(); vi++)
            {
                vertices.push_back(ring[vi]);

                // if (r != noOfRings - 1)
                // {
                    TripleIndex tripletIndex = getIndicesOfTriangle(r, vi, true);
                    // printf("vi = %d\t", vi);
                    indices.push_back(tripletIndex.a);
                    indices.push_back(tripletIndex.b);
                    indices.push_back(tripletIndex.c);

                    TripleIndex tripletIndex2 = getIndicesOfTriangle(r, vi, false);
                    indices.push_back(tripletIndex2.a);
                    indices.push_back(tripletIndex2.b);
                    indices.push_back(tripletIndex2.c);
                // }
                // else
                // {

                // }
            }
        }


        // SVerticesAndIndices ret;
        // ret.vertices = vertices;
        // ret.indices = indices;
        this->vertices = vertices;
        this->indices = indices;

        noOfIndices = indices.size();
        noOfVertices = vertices.size();
    }

public:
    Sphere(glm::vec3 position, float radius)
    : Mesh() 
    {
        assert(radius > 0);
        this->position = position;
        this->radius = radius;
        // NOTE : make this funciton called by corrected Vertices data & indices
        
        initializeVerticesAndIndicesDataOfSphere();

        // printText2D(const char *text, int x, int y, int size)

        // showvertices(vertices);
        // // vecshow
        // for (int i = 0; i < (indices.size() / 3); i++)
        // // for (int i = 0; i < indices.size(); i++)
        // {
        //     if (i % noVerticesEachRing == 0)
        //     {
        //         printf("--------\n");
        //     }

        //     int base = 3;
        //     printf("[%d, %d, %d]\n", 
        //         indices[base * i + 0],
        //         indices[base * i + 1],
        //         indices[base * i + 2]
        //     );
        //     // printf("%d, ", indices[i]);
        //     // if (i % 4 == 0)
        //     //     printf("\n");
        // }
        // // // showvertices(indices);

        callthisfakeconstructor(vertices.data(), noOfVertices,
            indices.data(), noOfIndices
        );
    }

    bool isCollideWith(Mesh& mesh)
    {
        glm::vec3 pos;
        for (int i = 0; i < mesh.getVertices().size(); i++)
        {
            pos = mesh.getVertices()[i].position;
            float dist = glm::distance(position, pos);
            // printf("center is "); 
            //     vecshow(position);
            // printf("pos is ");
            //     vecshow(pos);
            // printf("dist = %f\n\n", dist);
            if (dist <= radius)
            // if (glm::distance(position, pos) <= 1000)
            {
                return true;
            }
        }
        return false;
    }
};

#endif