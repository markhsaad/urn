#include "../include/Simulations/URN1.hpp"
#include "../include/Simulations/URN2.hpp"

int main() {
    /****************************** URN 1 ******************************/
    // doublePendulumWithZeroInput();
    // doublePendulumWithFeedbackLinearization();

    /****************************** URN 2 ******************************/
    // phasePortraitWithZeroInput(-5, 5, -5, 5, 200, 200); // Set bounds to be whole number (e.g. (-10, 10)). Otherwise the numbers may not be equally spaced and streamplot() in Python will have a stroke
    phasePortraitWithDamping(-5, 5, -5, 5, 200, 200);

    return 0;
}