#include <iostream>
#include <algorithm>

#include <fstream>
#include <vector>


using namespace std;

vector<int> read_rowers(){
  ifstream rowfile;
  rowfile.open("../resources/zeiten.txt");
  vector<int> array;
  int token;
  rowfile >> token;
  while(token > -1){ // checks for EOF{
    array.push_back(token);
    if(rowfile.peek() != EOF){
      rowfile >> token;
    }else{
      token = -1;
    }
  }
  return array;
}

void pv(vector<int> v){
  for(auto i : v){
    cout << i << " ";
  }
  cout << endl;
}

void transport(vector<int> start){
  vector<int> end; // end island
  for(auto i : start){
    // take 2 fastest guys
    // return back the second fastest
    // transport 2 slowest
    // return with the fstest
    // take 2 fastest guys
    // -> potential time save
}

int main(void){
  vector<int> rowers = read_rowers();
  sort(rowers.begin(), rowers.end());
  //int token = rowersa[0];
  //cout << token << endl;
  pv(rowers);
  return 0;
}
