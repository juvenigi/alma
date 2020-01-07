#include <iostream>
#include <math.h>

#define OUT // nice formatting dummy variable

 using namespace std;
/* Math utils */

/* contains: lesson_1 */

unsigned int sanity_sgn(int a){
  return (unsigned int) abs(a);
}

 /* unsigned int sanity_sgn(int a){ */
 /*   unsigned int b; */
 /*   if (a < 0) { */
 /*     b = (unsigned int) -a; */
 /*   } */
 /*   else{ */
 /*     b = (unsigned int) a; */
 /*   } */
 /*   return b; */
 /* } */

void wholediv_pos(unsigned int q, unsigned int n, OUT unsigned int * out){
  if(n==0){throw invalid_argument("cannot divide by zero");}
  unsigned int rest = q % n;
  unsigned int div  = q / n;
  out[0] = div;
  out[1] = rest;
}

void wholediv_pos_basic(unsigned int m, unsigned int n, OUT unsigned int * out){
  if(n==0){throw invalid_argument("cannot divide by zero");}
  unsigned int r;
  unsigned int q = 0;
  while(m >= n){
    m = m-n;
    q++;
  }
  r = m;
  out[0] = q;
  out[1] = r;
}

void wholediv(int m, int n, OUT int * out){
  if(n==0){throw invalid_argument("cannot divide by zero");}

  unsigned int mu = sanity_sgn(m);
  unsigned int nu = sanity_sgn(n);

  static unsigned int w_result[2];
  wholediv_pos_basic(mu,nu,w_result);

  if(m<0 && n<0){
    out[0] = (int) w_result[0];
    out[1] = -1 * (int) w_result[1];
  }else if(m*n>0){
    out[0] = (int) w_result[0];
    out[1] = (int) w_result[1];
  }else if(m<0){ // negative divisor
    out[0] = -1 * (int) w_result[0];
    out[1] = -1 * (int) w_result[1];
  }else{ // negative number
    out[0] = -1 * (int) w_result[0];
    out[1] = (int) w_result[1];
  }
}

unsigned int m_mod(unsigned int a, unsigned int b){
  static unsigned int temp[2];
  wholediv_pos_basic(a,b,temp);
  return temp[1];
}

int m_mod_2(int a, int b){
  static int temp[2];
  wholediv(a,b,temp);
  return temp[1];
}

int gcd(int a, int b) {
  if (b == 0){return a;}
  return gcd(b, a % b);
}

void quot(int a, int b, OUT int * out){
  if(b == 0){throw invalid_argument("received zero");}
  int div = gcd(a,b); // apparently you need c++17 for that
  out[0] = a / div;
  out[1] = b / div;
}

bool is_powtwo(unsigned int a){
  int i = 0;
  int h;
  do{
    h = a-pow(2,i);
    i++;
  }while(h > 0);

  if(h == 0){
    return true;
  }else{
    return false;
  }
}

bool is_powtwo_two(unsigned int a){
  if(a & (a-1)){
    return false;
  }else{
    return true;
  }
}
