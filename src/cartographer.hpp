#pragma once
#include <cmath>
#include <random>

class PermutationTable
{
    u_int32_t values;

public:
    PermutationTable(u_int seed = 0);
};

class Perlin2D
{
    const u_int DEFAULT_SEED = 0;
    u_int seed;
    PermutationTable perm_table;

public:
    Perlin2D(u_int seed = 0);
};