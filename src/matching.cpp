#include<iostream>
#include<set>
#include<vector>

#include"deps/graph.cpp"

using namespace std;
using NodeId = int; // following the convention established in the class definition

//static set<int> visited; // very bad code, but I don't care

bool traverse(Graph &g, NodeId id, vector<int> &match, vector<int> &ass){ // may call itself recursively, ergo there is a bool value to indicate success
  for(auto i : g.get_node(id).adjacent_nodes()){
    int jid = i.id();
    if(ass[jid] == -1){ // if job unassigned, assign it, and break away
      ass[jid] = id;
      match[id] = jid;
      return true;

    }else if(ass[jid] == -2){ // reassignment protocol, do nothing

    }else{ // job is assigned, then attempt to reassign
      int buf = ass[jid];
      ass[jid] = -2; // set to reassignment state
      bool status = traverse(g, buf, match, ass);
      if(status == true){
        ass[jid] = id;
        match[id] = jid;
        return true;
      }else{
        ass[jid] = buf;
      } // reassignment unsuccessful, proceding normal iteration
    }
  }
  //if we escaped from this loop, it means no match was found
  return false;
}

string bstr(bool b){
 return b ? "true" : "false";
}

int main(void){

  Graph g = Graph("../resources/tutortest",Graph::undirected);
  //Graph g = Graph("../resources/tutorien.txt",Graph::undirected);
  //g.print(); // debug
  int workers = g.num_nodes()/2;
  int jobs = workers;

  vector<int> matching;
  matching.reserve(workers); // may speed up performance and avoid overflow errors
  for(int i = 0; i<workers; i++){
    matching[i] = -1;
  }
  vector<int> assigned; // a class/struct is better but I'm lazy
  assigned.reserve(2*jobs); // may speed up performance and avoid overflow errors
  for(int i = 0; i<jobs; i++){ // set every job
    assigned[workers+i] = -1; // default "unassigned" value
  }

  // Loop where job assignment occurs
  for(int i = 0; i<workers; i++){
    traverse(g, i, matching, assigned);
  }
  bool matchflag = true; // perfect matching flag

  //FIXME: match is assigned incorrectly, but assigned is alright
  
  // check for unassigned jobs
  // for(int i : matching)
  //   cout << i <<endl;
  // cout <<endl;

   for(int i = 0; i<workers; i++){
     cout << "Tutor: " << i << " Matching No:"<< matching[i] - workers <<endl;
     //if(matching[i] == -1) {matchflag = false;
   }
  // }
  // cout <<endl;
  // check for unassigned workers
  // for(int i : assigned)
  //   cout << i <<endl;
  // cout <<endl;
  for(int i = workers; i<workers+jobs; i++){
    cout <<"Job No: " << i-workers<< " Tutor: " << assigned[i] <<endl;
    if(assigned[i] == -1) {matchflag = false;}
  }
  cout <<endl;
  // determine whether the matching is perfect

  cout << "Perfect matching status: " << bstr(matchflag) <<endl;
  return 0;
}
