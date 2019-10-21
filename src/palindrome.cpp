#include<iostream>
#include<string>
#include<bitset>
#include<math.h>

using namespace std;

 int * int_arrstr(int number){
  string numstr = to_string(number);
  int * numarray = (int*) malloc(sizeof(int)*numstr.length());
  for(unsigned int i = 0; i<numstr.length();i++){
    numarray[i] = stoi(numstr.substr(i,1));
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
  for(unsigned long int i = 0; i<length; i++){
    cout << in[i] << " ";
  }
  cout << endl;
}

bool pabi(bool * array, unsigned int array_length){
  for(unsigned long int i = 0; i<(array_length)/2;i++){
    if(array[i] != array[array_length-1-i]){
      return false;
    }
  }
  return true;
}

bool pali(string numstr){
  for(unsigned long int i = 0; i<(numstr.length())/2;i++){
    if(numstr.substr(i,1) != numstr.substr(numstr.length()-1-i,1)){
      return false;
    }
  }
  return true;
}

string flipi(string number){
  string n2 = number;
  for(unsigned int i = 0; i<number.length();i++){
    n2[i] = number[number.length()-1-i];
  }
  return n2;
}

bool * wrbarr(unsigned long long int value){
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

int palincheck(unsigned long long int a){
  long int blen = bilen(a);
  string decstr = to_string(a);
  bool * binarr = wrbarr(a);
  printbool(binarr,blen);
  cout << decstr;
  bool out = pali(decstr) && pabi(binarr,blen);
  free(binarr);

  return out;
}

long long int bigdecgen(int i, int j){
  // 0<i<9
  // 1<j<9 ... 10<j<99
  string sj = to_string(j);
  return stoi(sj + to_string(i) + flipi(sj));
}

int main(void){
  cout << bigdecgen(0,10) << endl;

  /* bool * binarr = (bool *) malloc(sizeof(bool)*3); */
  /* wrbarr(binarr,3,2); */
  /* printbool(binarr,3); */
  /* cout << pabi(binarr,3) << endl; */
  /* free(binarr); */
  return 0;
  unsigned long long int sum = 1;
  for(unsigned long long int i = 1; i<1e6; i++){
    if(palincheck(i)){
      sum += i;
      cout << sum << endl;
      }
  }
  cout << "End result: " << sum << endl;
  /* string str1; */
  /* cin >> str1; */
  /* cout << stoi( str1.substr(0,1) ) << endl; */

  return 0;
}
