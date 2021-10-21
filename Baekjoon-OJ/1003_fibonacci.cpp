#include <iostream>
#include <utility>

template <typename T1, typename T2>
std::pair<T1, T2> operator+(const std::pair<T1, T2>& A, const std::pair<T1, T2>& B) {
	return std::make_pair(A.first + B.first, A.second + B.second);
} 

void count_fibo_01(std::pair<int, int>* fibo_01, int n) {
	if (n == 0) {
		fibo_01[0] = std::make_pair(1, 0);
		return;
	}
	if (n == 1) {
		fibo_01[1] = std::make_pair(0, 1);
		return;		
	}
	if (fibo_01[n] == std::make_pair(0, 0)) {
		count_fibo_01(fibo_01, n-1);
		count_fibo_01(fibo_01, n-2);
		fibo_01[n] = fibo_01[n-1] + fibo_01[n-2];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	
	int T;
	int N;
	std::pair<int, int> count_fibo[41] = {{1, 0}};
	
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> N;
		count_fibo_01(count_fibo, N);
		std::cout << count_fibo[N].first << " " << count_fibo[N].second << "\n";
	}
	
	return 0;
}
