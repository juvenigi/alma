#include<iostream>
#include<math.h>

using namespace std;
bool isprime(int number){
  for(int n=2;n<sqrt((double) number);n++){
    if(number%n==0){return false;}
  }
  return true;
}

unsigned long int naive_prime(unsigned int iterations){ 
  unsigned long int sum = 0;
  for(unsigned int i = 2; i<=iterations; i++){
    if(isprime(i)){
      sum += i;
    }
  }
  return sum;
}

unsigned int eras_small(bool * sieve, unsigned int length, unsigned int skip){
  for(unsigned int i = skip; i<=length/2; i++){
    if(sieve[i] == 0){return sieve[i];}
  }
  return length;
}

void init_range(bool * sieve, max){
  for(int i = 0; i<max; i++){
    sieve[i] == 0;
  }
}

// strategy
// have an array of zeroes = prime until proven composite
// find smallest prime
// iterate and flip prime multiples (1s)
// check if our prime is not bigger than half of the range
  
unsigned long int eras_prime(unisgned int max){
  bool * sieve = new bool[max-1];
  init_range(sieve,max);
  unsigned int prime = 2;
  sieve[0] = 0;
  sieve[1] = 0;
  while(prime < max/2){
    for(unsigned int i = prime
    eras_small(sieve)
  }
  return sum;
}

int main(void){
  unsigned int is = 10e6;
  unsigned int all_numbers = is * (is/2); // 1 + 2 + 3 + ... + 10e6
  cout << naive_prime(iterations) << endl;
  return 0;
}
