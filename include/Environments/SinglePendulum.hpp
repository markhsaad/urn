#pragma once

#include "Environment.hpp"

class SinglePendulum : public Environment {
    public:
        // Constructor(s)
        SinglePendulum(double tf = 10, double dt = 0.001, Eigen::VectorXd x = Eigen::Vector2d(M_PI / 4, 0));

        // Setter(s)
        void setState(Eigen::VectorXd x);
        void setLink(double l);
        void setMass(double m);

        // Getter(s)
        Eigen::VectorXd getState();
        double getLink();
        double getMass();

        // Function to define the dynamics of the double pendulum environment 
        Eigen::VectorXd f(Eigen::VectorXd x, Eigen::VectorXd u);

    private:
        double l = 1; // length [m]
        double m = 1; // mass   [kg]
};