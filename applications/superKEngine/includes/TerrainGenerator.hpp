#ifndef TerrainGen_H
#define TerrainGen_H

#include "PerlinNoise.hpp"
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include "glm/geometric.hpp"
#include "stdEngine.hpp"

class TerrainGenerator
{
private:
    static PerlinNoise pn;
public:
    // static void showMatrix(std::vector<std::vector<float> > mat)
    static void showMatrix(std::vector<std::vector<Vertex> > mat);
    static std::vector<std::vector<Vertex> > generateTerrain(int width, int height);
    static std::vector<Vertex> flatten2DTo1D(std::vector<std::vector<Vertex> > mat);
};


// PerlinNoise TerrainGenerator::pn = PerlinNoise();

#endif