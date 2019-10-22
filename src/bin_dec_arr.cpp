#include<iostream>
#include<string>
#include<bitset>
#include<math.h>

#define OUT

using namespace std;

 int * int_decarr(int number){
  string numstr = to_string(number);
  int * numarray = (int*) malloc(sizeof(int)*numstr.length());
  for(unsigned int i = 0; i<numstr.length();i++){
    //numarray[i] = stoi(numstr.substr(i,1));
    numarray[i] = number % 10;
    number /= 10;
  }
  return numarray;
}

unsigned int bilen(unsigned long long int a){
  int length;
  for(unsigned long long int i = 0; a-pow(2,i) >= 0; ++i){
    length = i;
  }
  return length + 1;
}

void printbool(bool * in, unsigned int length){
  for(unsigned long int i = length; i>0; i--){
    cout << in[i-1];
  }
  cout << endl;
}

void printdec(int * in, unsigned int length){
  for(unsigned int i = length; i>0; i--){
    cout << in[i-1];
  }
  cout << endl;
}

bool * int_boolarr(unsigned long long int value){
  int len = bilen(value);
  bool * array = (bool *) malloc(sizeof(bool)*len);
  for(unsigned long int i = len-1; i>0; i--){
    if(value - pow(2,i)>=0){
      value = value - pow(2,i);
      array[i] = 1;
    }
    if(value - 1 == 0)
      array[0] = 1;
  }
  return array;
}

int * sum_decarr(int * num1, int * num2, int lnum1, int lnum2){
  int length;
  if(lnum1>lnum2){
    length = lnum1;
  }
  else{
    length = lnum2;
  }
  int * outarr = (int *) malloc(sizeof(int) * ++length);
  for(int i = 0; i<length; i++){
    outarr[i] = 0;
  }
  
  for(int i = 0; i<lnum1; i++){
    outarr[i] = num1[i];
  }

  int carry = 0;
  for(int i = 0; i<lnum2; i++){
    int sum = outarr[i] + num2[i] + carry;
    if(sum >= 10){
      sum = 10 - sum;
      carry = 1;
    }
    else{
      carry = 0;
    }
    outarr[i] = sum;
  }
  outarr[length-1] = carry;
  return outarr;
}

void shift_boolarr(bool * arr, int length){
  for(;;){}
}

bool * sum_boolarr(bool * bool1, int * bool2, int len1, int len2){
  int outlen;
  if(len1>len2){
    outlen = len1;
  }else{
    outlen = len2;
  }
  bool * outarr = (bool *) malloc(sizeof(bool) * ++outlen);
  //bool outcarry[];
  for(int i = 0; i<outlen; i++){
    outarr[i] = 0;
  }

  for(int i = 0; i<len1; i++){
    outarr[i] = bool1[i];
  }
  bool carry = 
  // for(int i = 0; i<len2; i++){
  //   if(((a|b)&c|(a&b))){carry true;}
  //   outarr[i] = a&b&c
  return outarr;
}

    
int main(void){
  int number = 90;
  int number2 = 12;
  int number3 = 45;
  int number4 = 55;
  int * decarr = int_decarr(number);
  int * decarr2 = int_decarr(number2);
  int * d3 = int_decarr(number3);
  int * d4 = int_decarr(number4);
  int * decsum = sum_decarr(decarr, decarr2, 2, 2);
  int * ds2 = sum_decarr(d3, d4, 2, 2);
  bool * binarr = int_boolarr(number);
  printdec(decsum,3);
  printdec(ds2,3);
  printdec(decarr, sizeof(decarr)/sizeof(int));
  printbool(binarr,sizeof(binarr)/sizeof(bool));
  //cout << decarr[1] << decarr[0] << endl;
  return 0;
}
