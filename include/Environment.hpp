#include <eigen3/Eigen/Dense>
#include <iostream>
#include <fstream>
#include <vector>

class Environment {
    public:
        // Constructor(s)
        Environment();

        // Variable(s)
        const double GRAVITY = 9.81; // gravitational acceleration [m/s^2]

        // Getter(s)
        Eigen::VectorXd getCurrentState();
        double getSamplingTime();
        double getSimulationTime();

        // Function to update the environment given an input u and a time step dt using RK4
        Eigen::VectorXd step(Eigen::VectorXd u);

        // Function to check when the simulation is done
        bool isDone();
    
    private:
        // Variable(s)
        std::vector<Eigen::VectorXd> X; // array to store the state over time
        std::vector<Eigen::VectorXd> U; // array to store the input over time

        // Pure virtual function to define the dynamics of the environment: dx/dt = f(x, u)
        virtual Eigen::VectorXd f(Eigen::VectorXd x, Eigen::VectorXd u) = 0;

    protected:
        // Variable(s)
        Eigen::VectorXd x; // current state of the system
        double dt = 0.001; // sampling time [s]
        double tf = 10; // simulation time [s]
};

// Function to save the data to a text file
void save(std::string filename, std::vector<Eigen::VectorXd> X);