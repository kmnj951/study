#include <iostream>

int main() {
	int N, K;
	int coin[10];
	int count = 0;
	std::cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		std::cin >> coin[i];
	}
	
	int pick = N - 1;
	while (K > 0) {	// pick >= 0
		if (K >= coin[pick]) {
			K -= coin[pick];	// division is recommended..
			++count;
		}
		else
			--pick;
	}
	
	std::cout << count;
	return 0;
}
