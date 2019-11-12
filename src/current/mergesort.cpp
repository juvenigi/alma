#include<iostream>
#include<vector>

#define SIZ 10e6

using namespace std;

void pv(vector<unsigned long int> v){
  for(unsigned int i = 0; i<v.size(); i++){
    cout << v[i] <<endl;
  }
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

vector<unsigned long int> merge(vector<unsigned long int> a, vector<unsigned long int> b){
  vector<unsigned long int> result;
  unsigned int mi = 0;
  unsigned int mj = 0;
  while(mi<a.size() and mj<b.size()){
    switch(a[mi]>b[mj]){
    case true:
      result.push_back(b[mj]);
      b.erase(b.begin()+mj);
      mj++;
      break;
    default:
      result.push_back(a[mi]);
      a.erase(a.begin()+mi);
      mi++;
    }
  }
  if(a.size()){
    result.reserve(result.size()+a.size());
    result.insert(result.end(),a.begin(),a.end());
  }
  if(b.size()){
    result.reserve(result.size()+b.size());
    result.insert(result.end(),b.begin(),b.end());
  }
  return result;
}

vector<unsigned long int> mergesort(vector<unsigned long int>unsort){
  size_t const half_size = unsort.size() / 2;
  vector<unsigned long int> a(unsort.begin(), unsort.begin() + half_size);
  vector<unsigned long int> b(unsort.begin() + half_size, unsort.end());
  if(unsort.size()>4){  
    a = mergesort(a);
    b = mergesort(b);
    return merge(a,b);
  }
  return merge(a,b);
}

int main(void){
  // initialize a big range
  vector<unsigned long int> v = randomized_v(5);
  //pv(v);
  vector<unsigned long int> merged = mergesort(v);
  //vector<unsigned long int> quickd = quicksort(v);

  pv(merged);
  //pv(quicked);
  
  return 0;
}
