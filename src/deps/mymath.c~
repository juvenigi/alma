#include <stdio.h>
#include <math.h>

#ifndef EULER
#define EULER
#define E 2.71828182845904523536
#endif /* EULER */

#ifndef PI
#define PI 3.141592653
#endif /* PI */

//#ifndef BOOL
//#define BOOL
//typedef _Bool bool;
//static const bool true = 1;
//static const bool false = 0;
//#endif /* BOOL */

int my_abs(int a){ // just use abs provided by math.h
  if(a<0){return 0-a;}
  else   {return a;}
}

int gauss_up(double number){ // gauss_down is just normal typecasting
  if( (double) ((int) number) - number != 0 ){
   return (int) number + 1;
  }else{
    return (int) number;
  }
}

bool isprimep(int number){
  for(int n=2;n<sqrt((double) number);n++){
    if(number%n==0){return false;}
  }
  return true;
}

double logbase(double a_base, double value){
  return log(value)/log(a_base);
}

int commondiv(int a,int b){
  while (a!=0&&b!=0){
    if (a>b){a = a-b;}
    else    {b = b-a;}
  }
  if(a==0){return b;}
  else    {return a;}
}

double rootbase(int wop, double value){
  double power = 1. / (double) wop;
  return pow(value,power);
}

double mag(double a, double b){ //magnitude
  if(a>b){
    return a-b;
  }else{
    return b-a;
  }
}

double m_sqrt(double value){
  double x,y = 1.;
  while(mag(x,y)>10e-8){
    x = y;
    y = (x+(value/x))/2;
  }
  return x;
}

/* double my_pow(double power, double value){} */

/* double naive_pow(){} */

double e_pow(double value, double power){
  return exp(power * log(value)); // e^ln(x) = x -> e^2*ln(x) = x^2
}

/* unsigned int fac(unsigned int value){ */

/* } */

unsigned int naive_fac(unsigned int value){
  unsigned int result = 1;
  for(int i = value; i>1; i--){
    result *= i;
  }
  return result;
}

/* double tricosinelaw(double tri_len_a, double tri_len_b){ */

/* } */


double * binomialsolve(double a, double b, double c){
  static double r_vals[2];
    for(int i=0;i<=1;i++){
      r_vals[i] = ((-1. * b
                    + (2. * i - 1)  // plus-minus sign
                    * sqrt(b * b - 4. * a * c)) // determinant
                   / (2. * a));
    }
  return r_vals;
}

double cosine(double x){
  int i_max = 10e6;
  double summand,result = 1.;
  for(int i=1;i<i_max;i++){
    summand = (-1.*x*x)/((2.*i)*((2.*i)-1.)) * summand; // done explicitly to avoid integer overflow
    result += summand;
  }
  return result;
}

double ree_man(double s){
  double sum;
  int MAX_I= 10e5;
  for(int i=1;i<=MAX_I;i++){
    sum += pow(i,-1*s);
  }
  return sum;
}

/* int main(void){ */
/*   printf("%f\n",m_sqrt(5)); */
/*   printf("%f\n",sqrt(5)); */

/*   return 0; */
/* } */
