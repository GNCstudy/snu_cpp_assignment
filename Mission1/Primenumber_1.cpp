#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			cout << "Not primenumber";
			return false;
		}
	}
	cout << "Primenumber";
	return true;
}

int main(){
	for (int i = 2; i <= 100; i++) {
		cout << i << ' ';
		isPrime(i);
		cout << endl;
	}
}