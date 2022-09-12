#include <iostream>

int main() {
	int balance[2] = {0};
	int A, B, C;
	
	std::cin >> A >> B >> C;
	
	balance[0] = A + B;
	balance[1] = balance[0] - 2 * C;
	
	if (balance[1] >= 0)
		std::cout << balance[1];
	else
		std::cout << balance[0];
	
	return 0;
}
