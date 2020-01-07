#include<iostream>
#include<math.h>

using namespace std;

#define OUT

/* Helper Functions */
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

/* Additive inverse involves flipping the sign of every digit */
void flipsign(pair<bool,bool> * num, int length){
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

int terlen(int decnum){
  if(!decnum){return 1;}
  int i = 0;
  while(pow(3,i)<2*abs(decnum)){++i;}
  return i;
}

pair<bool,bool> * conv_dec(int num, OUT int * length){
  //int length = 4; // lazy, it is better to check for the nearest 2*3^n
  *length = terlen(num);
  pair<bool,bool> * out = new pair<bool,bool>[*length]; // {{bool,bool},{bool,bool}...} a bool pair array

  if(num == 0) {out[0].first = false; out[0].second = false; return out;} // zero is simple

  bool pos = true;
  if(num < 0){ // do the following if the number is negative
    pos = false; // will run flipsign later
    num = 0 - num;
  }
  int i = 0;

  /* in order to get more cores to work,
     you can try to chunk this process into separate numbers [%(3^n) apart]
     and run this algo on each core.
     then run a simple merge on all chunks.

   */
  while(i<*length){
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
  if(!pos){flipsign(out,*length);}
    return out;
}


int main(void){

  // pair<bool,bool> pos1 = make_pair(true,true);
  // pair<bool,bool> zero = make_pair(false,false);
  // pair<bool,bool> neg1 = make_pair(false,true);

  // printdig(pos1);
  // cout << endl;
  // printdig(zero);
  // cout << endl;
  // printdig(neg1);
  // cout << endl;
  // cout << endl;

  pair<bool,bool> * numa;
  int numal;
  for(int j = -13; j<14; j++){
    numa = conv_dec(j,&numal);
    cout << j << " -> ";
    printt(numa,numal);
  }
  return 0;
}
