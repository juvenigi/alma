#include<iostream>
#include<string>
#include<bitset>
#include<math.h>

using namespace std;

bool is_palindrome(unsigned long long int number, int base){
  unsigned long long int reversed = 0;
  unsigned long long int k = number;
  while(k>0){
    reversed = base * reversed + (k % base);
    k = k/base;
  }
  return number == reversed;
}

unsigned long long int palindrome(unsigned long int input, int base, bool isOdd){
  unsigned long long int palin = input;
  unsigned long long int k = input;
  if(isOdd){
    k /= base; // ab -> aba if odd , ab -> abba if even
  }
  while(k>0){
    palin = palin * base + (k % base);
    k /= base;
  }
  return palin;
}

unsigned long long int sum_palindromes(unsigned long long int lim){
  unsigned long long int summand = 0;
  unsigned long long int sum = 0;
  unsigned long int i = 1;
  while(summand <= lim){
    summand = palindrome(i,10,0);
    if(is_palindrome(summand,2)){
      sum += summand;
      cout << summand << endl;
    }
    ++i;
  }
  i = 0;
  summand = 0;
  while(summand <= lim){
    summand = palindrome(i,10,1);
    if(is_palindrome(summand,2)){
      sum += summand;
      cout << summand << endl;;
    }
    ++i;
  }
  cout << endl;
  return sum;
}

int main(void){
  cout
    //<< palindrome(1,10,0) << endl
    //<< palindrome(1,10,1) << endl
    //<< is_palindrome(11,2)
    << sum_palindromes(10e9) << endl
    << endl;
  return 0;
}
