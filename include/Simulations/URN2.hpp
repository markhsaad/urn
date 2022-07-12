#include "../Environments/SinglePendulum.hpp"

void singlePendulumWithZeroInput() {
    // Create the environment with a simulation time of 10 s and a sampling time of 0.001 s (default)
    SinglePendulum sp;

    // Simulate with zero input
    Eigen::VectorXd u = Eigen::VectorXd::Zero(1); // input must be of type VectorXd and there is no Vector1d so... here we are
    while(!sp.isDone()) {
        sp.step(u);
    }
}