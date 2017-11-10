#include <iostream>
#include "factorial.h"

int main()
{
	int numberFactorials;
	std::cout<<"Please enter the amount of factorials you wish to display"<<std::endl;
	std::cin>>numberFactorials;
	for(int i=1; i<=numberFactorials; i++){
		factorial(i);
	}
}
