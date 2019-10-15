#include <iostream>

using namespace std;

unsigned int sanity_check(int a){
	unsigned int b = (unsigned int) a;
    if (a < 0) {
        throw std::invalid_argument("received negative value");
    }
    else{
		return b;
	}
}

unsigned int sanity_sgn(int a){
	unsigned int b;
    if (a < 0) {
        b = (unsigned int) -a;
    }
    else{
		b = (unsigned int) a;
	}
	return b;
}

int m_intsum(int a, int b){
	return a + b;
}

unsigned int * wholediv(unsigned int a, unsigned int b){
	unsigned int rest;
	unsigned int count = 0;
	while(a >= b){
		a = a-b;
		count++; 
	}
	rest = a;
	static unsigned int result[2] = {count,rest};
	return result;
}


int * wholediv_two(int a, int b){
	unsigned int au = sanity_sgn(a);
	unsigned int bu = sanity_sgn(b);
	static int result[2]= {-1,-1};		
	if((a*b)>0){ // negative * negative OR positive * positive
		return (int *) wholediv(au,bu);
	}else if (a<0){
		result[0] = (-1 * a - (-1 * a % b) / 3);
		result[1] = (-1 * a) % b;
		return result;
	}else{
		int * temp = (int *) wholediv(au,bu);
		result[0] = -1 * temp[0];
		result[1] = temp[1];
	}
	return result;
}

unsigned int lazy_modulo(unsigned int a, unsigned int b){
	unsigned int * result = wholediv(a,b);
	return result[1];
}

int gcd(int a, int b) { 
   if (b == 0){return a;} 
   return gcd(b, a % b);  
}

int * quot(int a, int b){	
	if(b == 0){throw std::invalid_argument("received zero");}
	int div = gcd(a,b); // apparently you need c++17 for that
	static int result[2];
	result[0] = a / div;
	result[1] = b / div;
	return result;
}

bool is_powtwo(unsigned int a){
	while(a > 2){
		a /= 2;
	}
	if(a == 0)
		return true;
	else
		return false;
}

bool is_powtwo_two(unsigned int a){
	if(a & (a-1)){
		return true;
	}else{
		return false;
	}
}
	

int main(void){
	int a,b;
	unsigned int au,bu; 
	cin >> a >> b;
	au = sanity_sgn(a);
	bu = sanity_sgn(b);
	unsigned int * wdiv = wholediv(au,bu);
	int * adv_div = wholediv_two(a,b);
	int * quotient = quot(a,b);
	cout << quotient[0] << " / " << quotient[1] << "\n";
	cout << wdiv[0] << " " << wdiv[1] << "\n";
	cout << lazy_modulo(au,bu)<<"\n";
	cout << is_powtwo(au)<<"\n";
	cout << is_powtwo_two(au)<<"\n";
	cout << "\n\n\n";
	
	cout << adv_div[0] << " " << adv_div[1];
	return 0;
}
