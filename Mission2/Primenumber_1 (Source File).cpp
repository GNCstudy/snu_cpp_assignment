#include <iostream>
using namespace std;

bool isPrime(int n) { // 어떤 수 N이 소수인지 판단하는 Bool 함수
	if (n < 2) return false; // N이 2보다 작으면 False 리턴
	for (int i = 2; i * i <= n; i++) { // For Loop (2부터 루트 n의 내림수까지 1씩 증가하면서)
		if (n % i == 0) { // n이 i로 나누어진다면 Not Primenumber로 출력
			cout << "Not primenumber";
			return false; // False  반환
		}
	}
	cout << "Primenumber"; // For Loop에서 False로 반환되지 않았다면 Primenumber로 출력
	return true; // True 반환
}

int main() { // INTEGER 메인
	for (int i = 2; i <= 10000; i++) { // For Loop (2부터 특정 수까지 1씩 증가하면서)
		cout << i << ' '; // Loop에서 몇번째 수인지 출력
		isPrime(i); // 바로 윗줄에서 출력된 수에 대한 Bool 함수
		cout << endl; //  New line character
	}
}