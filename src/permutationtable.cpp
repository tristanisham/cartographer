#include "cartographer.hpp"

PermutationTable::PermutationTable(u_int seed) {
    
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;

    this->values = seed;
}