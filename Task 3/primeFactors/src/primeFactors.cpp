#include "primeFactors.h"

using namespace std;

const int MAX = 10000000;
const int MIN = 0;
const int TRIAL_LIMIT = 500000
bool isPrime[MAX];


list<unsigned long int> primeFactors(unsigned long int input){
	list<unsigned long int> output;
	unsigned long long int original_factor, current_factor, top_factor;
	sieveOfE();
	//Loop finds for all prime factors/Checks first to see if number is prime
	while(checkPrime(input)!=true){
		//Find first factor
		original_factor=findFactor(input);
		current_factor=top_factor=original_factor;
		//NEW LOOP TO GO DOWN TREE
		while(checkPrime(top_factor!=true){
			//Recursive loop to find prime factor from top_factor
			while(checkPrime(current_factor)!=true) {
				current_factor=findFactor(current_factor);
			}
			output.pushback(current_factor);
			top_factor=top_factor/current_factor;
			current_factor=top_factor;
		}
		output.pushback(top_factor);
		//Removes original_factor from input. After branch is empty
		input=input/original_factor;
	}
	
	return output;
}

int greatestCommonDivisor(int x, int y){
	//Recursive gcd finder
	if(y==0){
		return x;
	}
	else{
		return greatestCommonDivisor(y,x%y);
	}
}

void sieveOfE(){
	memset(isPrime,true,sizeof(isPrime));
	int i,j,k;
	isPrime[1]=false;
	for(i=4; i<=MAX;i+=2){
		isPrime[i]=false;	
	}
	for (i=3;i<=MIN;i+=2){
		if(isPrime[i]){
			for(j=i*i,k=i<<1;j<=MAX;j+=k){
				isPrime[j]=false;
			}
		}
	}
}

unsigned long long int findFactor(unsigned long long int input){
	unsigned long long int factor;
	if (input<=TRIAL_LIMIT){
		 factor=trialDivision(input);
	}
	else{
		factor=rhoFactor(input);
	}
}

unsigned long long int rhoFactor(unsigned long long int input){

}

unsigned long long int trialDivision(unsigned long long int input){

}

bool checkPrime(unsigned long long int input){
	if (input<MAX){
		if (isPrime[input]){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		if(millerPrime(input)){
			return true;
		}
		else{
			return false;
		}
	}
}

bool millerPrime(unsigned long long int input){

}

