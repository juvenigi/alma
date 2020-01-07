#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // for std::sort


using namespace std;

vector<int> read_rowers(){
  ifstream rowfile;
  rowfile.open("../resources/zeiten.txt");
  vector<int> array;
  int token;
  rowfile >> token;
  while(token > -1){ // checks for EOF
    array.push_back(token); // token gets written here
    if(rowfile.peek() != EOF){
      rowfile >> token;
    }else{ // rowfile.peek == EOF
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

class Islands{
private:
  unsigned int timer;
  vector<int> start;
  vector<int> finish;

  bool erase(vector<int>*v,int something){
    auto it = std::find(v->begin(),v->end(),something);
    if (it != v->end()) {
      v->erase(it);
      return true;
    }
    return false;
  }
  void track(int time){
    timer += time;
  }

public:
  Islands(vector<int> sarray){
    timer = 0;
    start = sarray;
  }

  void time_undo(int rower){
    timer -= rower;
    cout << "UNDO: " << rower << endl;
  }

  int size(){
    return start.size();
  }

  void print(){
    int minutes = timer / 60; minutes %= 60;
    int hours = timer / 3600; hours %= 3600;

    cout << "Start: "; pv(start);
    cout << "Finish: "; pv(finish);
    //cout << timer;
    cout << "H: " << hours << "  M: " << minutes << "  S: " << timer % 60 << endl << endl;
  }

  bool transport(int first, int second, int turn){
    if(not erase(&start,first)) return false;
    if(not erase(&start,second)) return false;
    finish.push_back(first);
    finish.push_back(second);
    if(not erase(&finish,turn)){
      finish.pop_back();
      finish.pop_back(); // removing first second element
      start.push_back(first);
      start.push_back(second);
      return false;
    }
    start.push_back(turn);
    track(max(first,second));
    track(turn);
    cout << "Transport: " << first << " " << second << " - " << turn <<endl;
    return true;
  }

  pair<int,int> take(bool small){ // find largest/smallest values in start
    vector<int> ref = start; // call by reference
    pair<int,int> rval;
    int k = ref.size()-2; if(small){k = 0;}

    if(!ref.size()){return make_pair(-1,-1);} // in case ref is empty
    sort(ref.begin(),ref.end()); // performs quicksort on reference
    rval.first = ref[k]; // smallest element or second largest
    rval.second = ref[k+1]; // second smallest or largest
    return rval;
  }
};

void smartrow(Islands isl){
  int first = isl.take(true).first;
  int second = isl.take(true).second;
  while(isl.size() > 4){
    int last = isl.take(false).second;
    int slast = isl.take(false).first;
    isl.transport(first,second,second);
    isl.transport(last,slast,first);
    isl.print();
  }
  if(isl.size() == 3){
    cout << "HERE" << endl;
    int last = isl.take(false).second;
    isl.transport(first,last,first);
    isl.transport(first,second,first);
  }else{ // 4 remain
      int last = isl.take(false).second;
      int slast = isl.take(false).first;
      isl.transport(first,second,second);
      isl.transport(last,slast,first);
      isl.transport(first,second,first);
  }
  isl.time_undo(first);
  isl.print();
}

int main(void){
  vector<int> rowers = read_rowers();
  //vector<int> rowers = {1,2,3,4,5,5};
  //pv(rowers);

  Islands island = Islands(rowers);
  // cout << island.take(true).first << " " << island.take(true).second <<endl
  //      << island.take(false).first << " " << island.take(false).second <<endl;
  island.print();

  smartrow(island);

    return 0;
}
