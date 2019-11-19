#include<iostream>
#include<math.h>

using namespace std;

bool isprime(int number){
  for(int n=2;n<sqrt((double) number);n++){
    if(number%n==0){return false;}
  }
  return true;
}

// int main(void){
//   unsigned int number = 7;
//   cin >> number;

//   cout << isprimep(number) << endl;
  
//   return 0;
//}
