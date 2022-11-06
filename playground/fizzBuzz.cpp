#include <iostream>
#include "util.h"

using namespace std;

void fizzBuzz(int rangeStart, int rangeEnd)
{

    for (size_t i = rangeStart; i < rangeEnd; i++)
    {
        bool fizz = i % 3 == 0;
        bool buzz = i % 5 == 0;

        if (!fizz && !buzz)
        {
            std::cout << std::to_string(i) << std::endl;
        }
        else if (fizz && buzz)
        {
            std::cout << "FizzBuzz" << std::endl;
        }
        else if (buzz)
        {
            std::cout << "Buzz" << std::endl;
        }
        else if (fizz)
        {
            std::cout << "Fizz" << std::endl;
        }
    }
}

int main()
{
    fizzBuzz(1, 100);
}