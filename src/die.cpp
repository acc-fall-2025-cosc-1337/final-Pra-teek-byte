#include "die.h"
#include <cstdlib>

int Die::roll() {
    return (std::rand() % sides) + 1;
}
