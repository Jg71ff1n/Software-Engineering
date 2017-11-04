/*
 * Created by nas, 09/09/16
 */

#include <iostream>

#include "prime.h"

int main()
{
    int n;

    std::cout << "Enter a natural number: ";
    std::cin >> n;

    if (isPrime(n))
    {
        std::cout << n << " is a prime number." << std::endl;
    }
    else
    {
        std::cout << n << " is not a prime number." << std::endl;
    }
}
