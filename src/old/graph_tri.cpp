#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<math.h>

using namespace std;

pair <vector<vector<int>>,int> read_pyramid(char const * filename){
  ifstream file(filename);
  if(not file){ throw std::runtime_error("Cannot open file.");}
  vector<vector<int>> pyramid;

  int t = 0;
  int j = 0;
  int token;
  while(file.peek() != EOF){
    j++;
    vector<int> line;
    for(int i = 0; i<j; i++){
      t++;
      file >> token;
      line.push_back(token);
    }
    pyramid.push_back(line);
  }
  return make_pair(pyramid,t);
}

int pyramid_index(int members){
  return (sqrt(1 + 8 * members) - 1) / 2 -1;
}

vector<vector<int>> value(pair <vector<vector<int>>,int> pyramid){
  vector<vector<int>> vals;
  int max_i = pyramid_index(pyramid.second);
  for(int j = 0; j <= max_i; j++){
    vector<int> line;
    for(auto i : pyramid.first[j]){
      line.push_back(i);
    }
    vals.push_back(line);
  }
  for(int j = max_i-1; j>=0; j--){
    for(int i = 0; i <= j; i++){
      vals[j][i] += min(vals[j+1][i],vals[j+1][i+1]);
    }
  }
  return vals;
}

void printpyr(pair<vector<vector<int>>,int> pyramid){
  int m_index = pyramid_index(pyramid.second);
  int index = 0;
  while(index <= m_index){
    for(int i = 0; i < index+1; i++){
      cout << pyramid.first[index][i] << " ";
    }
    cout << endl;
    index++;
  }
}

void traverse(pair<vector<vector<int>>,int> py, pair<vector<vector<int>>,int> pyv){
  int j = 0;
  int m_index = pyramid_index(py.second);

  cout << "Optimal Traversal: ";
  for(int i = 0; i <= m_index; i++){
    if(pyv.first[i][j]>pyv.first[i][j+1]){
      cout << py.first[i][++j];
    }else{
      cout << py.first[i][j];
    }
    cout << " ";
  }
  cout << endl;
}

int main(void){
  pair<vector<vector<int>>,int> py = read_pyramid("../resources/triangle_15");
  pair<vector<vector<int>>,int> pyv = make_pair(value(py),py.second);
  //printpyr(py);
  //printpyr(pyv);
  traverse(py,pyv);
  return 0;
}
