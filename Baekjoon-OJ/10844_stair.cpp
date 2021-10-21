#include <iostream>

#define MAX 1000000000

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int end_num[10] = {0};
	int N;
	std::cin >> N;
	
	for (int n = 1; n < 10; ++n) {
		end_num[n] = 1;
	}
	for (int i = 1; i < N; ++i) {
		int cur_num[10] = {0};
		int n;
		for (n = 0; n < 10; ++n) {
			if (n > 0) {
				cur_num[n] += end_num[n-1];
			}
			if (n < 9) {
				cur_num[n] += end_num[n+1];
			}
		}
		for (n = 0; n < 10; ++n) {
			if (cur_num[n] < MAX)
				end_num[n] = cur_num[n];
			else
				end_num[n] = cur_num[n] % MAX;
		}	
	}
	
	int stair_num = 0;
	for (int n = 0; n < 10; ++n) {
		stair_num += end_num[n];
		if (stair_num >= MAX)
			stair_num %= MAX;
	}
	
	std::cout << stair_num;
	return 0;
}

// 9 

// 1 0 - 1
// 2 1 - 1
// 1 2 - 2
// 3 2
// ..
// 7 8 - 2
// 9 8
// 8 9 - 1


