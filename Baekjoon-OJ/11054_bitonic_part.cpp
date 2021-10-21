#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N;
	int A[1000];
	int increase[1000] = {0};
	int decrease[1000] = {0};
	
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
	}
	
	for (int i = 0; i < N; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (A[i] > A[j] && increase[i] < increase[j])
				increase[i] = increase[j];
		}
		++increase[i];
	}
	
	for (int i = N -1 ; i >= 0; --i) {
		for (int j = i + 1; j < N; ++j) {
			if (A[i] > A[j] && decrease[i] < decrease[j])
				decrease[i] = decrease[j];
		}
		++decrease[i];
	}
	
	int max_len = 0;
	for (int i = 0; i < N; ++i) {
		if (max_len < increase[i] + decrease[i])
			max_len = increase[i] + decrease[i];
	}
	
	std::cout << --max_len;
	return 0;
}
