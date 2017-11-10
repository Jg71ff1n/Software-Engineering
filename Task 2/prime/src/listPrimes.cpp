#include <iostream>

#include "prime.h"

int main()
{
	int i=2, PrimesNeeded,PrimesPrinted;
	std::cout<<"Please enter the amount of primes you wish to display"<<std::endl;
	std::cin>>PrimesNeeded;
	while(PrimesPrinted<PrimesNeeded){	
		if (isPrime(i)){
			std::cout<<i<<std::endl;
			PrimesPrinted++;			
		}
		i++;		
	}
}
