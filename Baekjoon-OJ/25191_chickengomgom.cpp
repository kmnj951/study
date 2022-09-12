#include <iostream>

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
	int N;
	int A, B;
	
	std::cin >> N >> A >> B;
	std::cout << min(N, A/2+B);
	
	return 0;
}
