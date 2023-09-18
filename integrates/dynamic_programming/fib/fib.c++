#include <iostream>
// #include "/opt/homebrew/include/opencv4/opencv2/opencv.hp
// #include <opencv.hpp>

using namespace std;

int fib1(int n)
{
    if (n <= 2) 
        return (1);
    return (fib1(n - 1) + fib1(n - 2));
}

int main(void)
{
    int n = 7;
    std::cout << "simple fib of " << n << " = " << fib1(n) << std::endl;
    // std::cout << "simple fib of " ;
    return (0);
}