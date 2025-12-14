#include "die.h"
#include <cstdlib>

int Die::roll() {
    return (std::rand() % sides) + 1;
}
// Question 1 commit
// Question 1 commit
