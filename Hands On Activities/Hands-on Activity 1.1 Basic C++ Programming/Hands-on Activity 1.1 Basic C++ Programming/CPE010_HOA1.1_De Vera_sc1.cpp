#include <iostream>
// no using namespace std daw

// function prototyping lesson
class Triangle{
private: // Private class
    double totalAngle, angleA, angleB, angleC;
public: // Public class
// Constructor
    Triangle (double A, double B, double C);
    void setAngles (double A, double B, double C);
    const bool validateTriangle();
};

int main(){
    Triangle set1(50,90,75);
    // Driver code
    if (set1.validateTriangle()){
        std::cout << "The shape is a valid triangle." << std::endl;}
    else {
        std::cout << "The shape is NOT a valid Triangle." << std::endl;}

    return 0;
}

// Constructor
Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

// Setting new angles
void Triangle::setAngles (double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

// Computing the Triangle
const bool Triangle::validateTriangle() {
    return (totalAngle == 180);}
