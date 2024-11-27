#include <iostream>
#include <cmath>

int main() 
{
    double x = 2.3;
    double y = 4.5;

    // calculating magnitude of the vector
    double mag = std::sqrt(x*x+y*y);

    // result
    std::cout<<"Magnitude of vector is:" <<mag<<std::endl;
    return 0;

}