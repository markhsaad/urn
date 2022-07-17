#include "../Environments/SinglePendulum.hpp"

void phasePortraitWithZeroInput(double x1i, double x1f, double x2i, double x2f, double nx1, double nx2) {
    // Create the environment
    SinglePendulum sp;

    // Set zero input
    Eigen::VectorXd u(1);
    u << 0;

    // Initialize array to store the values
    std::vector<Eigen::VectorXd> P;

    // Compute dx/dt for each coordinate pair
    for(int i = 0; i < nx1; i++) {
        for(int j = 0; j < nx2; j++) {
            // Compute x1 and x2
            double x1 = x1i + i * (x1f - x1i) / nx1;
            double x2 = x2i + j * (x2f - x2i) / nx2;

            // Generate the state vector
            Eigen::Vector2d x(x1, x2);

            // Compute dx/dt
            Eigen::Vector2d dxdt = sp.f(x, u);

            // Store the values in an std::vector
            P.push_back(Eigen::Vector4d(x(0), x(1), dxdt(0), dxdt(1)));
        }
    }

    // Save the data to a text file
    save("phasePortrait.txt", P);
}

void phasePortraitWithDamping(double x1i, double x1f, double x2i, double x2f, double nx1, double nx2) {
    // Create the environment
    SinglePendulum sp;

    // Set zero input
    Eigen::VectorXd u(1);

    // Initialize array to store the values
    std::vector<Eigen::VectorXd> P;

    // Compute dx/dt for each coordinate pair
    for(int i = 0; i < nx1; i++) {
        for(int j = 0; j < nx2; j++) {
            // Compute x1 and x2
            double x1 = x1i + i * (x1f - x1i) / nx1;
            double x2 = x2i + j * (x2f - x2i) / nx2;

            // Generate the state vector
            Eigen::Vector2d x(x1, x2);

            // Add damping
            u << -x2;

            // Compute dx/dt
            Eigen::Vector2d dxdt = sp.f(x, u);

            // Store the values in an std::vector
            P.push_back(Eigen::Vector4d(x(0), x(1), dxdt(0), dxdt(1)));
        }
    }

    // Save the data to a text file
    save("phasePortrait.txt", P);
}