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

  pair<int,int> sizes(){
    return make_pair(start.size(),finish.size());
  }

  void print(){
    int minutes = timer / 60; minutes %= 60;
    int hours = timer / 3600; hours %= 3600;

    cout << "Start: "; pv(start);
    cout << "Finish: "; pv(finish);
    //cout << timer;
    cout << "H: " << hours << "M: " << minutes << "S: " << timer % 60 << endl << endl;
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

  pair<int,int> take(bool small,bool startisle){
    vector<int> ref;
    pair<int,int> rval;
    int k = 0;
    switch(startisle){
    case true:
      ref = start;
      break;
    default:
      ref = finish;
    }
    if(small){k = ref.size()-2;}
    sort(ref.begin(),ref.end());
    if(!ref.size()){return make_pair(-1,-1);}
    rval.first = ref[k];
    rval.second = ref[k+1];
    return rval;
  }
};

void smartrow(Islands isl){
  pair<int,int> p1 = isl.take(true,true);
  pair<int,int> p2 = isl.take(true,false);

  
}

// int main(void){
//   //vector<int> rowers = read_rowers();
  
  
//   return 0;
// }

int main(void){
  //vector<int> rowers = read_rowers();
  vector<int> rowers = {6,1,3,3,4,5};
  pv(rowers);

  Islands island = Islands(rowers);
  island.print();

  pair <int,int> take = island.take(true,false);
  cout << take.first << " " << take.second <<endl;
  island.print();

  island.transport(1,3,3);
  island.print();
  //take = island.take(true);
  //cout << take.first << " " << take.second <<endl;
  return 0;
}
