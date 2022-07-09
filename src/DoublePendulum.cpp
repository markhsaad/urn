#include "../include/DoublePendulum.hpp"

DoublePendulum::DoublePendulum(double tf, double dt, Eigen::VectorXd x) {
    Environment::x = x;
    Environment::tf = tf;
    Environment::dt = dt;
}

void DoublePendulum::setLink1(double l1) {
    DoublePendulum::l1 = l1;
}

void DoublePendulum::setLink2(double l2) {
    DoublePendulum::l2 = l2;
}

void DoublePendulum::setMass1(double m1) {
    DoublePendulum::m1 = m1;
}

void DoublePendulum::setMass2(double m2) {
    DoublePendulum::m2 = m2;
}

double DoublePendulum::getLink1() {
    return DoublePendulum::l1;
}

double DoublePendulum::getLink2() {
    return DoublePendulum::l2;
}

double DoublePendulum::getMass1() {
    return DoublePendulum::m1;
}

double DoublePendulum::getMass2() {
    return DoublePendulum::m2;
}

Eigen::VectorXd DoublePendulum::f(Eigen::VectorXd x, Eigen::VectorXd u) {
    // Parse the state
    double  q1 = x(0); // theta_1
    double dq1 = x(1); // theta_1_dot
    double  q2 = x(2); // theta_2
    double dq2 = x(3); // theta_2_dot

    // Compute M
    Eigen::Matrix2d M;
    M << (m1 + m2) * l1,    m2 * l2 * cos(q1 - q2),    m2 * l1 * cos(q1 - q2),    m2 * l2;

    // Compute C
    Eigen::Matrix2d C;
    C << 0,    m2 * l2 * dq2 * sin(q1 - q2),    -m2 * l1 * dq1 * sin(q1 - q2),    0;

    // Compute tau_g
    Eigen::Vector2d tau_g;
    tau_g << -(m1 + m2) * GRAVITY * sin(q1),    -m2 * GRAVITY * sin(q2);

    // Compute (or I guess, define, in this case) B
    Eigen::Matrix2d B = Eigen::Matrix2d::Identity();

    // Compute the accelerations
    Eigen::Vector2d ddq = M.inverse() * (B * u + tau_g - C * Eigen::Vector2d(dq1, dq2));

    // Compute and return dx
    Eigen::Vector4d dx = Eigen::Vector4d(dq1, ddq(0), dq2, ddq(1));
    return dx;
}