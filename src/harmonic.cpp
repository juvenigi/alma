#include<iostream>

using namespace std;
float harmonic(int iterations){
  float sum = 0.0;
  for(int i = 1; i<=iterations; i++){
    sum += 1./i;
  }
  return sum;  
}

float inv_harmonic(int iterations){
  float sum = 0.0;
  for(int i = iterations; i>0; i--){
    sum += 1./i;
  }
  return sum;
}

int main(void){

  int n = 10e5;
  //cin << 5;

  cout << harmonic(n) << endl;
  cout << inv_harmonic(n) << endl;
  /* Explanation:
   * rounding error happens every time during addition, resulting in diverging results.
   */
  return 0;
}
