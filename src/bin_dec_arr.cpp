#include<iostream>
#include<string>
#include<bitset>
#include<math.h>

#define OUT

using namespace std;

/* TODO:
 * change int to unsigned int to avoid negative numbers
 */

int bilen(int a){
  int length;
  for( int i = 0; a-pow(2,i) >= 0; ++i){
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

int * int_decarr(int number, OUT int * length){
  string numstr = to_string(number);
  *length = (int) numstr.length();
  int * numarray = (int*) malloc(sizeof(int) * (*length));
  for(unsigned int i = 0; i<numstr.length();i++){
    //numarray[i] = stoi(numstr.substr(i,1));
    numarray[i] = number % 10;
    number /= 10;
  }
  return numarray;
}

bool * int_boolarr(int value, OUT int * length){
  *length = bilen(value);
  bool * array = (bool *) malloc(sizeof(bool) * (*length));
  for(int i = 0; i < *length; i++){
    array[i] = value % 2;
    value /= 2;
  }
  return array;
}

int * sum_decarr(int * num1, int * num2, int lnum1, int lnum2, OUT int * length){
  if(lnum1>lnum2){
    *length = lnum1;
  }else{
    *length = lnum2;
  }

  int * outarr = (int *) malloc(sizeof(int) * ++*length); // zero out the array
  for(int i = 0; i<*length; i++){
    outarr[i] = 0;
  }

  for(int i = 0; i<lnum1; i++){ // copy the first number
    outarr[i] = num1[i];
  }

  bool carry = 0; // carry digit, it's funny but it can only be 1 if you're adding numbers
  for(int i = 0; i<lnum2; i++){
    int sum = outarr[i] + num2[i] + carry;
    if(sum >= 10){ // in case of digit overflow
      sum = 10 - sum;
      carry = 1;
    }
    else{
      carry = 0;
    }
    outarr[i] = sum;
  }
  outarr[*length-1] = carry; // the last carry digit
  return outarr; // the funcion outputs a number with a leading zero, shouldn't be a problem.
}

void shift_boolarr(bool * arr, int length){
  for(int i = length-1; i>0; --i){
    arr[i] = arr[i-1];
  }
  arr[0] = 0;
}

bool isZero(bool * arr, int length){
  for(int i = length-1; i>=0; i--){
    if(arr[i] != 0){
      return false;
    }
  }
  return true;
}

bool * sum_boolarr(bool * bool1, bool * bool2, int len1, int len2, OUT int * outlen){
  if(len1>len2){
    *outlen = len1;
  }else{
    *outlen = len2;
  }

  bool * outarr = (bool *) malloc(sizeof(bool) * ++(*outlen));
  bool * bool2b = (bool *) malloc(sizeof(bool) * (*outlen));
  bool * carryr = (bool *) malloc(sizeof(bool) * (*outlen));

  for(int i = 0; i<*outlen; i++){
    outarr[i] = 0;
    carryr[i] = 0;
    bool2b[i] = 0;
  }

  for(int i = 0; i<len1; i++){
    outarr[i]=bool1[i];
  }
  for(int i = 0; i<len2; i++){
    bool2b[i] = bool2[i];
  }
  
  do{
    for(int i = 0; i<*outlen; i++){
      carryr[i] = outarr[i] & bool2b[i];
      outarr[i] = outarr[i] ^ bool2b[i];
    }
    shift_boolarr(carryr, *outlen);
    for(int i=0; i<*outlen; i++){
      bool2b[i] = carryr[i];
    }
  }while(!isZero(carryr,*outlen));
  return outarr;
}


int main(void){

  int n1 = 20; // for testing purpposes only
  int n2 = 69;
  cin >> n1;
  cin >> n2;

  n1 = abs(n1); // code sanitation
  n2 = abs(n2);

  
  int nb1_l;
  int nb2_l;
  bool * nb1 = int_boolarr(n1,&nb1_l);
  bool * nb2 = int_boolarr(n2,&nb2_l);
  int nbs_l;
  bool * nbs = sum_boolarr(nb1,nb2,nb1_l,nb2_l,&nbs_l);

  int ni1_l;
  int ni2_l;
  int * ni1 = int_decarr(n1,&ni1_l);
  int * ni2 = int_decarr(n2,&ni2_l);

  int nis_l;
  int * nis = sum_decarr(ni1,ni2,ni1_l,ni2_l,&nis_l);
  
  cout << n1 << " " << n2 << endl;

  printbool(nb1,nbs_l);
  printbool(nb2,nbs_l);
  printbool(nbs,nbs_l);

  printdec(ni1,nis_l);
  printdec(ni2,nis_l);
  printdec(nis,nis_l);

  return 0;
}
