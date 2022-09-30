#include <iostream>

int case_num(int n) {
	static int c_num[12] = {0, 1, 1<<1, 1<<2};
	if (c_num[n] == 0) {
		c_num[n] = case_num(n-1) + case_num(n-2) + case_num(n-3);
	}
	return c_num[n];
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		int n;
		std::cin >> n;
		std::cout << case_num(n) << "\n";
	}
	return 0;
}
