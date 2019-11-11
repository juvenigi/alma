#include<iostream>
#include<math.h>
#include<bits/stdc++.h>

#define EPSLIM 10e-7

using namespace std;

int read(){
  int r;
  cin >> r;
  return r;
}

double nt_function(double x, double a); //inverse of 3(a)^(1/3)

/* Binary Search */
double binsearch(double x){
  double low, high;   // Initialize boundary values
  if (x >= 0 && x <= 1){
    low = x;
    high = 1;
  }else{
    low = 1;
    high = x;
    }

  double guess = (low + high) / 2; // juicy part
  while(fabs(nt_function(guess,0) - x) >= EPSLIM){
    cout << fabs(nt_function(guess,0))-x <<endl;
    if(nt_function(guess,0) > x){
      high = guess;
    }else{
      low = guess;
    }
    guess = (low + high) / 2;
  }
  return guess;
}

/* Newton Verfahren */

double nt_function(double x, double a){
  return (x*x*x)/27 - a;
}

double dx_function(double x){
  return (x*x)/9;
}

double newtonmethod(double a){
  double x = 0;
  double xn = 10;
  while(fabs(x-xn) > EPSLIM){
    cout << fabs(x-xn) << endl;
    x = xn;
    xn = xn - ((nt_function(xn,a))/(dx_function(xn)));
  }
  return xn;
}

int main(void){
  double value = read();

  cout << newtonmethod(value) << endl
       << binsearch(value) << endl;
  return 0;
}
