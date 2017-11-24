#include "primeFactors.h"

using namespace std;

const unsigned long int MAX = numeric_limits<long int>::max();
const unsigned long int MIN =  100000;
bool isPrime[MAX];


list<unsigned long int> primeFactors(unsigned long int input){
	list<unsigned long int> output;
	int x_fixed=2,cycle_size=2,x=2,factor=1;
	while (factor==1) {
		for (int i=1; i<=cycle_size && factor; i++){
			x=(x*x+1)%input;
			factor = greatestCommonDivisor(x-x_fixed, input);
		}
		cycle_size *=2;
		x_fixed=x;
	}
	output.push_back(factor);
	return output;
}

int greatestCommonDivisor(int x, int y){
	if(y==0){
		return x;
	}
	else{
		return greatestCommonDivisor(y,x%y);
	}
}

void seiveOfE(){
	memset(isPrime,true,sizeof(isPrime));
	int i,j,k;
	isPrime[1]=false;
	for(i=4; i<=MAX;i+=2)
	{
		isPrime[i]=false;	
	}
	for (i=3;i<=MIN;i+=2)
	{
		if(isPrime[i])
		{
			for(j=i*i,k=i<<1;j<=MAX;j+=k)
			{
				isPrime[j]=false;
			}
		}
	}
}
