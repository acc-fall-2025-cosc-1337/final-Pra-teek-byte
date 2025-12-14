#include <iostream>
#include <cstdlib>
#include <ctime>
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Die die1, die2;
    Shooter shooter;
    Roll* roll = shooter.throw_dice(die1, die2);

    ComeOutPhase come_out_phase;

    while (come_out_phase.get_outcome(roll) == RollOutcome::natural ||
           come_out_phase.get_outcome(roll) == RollOutcome::craps) {
        std::cout << "Rolled " << roll->roll_value()
                  << " roll again" << std::endl;
        roll = shooter.throw_dice(die1, die2);
    }

    int point = roll->roll_value();
    std::cout << "Rolled " << point << " start of point phase" << std::endl;
    std::cout << "Roll until " << point << " or a 7 is rolled" << std::endl;

    roll = shooter.throw_dice(die1, die2);
    PointPhase point_phase(point);

    while (point_phase.get_outcome(roll) != RollOutcome::seven_out &&
           point_phase.get_outcome(roll) != RollOutcome::point) {
        std::cout << "Rolled " << roll->roll_value()
                  << " roll again" << std::endl;
        roll = shooter.throw_dice(die1, die2);
    }

    std::cout << "Rolled " << roll->roll_value()
              << " end of point phase" << std::endl;

    shooter.display_rolled_values();
    return 0;
}
// Question 5 commit
// Q5 commit
