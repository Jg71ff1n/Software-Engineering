#include "primeFactors.h"
void sieveOfE();
using namespace std;
using std::chrono::steady_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;

const int MAX_SIEVE = 10000000;
const int SIEVE_SIZE=(MAX_SIEVE/2)+1;
static bool isPrime[MAX_SIEVE];
static bool isSieveCalled=false;

list<unsigned long int> primeFactors(unsigned long int input){
	list<unsigned long int> output = {};
	//unsigned long int original_factor, current_factor, top_factor;
	if (input<=1){
		return output;
	}
	//steady_clock::time_point startTime = steady_clock::now();
	if(isSieveCalled==false){
		sieveOfE();		
		isSieveCalled=true;
	}
	//steady_clock::time_point finishTime = steady_clock::now();
	//milliseconds timeTaken = duration_cast<milliseconds>(finishTime - startTime);
	//cout << "Time taken: " << timeTaken.count() << "ms" << endl;
	//Loop finds for all prime factors/Checks first to see if number is prime
	output=trialDivision(input);
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
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0]=false;
    isPrime[1]=false;
	for (long int p=2; p<MAX_SIEVE; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (isPrime[p] == true)
        {
            // Update all multiples of p
            for (long int i=p*p; i<=MAX_SIEVE; i +=p)
                isPrime[i] = false;
        }
    }
    //Output all primes
    /*for (int i=0; i<100;i++){
    	if(isPrime[i]==true){
    		cout<<i<<endl;
    	}
    }*/
    isPrime[2]=true;
}

unsigned long int findFactor(unsigned long int input){
	unsigned long int factor;
	if (input<=MAX_SIEVE){
		 //factor=trialDivision(input);
	}
	else{
		factor=rhoFactor(input);
	}
}

unsigned long int rhoFactor(unsigned long int input){

}

list<unsigned long int> trialDivision(unsigned long int input){
	list<unsigned long int> output={};
	unsigned long int i;
	i=3;
	//WHILE LOOP FOR DIVISION BY TWO
	while(input %2==0){
			output.push_back(2);
			input=input/2;
		}
	while(i<=input/i){
		/*if (input %2==0){
			output.push_back(2);
			input=input/2;
		}*/
		//Check to see if sieve check is too slow
		if (i<MAX_SIEVE){
			if (isPrime[i]==true && input % i==0){
				output.push_back(i);
				input/=i;
			}
			else{
				i+=2;
			}
		}
		else{
			if (input % i==0){
				output.push_back(i);
				input/=i;
			}
			else{
				i+=2;
			}
		}
	}
	output.push_back(input);
	return output;
}

bool checkPrime(unsigned long int input){
	if (input<MAX_SIEVE){
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

bool millerPrime(unsigned long int input){
	int certaintyFactor=10;
	unsigned long int a,x,d;
	
	for (int i=0; i<certaintyFactor;i++){
	}
}

