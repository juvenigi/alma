#include<iostream>
#include<math.h>
#include<quadmath.h>
#include<iomanip>

using namespace std;

double read(){
  double r;
  cin >> r;
  return r;
}

double naivesum(double c,int imax){
  c--; // prep

  for(int i=1;i<=imax;i++){
    c = i*c-1;
    //cout << c <<endl;
  }
  //cout <<endl;
  return c;
}
float fnaivesum(float c,int imax){
  c--; // prep

  for(int i=1;i<=imax;i++){
    c = i*c-1;
    //cout << c <<endl;
  }
  //cout <<endl;
  return c;
}
__float128 lnaivesum(__float128 c,int imax){
  c--; // prep

  for(int i=1;i<=imax;i++){
    c = i*c-1;
    //cout << c <<endl;
  }
  //cout <<endl;
  return c;
}

float mindboggle(int ia, int ib){
  float a = (float) ia;
  float b = (float) ib;

  float a_2=a*a;
  float b_2=b*b;
  float b_4=b_2*b_2;
  float b_6=b_4*b_2;
  float b_8=b_4*b_4;
  return (333.75 - a_2)*b_6 + a_2*(11*a_2*b_2-121*b_4-2)+5.5*b_8+(a)/(2*b);
}

double mindoggle(int ia, int ib){
  double a = (double) ia;
  double b = (double) ib;

  double a_2=a*a;
  double b_2=b*b;
  double b_4=b_2*b_2;
  double b_6=b_4*b_2;
  double b_8=b_4*b_4;
  return (333.75 - a_2)*b_6 + a_2*(11*a_2*b_2-121*b_4-2)+5.5*b_8+(a)/(2*b);
}

__float128 mindlonggle(int ia, int ib){
  __float128 a = (__float128) ia;
  __float128 b = (__float128) ib;

  __float128 a_2=a*a;
  __float128 b_2=b*b;
  __float128 b_4=b_2*b_2;
  __float128 b_6=b_4*b_2;
  __float128 b_8=b_4*b_4;
  return (333.75 - a_2)*b_6 + a_2*(11*a_2*b_2-121*b_4-2)+5.5*b_8+(a)/(2*b);
}

int main(void){
  double c = M_E;
  float fc = M_E;
  __float128 lc = M_Eq;

  int a = 77617;
  int b = 33096;

  cout
    //<< c <<endl
    //<< lc <<endl
    
    << fnaivesum(fc,25)<<endl
    << naivesum(c,25) <<endl
    << setprecision(16) << (double)lnaivesum(lc,25)<<endl
    << mindboggle(a,b)<<endl
    <<  mindoggle(a,b)<<endl
    << setprecision(16) << (long double)mindlonggle(a,b)<<endl
    ;
  return 0;
}
