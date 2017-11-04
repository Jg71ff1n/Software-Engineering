/*
 * Created  by rbh, 30/01/11
 * Modified by nas, 09/09/16
 * Modified by nas, 24/09/17
 */

#include <cmath>

#include "prime.h"

bool isPrime(int n)
/* This is a rather inefficient implementation.
 * We will consider better approaches in Task 3.
 */
{
    for (int possibleFactor = 2; possibleFactor < n; ++possibleFactor)
    {
        if ((n % possibleFactor) == 0)
        {
            return false;
        }
    }
    return true;
}
