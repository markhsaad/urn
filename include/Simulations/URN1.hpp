#include "../Environments/DoublePendulum.hpp"

void doublePendulumWithZeroInput() {
    // Create the environment with a simulation time of 20 s and a sampling time of 0.02 s
    DoublePendulum dp(20, 0.02);

    // Simulate with zero input
    Eigen::Vector2d u(0, 0);
    while(!dp.isDone()) {
        dp.step(u);
    }
}

void doublePendulumWithFeedbackLinearization() {
    // Create the environment with a simulation time of 20 s and a sampling time of 0.02 s
    DoublePendulum dp(10, 0.02);

    // Get the system parameters
    double l1 = dp.getLink1();
    double l2 = dp.getLink2();
    double m1 = dp.getMass1();
    double m2 = dp.getMass2();

    // Define the K matrix
    Eigen::MatrixXd K(2, 4);
    K << 1, 2, 0, 0, 0, 0, 1, 2;

    // Set the desired point
    Eigen::Vector4d xd(M_PI, 0, M_PI, 0);

    // Simulate with feedback Linearization
    Eigen::Vector2d u;
    Eigen::Vector2d ud;
    Eigen::Vector4d x = dp.getCurrentState(); // initial state
    while(!dp.isDone()) {
        // Compute ud
        ud = -K * (x - xd);

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
        tau_g << -(m1 + m2) * dp.GRAVITY * sin(q1),    -m2 * dp.GRAVITY * sin(q2);

        // Compute (or I guess, define, in this case) B
        Eigen::Matrix2d B = Eigen::Matrix2d::Identity();

        // Compute the input
        u = B.inverse() * (M * ud + C * Eigen::Vector2d(dq1, dq2) - tau_g);

        // Step
        x = dp.step(u);
    }
}