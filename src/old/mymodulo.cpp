#include <iostream>
#include "modules/mutils.cpp"

using namespace std;

int main(void){
  int i;
  int j;
  int modulo;

  cin >> i >> j;

  modulo = m_mod_2(i,j);


  cout << "Rest : " << modulo << endl
       << "Compare to standard: " << i % j << endl;

  return 0;
}
