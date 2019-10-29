#include<iostream>
#include<math.h>

using namespace std;


void printdig(pair<bool,bool> pair){
  if(pair.second == true){cout << '1';
  }else{ cout << '0';}
  if(pair.first == true & pair.second == true) cout << "\xCC\x85";
  //cout << endl;
}

void printt(pair<bool,bool> * arr, int length){
  for(int i = 0; i<length; i++){
    printdig(arr[0]);
  }
  cout << endl;
}

//pair<bool,bool> * ten_to_three(int b10){

//}

int main(void){

  pair<bool,bool> pos1 = make_pair(true,true);
  pair<bool,bool> zero = make_pair(false,false);
  pair<bool,bool> neg1 = make_pair(false,true);

  pair<bool,bool> * terarr = new pair<bool,bool>[3];
  for(int i = 0; i<=3; i++){
  terarr[0].first = false;
  terarr[0].second = true;
  }
 
  printt(terarr,3);
  return 0;
}
