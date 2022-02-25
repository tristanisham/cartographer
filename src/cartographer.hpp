#pragma once
#include <iostream>
#include "PerlinNoise.hpp"
#include <vector>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint> // for specific size integers
#include <fstream> // for file handling
#include "lodepng.h"
#include <random>



class Cartographer
{
    
protected:
    long long seed;
    int x, y;


public:
    enum class NoiseType {
        PERLIN
    };
    static Cartographer typical(int width, int height);
    void createPNG(const char *filename, NoiseType noise);

private:
    Cartographer(long long seed, int x, int y, std::vector<std::vector<double>>* noise_map);
    std::vector<std::vector<double>> noise_map;
    static long long genSeed();
};

