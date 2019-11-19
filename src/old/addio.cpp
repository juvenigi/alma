#include <iostream>
#include <iomanip>
#include "modules/mutils.cpp"

using namespace std;

int m_intsum(int a, int b){
	return a + b;
}

int main(void){
	int t,j;
  int quotient[2];

	cin >> t;
	cin >> j;

  quot(t,j,quotient);

	cout << "Sum: " << m_intsum(t,j) << endl
       << "Quotient: " << quotient[0] << "/" << quotient[1] << endl
       << "Quotient (decimal): " << fixed << setprecision(3) << (double) t / (double) j << endl;
	return 0;
}
