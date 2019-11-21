#include<complex>
#include<tgmath.h>
#include<iostream>

using namespace std;

typedef double _Complex complex;

int main(void){
  std::complex<double> z(0.0,1.0);
  cout << real(z) << " " << imag(z) <<endl;
  return 0;
}
