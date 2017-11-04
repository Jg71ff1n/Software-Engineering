/*
 * Created  by rbh, 15/01/11
 * Modified by nas, 09/09/16
 * Modified by nas, 17/11/16
 */

#include <iostream>
#include <chrono>
#include <random>

#include "prime.h"

int main()
{
    // Generate a seed value from the system clock.
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Create a (pseudo-)random number engine, initialised with the seed value.
    std::default_random_engine eng{seed};

    // We want to produce a uniform distribution of integers between 1 and 50.
    std::uniform_int_distribution<int> dist{1,50};

    // Generate a random number, using our distribution and engine.
    int n = dist(eng);

    if (isPrime(n))
    {
        std::cout << n << " is a prime number." << std::endl;
    }
    else
    {
        std::cout << n << " is not a prime number." << std::endl;
    }
}
