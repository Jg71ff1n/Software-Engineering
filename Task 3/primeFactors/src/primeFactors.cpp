#include "primeFactors.h"
using namespace std;

const int MAX_SIEVE = 10000000;
static bool isPrime[MAX_SIEVE];
static bool isSieveCalled=false;
/* 
Prime Factors:
The first set of logic satements are input sanitation such that any number less than to 2 will be not added to the prime factor outputs, due to the first prime number being 2 which should 2 be entered will instantly return due to the special case of it being the only even prime number and as such causing small issues with code when it is entered on its own.

Second if statement is a check to ensure that the sieve of Eratosthenes is only called once, that being on the first prime number passed to it in a sequence due to the sieve's boolean array being a static variable.

This array is from 0-MAX_SIEVE with each natural number being a location in memory that contains a true/false value as to whether that number is a prime.

It then calls the function trialDivision outputting the list of prime factors to the list called output; which is then returned
*/
list<unsigned long int> primeFactors(unsigned long int input){
	list<unsigned long int> output = {};
	if (input<=1){
		return output;
	}
	if (input==2){
		output.push_back(input);
		return output;
	}
	if(isSieveCalled==false){
		sieveOfE();
	}
	output=trialDivision(input);
	return output;
}
/*
Sieve of E/Sieve of Eratosthenes(Shortened for ease of typing and use):
A basic overview for the sieve is that it creates a list; or in this case a boolean array, for memory saving purposes; as I do not need to store a data value and a prime flag.

Within this list we start at the number 2 and iterate for each natural number up to a specified size. For each iteration we remove every following number that is a multiple of the original number. So in this case I set the iterator to the square of the original number as this saves us from setting a prime flag multiple times. For instance if the prime number is 3 there is no need to state that 3*2 will not be prime as we will have already set the prime flag for it when we removed all multiple of 2 i.e 2*3 will have been removed already. 

Algorithmic understandings and optimisations gained from:
Melissa E. O’Neill, 2009[Online]. Journal of Functional Programming  Cambridge: Cambridge University Press
Available at:https://www.cs.hmc.edu/~oneill/papers/Sieve-JFP.pdf [Accessed 29th December 2017]
*/
void sieveOfE(){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0]=false;
    isPrime[1]=false;
	for (long int i=2; i<MAX_SIEVE; i++)
    {
        //If isPrime[i] has not been changed by previous numbers, must be a prime
        if (isPrime[i] == true)
        {
            //Remove all following multiples of the number
            for (long int j=i*i; j<=MAX_SIEVE; j +=i)
                isPrime[j] = false;
        }
    }
}
/*
Trial division:
This algorithim is an extension of the standard trial divison method that was found on Khan Academy. 

The base algorithm works by taking a number and checking to see if it divides into the inputted number using the check for  the modulo of the input equalling 0 indicating that current iterated number is a divisor. After which the divisor is added to the prime factor list output, and then we divide the number to be factorised by the divisor. Iterating to the next number.

The extension I implemented is to first incorporate the prime sieve as a check to see if the number that is a factor is a prime number. This reduces the amount of subsequent divisions that must occur as I am searching for the leaves of the factor tree. Multiple tests have confirmed this speed up. 

Another consideration that had to be made was in the while loop limiter, to improve search speed I used the mathematical fact that any number made of two or more primes must be n=x*y*z... and by considering the fact that the smallest amount of primes possibly used is 2 and the max size the could create would be a square number. Meaning that n=x*x, however should x*x be implemented interger overflow is a possibility and such by re-arranging the equation we can be left with n/x=x. This allows for searching numbers less than the square root of the inputted number. 

Finally by taking an idea used in the sieve for the elimination of multiples of the factor numbers we can speed up the search by skipping all even numbers. This does pose an issue as it means that 2 will be missed out, as such a secondary loop is implemented to solve this issue as it will remove all factors of 2 from the number, which in turn also halves the inputted number straight away, reducing the number that has to be trialed up to in the main loop.

Base understanding and small improvements gained from:
Khan Academy, 2017.COMPUTER SCIENCE-> JOURNEY INTO CRYPTOGRAPHY-> Primality test-> Trial Division [Online] Khan Academy
Available at:https://www.khanacademy.org/computing/computer-science/cryptography/comp-number-theory/a/trial-division [Accessed 29th December 2017] 
*/
list<unsigned long int> trialDivision(unsigned long int input){
	list<unsigned long int> output={};
	unsigned long int i=3;
	//WHILE LOOP FOR DIVISION BY TWO
	while(input %2==0){
			output.push_back(2);
			input/=2;
		}
	while(i<=input/i){
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
