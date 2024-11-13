#include <iostream>
#include <cmath>

int main()
{
    // take user input as a double value
    double x, y;

    std::cout << "Enter the value of x component of the vector: ";
    std::cin >> x;
    std::cout << "Enter the value of y component of the vector: ";
    std::cin >> y;

    // calculate the magnitude of the vector
    double mag = std::sqrt(x*x+y*y);

    // result 
    std::cout<< "Magnitude of vector is: "<<mag<<std::endl;
    return 0;

}
