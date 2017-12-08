/*
 * Created by nas, 28/03/17
 */

#ifndef PRIMEFACTORS_NAS280317
#define PRIMEFACTORS_NAS280317

#include <list>
#include <limits>
#include <cmath>
#include <iostream>
#include <chrono>
#include "string.h"

/*
Compute the list of prime factors of the parameter.
The list should be sequenced in ascending order.
E.g. primeFactors(18) should return {2,3,3}.
If the parameter is 0 or 1, the resulting list should be empty.
*/
std::list<unsigned long int> primeFactors(unsigned long int input);
void sieveOfE();
static std::list<unsigned long int> trialDivisionUp(unsigned long int input);
static std::list<unsigned long int> trialDivisionDown(unsigned long int input);
void *pthread_wrapper_up(void *arg);
void *pthread_wrapper_down(void *arg);
#endif

