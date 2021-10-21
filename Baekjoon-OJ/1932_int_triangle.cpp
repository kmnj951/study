#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int triangle[500][500];
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			std::cin >> triangle[i][j];
		}
	}
	for (int i = n - 2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			triangle[i][j] += triangle[i+1][j] > triangle[i+1][j+1] ? triangle[i+1][j] : triangle[i+1][j+1];
		}
	}
	
	std::cout << triangle[0][0];
	return 0;
}
