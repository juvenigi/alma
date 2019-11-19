#include <iostream>
#include "modules/mutils.cpp"

using namespace std;

int main(void){
  int number;
  cin >> number;

  cout << "Is power of two (first algo): " << is_powtwo(number) << endl
       << "Is power of two (second algo): " << is_powtwo_two(number) <<endl;
  return 0;
}
