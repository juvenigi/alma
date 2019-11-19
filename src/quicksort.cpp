#include<iostream>
#include<vector>
#include<string>
#include"deps/vutils.cpp" //FIXME: don't be lazy

#define SIZ 10e6

vector<unsigned long int>quicksort(vector<unsigned long int> unsort){
  long unsigned int pivot = unsort[unsort.size()-1];
  unsort.pop_back();

  vector<unsigned long int> a;
  vector<unsigned long int> b;
  // a = quicksort(a);
  // b = quicksort(b);

  while(unsort.size()!=0){
    if(unsort[unsort.size()-1]>pivot){
      b.push_back(unsort[unsort.size()-1]);
      unsort.pop_back();
    }else{
      a.push_back(unsort[unsort.size()-1]);
      unsort.pop_back();
    }
  }
  if(a.size()>1) a = quicksort(a);
  if(b.size()>1) b = quicksort(b);

  vector<unsigned long int> sort;
  sort.reserve(a.size()+b.size()+1);
  sort.insert(sort.end(),a.begin(),a.end());
  sort.insert(sort.end(),pivot);
  sort.insert(sort.end(),b.begin(),b.end());
  return sort;
}

int main(void){
  vector<unsigned long int> v = randomized_v(20);
  pv(v);

  vector<string> sv = vconvert_str_i(v);
  //pv(sv);

  vector<unsigned long int> quicked = quicksort(v);
  pv(quicked);

  // vector<string> squicked = quicksort(sv);
  // pv(squicked);

  return 0;
}

