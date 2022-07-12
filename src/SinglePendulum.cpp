#include "../include/Environments/SinglePendulum.hpp"

SinglePendulum::SinglePendulum(double tf, double dt, Eigen::VectorXd x) {
    Environment::x = x;
    Environment::tf = tf;
    Environment::dt = dt;
}

void SinglePendulum::setLink(double l) {
    SinglePendulum::l = l;
}

void SinglePendulum::setMass(double m) {
    SinglePendulum::m = m;
}

double SinglePendulum::getLink() {
    return SinglePendulum::l;
}

double SinglePendulum::getMass() {
    return SinglePendulum::m;
}

Eigen::VectorXd SinglePendulum::f(Eigen::VectorXd x, Eigen::VectorXd u) {
    return Eigen::Vector2d(x(1), (1.0 / m * pow(l, 2)) * (u(0) - m * GRAVITY * l * sin(x(0))));
}