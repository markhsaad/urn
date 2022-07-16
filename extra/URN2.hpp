#include "../Environments/SinglePendulum.hpp"

void singlePendulumWithZeroInput() {
    // Create the environment with a simulation time of 10 s and a sampling time of 0.001 s (default)
    SinglePendulum sp;

    // Simulate
    Eigen::VectorXd u(1);
    u << 0;
    while(!sp.isDone()) {
        sp.step(u);
    }
}

void singlePendulumWithDamping() {
    // Create the environment with a simulation time of 10 s and a sampling time of 0.001 s (default)
    SinglePendulum sp;

    // Get the initial state
    Eigen::Vector2d x = sp.getCurrentState();

    // Simulate
    Eigen::VectorXd u(1);
    while(!sp.isDone()) {
        u << -x(1);
        x = sp.step(u);
    }
}