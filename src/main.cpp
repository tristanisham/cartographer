#include "cartographer.hpp"

int main(int argc, char const *argv[])
{
    Cartographer cart = Cartographer::typical(512, 512);
    cart.createPNG("./logo.png", Cartographer::NoiseType::PERLIN);
    return 0;
}
