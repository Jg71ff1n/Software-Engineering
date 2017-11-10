#include <iostream>
#include "factorial.h"

void factorial(int n){
	unsigned long long total=1;
		for(int i=1; i<=n; i++){
			total=i*total;
		}
	std::cout<<total<<std::endl;
}
