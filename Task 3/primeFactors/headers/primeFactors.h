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
std::list<unsigned long int> primeFactors(unsigned long int input);//Change to depth first search
int greatestCommonDivisor(int x, int y);//DONE
void sieveOfE();//DONE
unsigned long int rhoFactor(unsigned long int input);//NEED TO IMPLEMENT
std::list<unsigned long int> trialDivision(unsigned long int input);//NEED TO IMPLEMENT
unsigned long int findFactor(unsigned long int input);//DONE
bool millerPrime(unsigned long int input);//NEED TO IMPLEMENT-ADD OVERFLOW CHECK
bool checkPrime(unsigned long int input);//DONE
#endif

//POSSIBLE REDUNDANT CODE

/*while(checkPrime(input)!=true){
		//Find first factor
		original_factor=findFactor(input);
		current_factor=top_factor=original_factor;
		//NEW LOOP TO GO DOWN TREE
		while(checkPrime(top_factor!=true)){
			//Recursive loop to find prime factor from top_factor
			while(checkPrime(current_factor)!=true) {
				current_factor=findFactor(current_factor);
			}
			output.push_back(current_factor);
			top_factor=top_factor/current_factor;
			current_factor=top_factor;
		}
		output.push_back(top_factor);
		//Removes original_factor from input. After branch is empty
		input=input/original_factor;
	}*/

	//steady_clock::time_point startTime = steady_clock::now();

	//steady_clock::time_point finishTime = steady_clock::now();
	//milliseconds timeTaken = duration_cast<milliseconds>(finishTime - startTime);
	//cout << "Time taken: " << timeTaken.count() << "ms" << endl;
