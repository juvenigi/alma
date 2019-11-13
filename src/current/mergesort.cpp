#include<iostream>
#include<vector>
#include<string>

#define SIZ 10e6

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

