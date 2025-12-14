#include <iostream>
#include <cassert>
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include "roll.h"
#include "die.h"

int main() {
    Die die1, die2;

    // -------------------------
    // Test ComeOutPhase
    // -------------------------
    ComeOutPhase comeOut;

    // Test natural
    Roll roll1(die1, die2);
    while (roll1.roll_value() != 7 && roll1.roll_value() != 11) {
        roll1.roll_dice();
    }
    assert(comeOut.get_outcome(&roll1) == RollOutcome::natural);
    std::cout << "ComeOutPhase natural test passed!\n";

    // Test craps
    Roll roll2(die1, die2);
    while (roll2.roll_value() != 2 && roll2.roll_value() != 3 && roll2.roll_value() != 12) {
        roll2.roll_dice();
    }
    assert(comeOut.get_outcome(&roll2) == RollOutcome::craps);
    std::cout << "ComeOutPhase craps test passed!\n";

    // Test point
    Roll roll3(die1, die2);
    while (roll3.roll_value() == 2 || roll3.roll_value() == 3 || roll3.roll_value() == 7 || roll3.roll_value() == 11 || roll3.roll_value() == 12) {
        roll3.roll_dice();
    }
    assert(comeOut.get_outcome(&roll3) == RollOutcome::point);
    std::cout << "ComeOutPhase point test passed!\n";

    // -------------------------
    // Test PointPhase
    // -------------------------
    int pointValue = 5; // Example point
    PointPhase pointPhase(pointValue);

    // Roll equal to point -> RollOutcome::point
    Roll roll4(die1, die2);
    while (roll4.roll_value() != pointValue) {
        roll4.roll_dice();
    }
    assert(pointPhase.get_outcome(&roll4) == RollOutcome::point);
    std::cout << "PointPhase point test passed!\n";

    // Roll equal to 7 -> RollOutcome::seven_out
    Roll roll5(die1, die2);
    while (roll5.roll_value() != 7) {
        roll5.roll_dice();
    }
    assert(pointPhase.get_outcome(&roll5) == RollOutcome::seven_out);
    std::cout << "PointPhase seven_out test passed!\n";

    // Roll any other value not point or 7 -> RollOutcome::nopoint
    Roll roll6(die1, die2);
    while (roll6.roll_value() == pointValue || roll6.roll_value() == 7) {
        roll6.roll_dice();
    }
    assert(pointPhase.get_outcome(&roll6) == RollOutcome::nopoint);
    std::cout << "PointPhase nopoint test passed!\n";

    std::cout << "All Phase tests passed successfully!\n";

    return 0;
}

