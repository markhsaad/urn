#include "Environment.hpp"

class DoublePendulum : public Environment {
    public:
        // Constructor(s)
        DoublePendulum(double tf, double dt, Eigen::VectorXd x = Eigen::Vector4d(M_PI / 4, 0, 3 * M_PI / 4, 0));

        // Setter(s)
        void setState(Eigen::VectorXd x);
        void setLink1(double l1);
        void setLink2(double l2);
        void setMass1(double m1);
        void setMass2(double m2);

        // Getter(s)
        Eigen::VectorXd getState();
        double getLink1();
        double getLink2();
        double getMass1();
        double getMass2();

        // Function to define the dynamics of the double pendulum environment 
        Eigen::VectorXd f(Eigen::VectorXd x, Eigen::VectorXd u);
    
    private:
        double l1 = 1; // link 1 length [m]
        double l2 = 1; // link 2 length [m]
        double m1 = 1; // mass 1 mass   [kg]
        double m2 = 1; // mass 2 mass   [kg]
};