#include "cartographer.hpp"

Perlin2D::Perlin2D(u_int seed)
{
    this->seed = seed;
    PermutationTable pt{seed};
    this->perm_table = pt;
}
