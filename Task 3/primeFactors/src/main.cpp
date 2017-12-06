#include "primeFactors.h"
#include <iostream>

using namespace std;

int main(){
	unsigned long int input=0;
	list<unsigned long int> output = {};
	cout<<"Please enter a number"<<endl;
	cin>>input;
	output = primeFactors(input);
	cout<<"Factors"<<endl;
	for (unsigned long int f : output){
		cout<<f<<' ';
	}
	//seiveOfE();
}
