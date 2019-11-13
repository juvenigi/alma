#include<iostream>
#include<vector>
#include<string>
#include"deps/vutils.cpp" //FIXME: don't be lazy

#define SIZ 10e6

using namespace std;

vector<unsigned long int> merge(vector<unsigned long int> a, vector<unsigned long int> b){
  vector<unsigned long int> result;
  while(a.size() or b.size()){
    if(a.size()!=0 and b.size()!=0){
      switch(a[a.size()-1]>b[b.size()-1]){
      case true:
        result.insert(result.begin(),a[a.size()-1]);
        a.pop_back();
        break;
      default:
        result.insert(result.begin(),b[b.size()-1]);
        b.pop_back();
      }
    }else if(a.size()==0 && b.size()!=0){
      result.insert(result.begin(),b[b.size()-1]);
      b.pop_back();
    }else if(b.size()==0 && a.size()!=0){
      result.insert(result.begin(),a[a.size()-1]);
      a.pop_back();
    }
  }
  return result;
}

vector<unsigned long int> mergesort(vector<unsigned long int>unsort){
  size_t const half_size = unsort.size() / 2;
  vector<unsigned long int> a(unsort.begin(), unsort.begin() + half_size);
  vector<unsigned long int> b(unsort.begin() + half_size, unsort.end());
  if(unsort.size()>2){
    a = mergesort(a);
    b = mergesort(b);
    return merge(a,b);
  }
  return merge(a,b);
}

// overload to support strings
vector<string> mergesort(vector<string>unsort){
  return vconvert_str_i(mergesort(vconvert_str_i(unsort)));
}

int main(void){
  vector<unsigned long int> v = randomized_v(5);
  //pv(v);

  vector<string> sv = vconvert_str_i(v);
  //pv(sv);

  vector<unsigned long int> merged = mergesort(v);
  pv(merged);

  vector<string> smerged = mergesort(sv);
  pv(smerged);

  return 0;
}

