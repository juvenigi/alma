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
  for(unsigned int i = skip; i<length; i++){
    if(sieve[i] == true){return i+1;}
  }
  return length+1;
}

void init_range(bool * sieve, unsigned int max){
  for(int i = 0; i<max; i++){
    sieve[i] = true;
  }
}

// strategy
// have an array of zeroes = prime until proven composite
// find smallest prime
// iterate and flip prime multiples (1s)
// check if our prime is not bigger than half of the range

unsigned long int eras_prime(unsigned int max){
  bool * sieve = new bool[max-1];
  init_range(sieve,max);
  unsigned int prime = 2;
  sieve[0] = 1; // 1 is not prime
  sieve[1] = 1; // 2 is is prime
  while(prime < max){
    for(long int mult = 2; mult*prime<=max; mult++){
      sieve[mult*prime-1] = 0;
      //cout << mult*prime << endl;
    }
    prime = eras_small(sieve,max,prime);
    cout << prime << endl;
  }
  unsigned long long int sum = 0;
  for(unsigned int i = 0; i<max; i++){
    sum += sieve[i]*i;
  }
  return sum;
}

int main(void){
  unsigned int is = 10e6;
  unsigned int all_numbers = is * (is/2); // 1 + 2 + 3 + ... + 10e6
  unsigned int eras_prime_s = eras_prime(10);
  //cout << all_numbers << endl;
  cout << eras_prime_s << endl;
  //cout << naive_prime(iterations) << endl;
  return 0;
}
