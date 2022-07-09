#include "../include/Environment.hpp"

Environment::Environment() {
    X.reserve(round(tf / dt));
}

Eigen::VectorXd Environment::getCurrentState() {
    return x;
}

double Environment::getSamplingTime() {
    return dt;
}

double Environment::getSimulationTime() {
    return tf;
}

Eigen::VectorXd Environment::step(Eigen::VectorXd u) {
    // Perform a fourth-order Runge-Kutta update
    Eigen::VectorXd k1 = this->f(x                , u);
    Eigen::VectorXd k2 = this->f(x + (dt / 2) * k1, u);
    Eigen::VectorXd k3 = this->f(x + (dt / 2) * k2, u);
    Eigen::VectorXd k4 = this->f(x +  dt      * k3, u);

    x += (1.0 / 6.0) * dt * (k1 + 2 * k2 + 2 * k3 + k4);

    // Log the state and the input
    X.push_back(x);
    U.push_back(u);

    // If done simulating, stop running and save
    if (isDone()) {
        save("state.txt", X);
        save("input.txt", U);
    };

    return x;
}

bool Environment::isDone() {
    // Done when enough samples have been collected
    return (X.size() >= round(tf / dt));
}

void save(std::string filename, std::vector<Eigen::VectorXd> X) {
    std::ofstream file;
    file.open(filename);

    for(int i = 0; i < X.size(); i++) {
        for(int j = 0; j < X[i].size(); j++) {
            file << X[i](j) << "\t";
        }
        file << std::endl;
    }
    file.close();
}