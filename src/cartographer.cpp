#include "cartographer.hpp"
#include <ctime>
#include <sstream>

long long Cartographer::genSeed()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 9223372036854775807); // distribution in range [1, 6]

    return dist6(rng);
}

Cartographer::Cartographer(long long seed, int x, int y, std::vector<std::vector<double>> *noise_map = NULL)
{
    this->x = x;
    this->y = y;
    this->seed = seed;

    if (noise_map != NULL)
    {
        this->noise_map = *noise_map;
    }
}

Cartographer Cartographer::typial(int width, int height)
{
    long long ss = Cartographer::genSeed();
    
    const siv::PerlinNoise::seed_type seed = ss;
    const siv::PerlinNoise perlin{seed};
    std::vector<std::vector<double>> noise_map;
    for (int y = 0; y < height; y++)
    {
        std::vector<double> nwidth;
        for (int x = 0; x < width; x++)
        {
            double nx = x / width - 0.5, ny = y / height - 0.5;
            auto result = perlin.octave2D_01((x * 0.01), (y * 0.01), 4);
            nwidth.push_back(result);
        }
        noise_map.push_back(nwidth);
    }

    std::vector<std::vector<double>> *map = &noise_map;
    return Cartographer(seed, width, height, map);
}

void encodeOneStep(const char *filename, std::vector<unsigned char> &image, unsigned width, unsigned height)
{
    //Encode the image
    unsigned error = lodepng::encode(filename, image, width, height);

    //if there's an error, display it
    if (error)
        std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

void Cartographer::createPNG(const char *filename)
{
    // for (unsigned i; i < this->noise_map.size(); i++)
    // {
    //     for (unsigned j; j < this->noise_map[i].size(); j++)
    //     {

    //         // std::cout << j << std::endl;
    //     }
    // }

    std::vector<unsigned char> image;
    image.resize(this->x * this->y * 4);
    for (unsigned y = 0; y < this->y; y++)
        for (unsigned x = 0; x < this->x; x++)
        {
            image[4 * this->x * y + 4 * x + 0] = 255 * this->noise_map[y][x];
            image[4 * this->x * y + 4 * x + 1] = 255 * this->noise_map[y][x];
            image[4 * this->x * y + 4 * x + 2] = 255 * this->noise_map[y][x];
            image[4 * this->x * y + 4 * x + 3] = 255;
        }

    // for (unsigned y; y < this->noise_map.size(); y++)
    // {
    //     for (unsigned x; x < this->noise_map[y].size(); x++)
    //     {
    //         image[4 * x * y + 4 * x + 0] = 255 * this->noise_map[y][x];
    //         image[4 * x * y + 4 * x + 1] = 255 * this->noise_map[y][x];
    //         image[4 * x * y + 4 * x + 2] = 255 * this->noise_map[y][x];
    //         image[4 * x * y + 4 * x + 3] = 255;
    //     }
    // }

    encodeOneStep(filename, image, this->x, this->y);
}