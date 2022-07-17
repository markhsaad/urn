#include "../include/Simulations/URN1.hpp"
#include "../include/Simulations/URN2.hpp"

int main() {
    /****************************** URN 1 ******************************/
    // doublePendulumWithZeroInput();
    // doublePendulumWithFeedbackLinearization();

    /****************************** URN 2 ******************************/
    // Set bounds to be whole number. Otherwise the numbers may not be equally spaced and streamplot() in Python will have a stroke

    // phasePortraitWithZeroInput(-3, 3, -3, 3, 150, 150);
    phasePortraitWithDamping(-3, 3, -3, 3, 150, 150);

    return 0;
}