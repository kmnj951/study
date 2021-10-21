#include <iostream>
#define MIN(a, b) (a) < (b) ? (a) : (b)

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int min[3] = {0};
	int cur[3];
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int c = 0; c < 3; ++c) {
			std::cin >> cur[c];
			cur[c] += MIN(min[(c+1)%3], min[(c+2)%3]);
			
		}
		for (int c = 0; c < 3; ++c)
			min[c] = cur[c];
	}
	
	int min_all = MIN(min[0], min[1]);
	min_all = MIN(min_all, min[2]);
	
	std::cout << min_all;
	
	return 0;
}

// 2 3 2
// 50 5 50
// 100 1 100
