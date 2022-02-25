# Cartographer
**Current Version: v0.0.0**

Cartographer is currently a library that consists of just *five* files. They are easy to compile using g++, clang++ or any compiler if you decide to use [xmake](https://xmake.io). Below you'll find an example and any documentation regarding each version of the library (it follows semantic versioning) and a short example of a complete program using Cartographer. 

All version without a release tag (as shown on the official [git](https://github.com/tristanisham/cartographer)) will be tracked to `v0.0.0` or will be otherwise specified. Master is bleeding edge, and as such should not be used in production. For information on contributing please [click here](./CONTRIBUTING.md).

## v0.0.0

```cpp
#include "cartographer.hpp"

int main(int argc, char const *argv[])
{
    Cartographer cart = Cartographer::typical(512, 512);
    cart.createPNG("./logo.png", Cartographer::NoiseType::PERLIN);
    return 0;
}
```
