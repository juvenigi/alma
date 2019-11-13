#include<iostream>
#include<vector>
#include<string>

using namespace std;

void pv(vector<unsigned long int> v){
  for(unsigned int i = 0; i<v.size(); i++) cout << v[i] <<endl;
  cout <<endl;
}

// function overload to support strings
void pv(vector<string> v){
  for(unsigned int i = 0; i<v.size(); i++) cout << v[i] <<endl;
  cout <<endl;
}

// https://stackoverflow.com/questions/47232384/non-repeating-random-numbers-in-vector-c
vector<unsigned long int> randomized_v(unsigned int size){
  vector<unsigned long int> v;
  srand (time(NULL)); // set up seed
  for(unsigned long int i = 0; i < size; ++i){
    unsigned j = rand() % (i + 1);
    if (j < i){
      v.push_back(v[j]);
      v[j] = i;
    }else{
      v.push_back(i);
    }
  }
  return v;
}

vector<string> vconvert_str_i(vector<unsigned long int> v){
  vector<string>out;
  for(unsigned long int x : v) out.push_back(to_string(x));
  return out;
}

vector<unsigned long int> vconvert_str_i(vector<string> v){
  vector<unsigned long int>out;
  for(string x : v) out.push_back(stoi(x));
  return out;
}
