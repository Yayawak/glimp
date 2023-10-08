#include "../includes/TerrainGenerator.hpp"

PerlinNoise TerrainGenerator::pn = PerlinNoise();

void TerrainGenerator::showMatrix(std::vector<std::vector<Vertex> > mat)
// static void showMatrix(std::vector<std::vector<Vertex> > mat)
{
    for (int h = 0; h < mat.size(); ++h)
    {
        std::vector<float> row;
        for (int w = 0; w < mat[h].size(); ++w)
        {
            printf("|%.2f", mat[h][w].position.z);
        }
        printf("|\n");
        // std::string s("-");
        // s.
        // printf("-")
    }
}
// perlin noise
// TerrainGenerator()
// static std::vector<std::vector<float> > generateTerrain(int width, int height)
std::vector<std::vector<Vertex> > TerrainGenerator::generateTerrain(int width, int height)
{
    // float maxWOrH = std::max(width, height);
    // float maxWOrH = 1.f / std::max(width, height);
    // ** If i want to make terrain more large in area adjust topper value in below line
    float maxWOrH = 4.f / std::max(width, height);
    // std::vector<std::vector<float> > ret;
    std::vector<std::vector<Vertex> > ret;
    float any = 0;
    for (int h = 0; h < height; ++h)
    {
        // std::vector<float> row;
        std::vector<Vertex> row;
        for (int w = 0; w < width; ++w)
        {
            float scale = 5;
            double y = (double)h / ((double)height * scale);
            double x = (double)w / ((double)width * scale);
            // double y = (double)h / (double)500;
            // double x = (double)w / (double)500;
            // float k = pn.noise(h, w, any);
            // float k = pn.noise(x, y, any);
            // float z = pn.noise(10 * x, 10 * y, 8);
            // ** This k value indicate how messy our terrain are
            float k = 30; // old is 10
            float z = pn.noise(k * x, k * y, 8);
            // k = 20 * pn.noise(x, y, 0.8);
            // z = lerp(0.50f, 0.58f, 0, 2, z);
            // z = sin(glm::radians(z));
            // printf("k = %f\n", k);
            Vertex v;
            // v.position = glm::vec3(w, h, z);
            // v.position = glm::vec3(w, h, z);
            v.position = glm::vec3(w * maxWOrH, h * maxWOrH, z);
            v.normal = glm::normalize(v.position);
            // v.color = glm::vec3(0.5, 0, z);
            v.color = glm::vec3(0, 0.3, 
                // lerp(0.3f, 0.7f, 0, 1, z)
                // lerp(-2, 2, 0, 1, z)
                // lerp(0.4, 0.8, 0, 1, z)
                z
                // z
                // pow(sin(random()), 2)
            );
            v.texcoord = glm::vec3(0, 0, 0);

            row.push_back(v);
        }
        ret.push_back(row);
    }
    return (ret);
}

std::vector<Vertex> TerrainGenerator::flatten2DTo1D(std::vector<std::vector<Vertex> > mat)
{
    std::vector<Vertex> flat;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            flat.push_back(mat[i][j]);
        }
    }
    return flat;
}