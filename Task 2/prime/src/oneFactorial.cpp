#include "factorial.h"
#include <iostream>

int main(){
	int n;
	std::cout<<"Please enter a number between 1 and 20"<<std::endl;
	while(true){
		std::cin>>n;
		if(1<=n && n<=20){
			break;
		}
		else{
			std::cout<<"Please enter a number between 1 and 20"<<std::endl;
		}
	}
	factorial(n);
	return 0;
}
