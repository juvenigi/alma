#include <iostream>

using namespace std;

int m_intsum(int a, int b){
	return a + b;
}

int main(void){
	int t,j;
	cin >> t;
	cin >> j;
	
	cout << "Sum: "; 
	cout << m_intsum(t,j);
	return 0;
}
