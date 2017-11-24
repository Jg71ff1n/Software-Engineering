/*
 * Created by nas, 28/03/17
 */

#ifndef PRIMEFACTORS_NAS280317
#define PRIMEFACTORS_NAS280317

#include <list>
#include <limits>
#include "string.h"

/*
Compute the list of prime factors of the parameter.
The list should be sequenced in ascending order.
E.g. primeFactors(18) should return {2,3,3}.
If the parameter is 0 or 1, the resulting list should be empty.
*/
std::list<unsigned long int> primeFactors(unsigned long int input);
int greatestCommonDivisor(int x, int y);
void seiveOfE();

#endif
