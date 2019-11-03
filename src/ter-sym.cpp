#include<iostream>
#include<math.h>

using namespace std;


void printdig(pair<bool,bool> pair){
  if(pair.second == true){cout << '1';}else{ cout << '0';} // one or zero
  if(pair.first == false && pair.second == true) {cout << "\xCC\x85";} // add a hat only to one
}

void printt(pair<bool,bool> * arr, int length){ // simple recursion
  for(int i = length-1; i>=0; i--){
    printdig(arr[i]);
  }
  cout << endl;
}

void flipsign(pair<bool,bool> * num, int length){ // -1 becomes 1 and vice versa
  for(int i = 0; i<length; i++){
    switch(num[i].first){

    case true:
      num[i].first = false;
      break;

    default:
      num[i].first = true;
    }
  }
}

pair<bool,bool> * conv_dec(int num){
  int length = 4; // lazy, it is better to check for the nearest 2*3^n
  pair<bool,bool> * out = new pair<bool,bool>[length]; // {{bool,bool},{bool,bool}...} a bool pair array

  if(num == 0) {out[0].first = false; out[0].second = false; return out;} // zero is simple

  bool pos = true;
  if(num < 0){ // do the following if the number is negative
    pos = false;
    num = 0 - num;
  }
  int i = 0;
  while(i<length){
    switch(num % 3){
    case 1:
      out[i].first = true;
      out[i].second = true;
      num--;
      break;

    case 2:
      out[i].first = false;
      out[i].second = true;
      num++; // the biggest difference is that the balanced ternary has no '2' ergo you need to do this
      break;

    default:
      out[i].first = false;
      out[i].second = false;
      break;
    }
    i++;
    num /= 3;
  }
  if(!pos){flipsign(out,length);}
    return out;
}


int main(void){

  pair<bool,bool> pos1 = make_pair(true,true);
  pair<bool,bool> zero = make_pair(false,false);
  pair<bool,bool> neg1 = make_pair(false,true);

  printdig(pos1);
  cout << endl;
  printdig(zero);
  cout << endl;
  printdig(neg1);
  cout << endl;
  cout << endl;

  pair<bool,bool> * numa;
  for(int j = -13; j<15; j++){
    numa = conv_dec(j);
    printt(numa,4);
  }
  return 0;
}
