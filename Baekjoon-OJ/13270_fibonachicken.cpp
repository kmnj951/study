#include <iostream>
#include <vector>

int count_min(const int* fibo, std::vector<int>& min, int num) {
	if (num < 2)
		return 0;
	if (min[num] == 0) {
		int fi;
		for (fi = 0; fibo[fi] < num; ++fi)
			;
	
		min[num] = num;
		for (--fi; fi > 1; --fi) {
			int find_min;
			int pre_num = num - fibo[fi];
			find_min = count_min(fibo, min, pre_num) + fibo[fi-1];
			min[num] = min[num] < find_min ? min[num] : find_min;
		}
	}
	return min[num]; 
}

int count_max(const int* fibo, std::vector<int>& max, int num) {
	if (num < 2)
		return 0;
	if (max[num] == 0) {
		int fi;
		for (fi = 0; fibo[fi] < num; ++fi)
			;
	
		max[num] = 0;
		for (--fi; fi > 1; --fi) {
			int find_max;
			int pre_num = num - fibo[fi];
			find_max = count_max(fibo, max, pre_num) + fibo[fi-1];
			max[num] = max[num] > find_max ? max[num] : find_max;
		}
	}
	return max[num];
}

int make_fibo(int* fibo, int seq) {
	if (fibo[seq] == 0)
		fibo[seq] = make_fibo(fibo, seq-1) + make_fibo(fibo, seq-2);
	return fibo[seq];
}

int main() {
	int N;
	int fibo[22] = {1, 1};
	std::vector<int> min{0, 0, 1, 2}, max{0, 0, 1, 2};

	std::cin >> N;
	min.resize(N+1);
	max.resize(N+1);		
	make_fibo(fibo, 21);
	
	count_min(fibo, min, N);
	count_max(fibo, max, N);
	
	std::cout << min[N] << " " << max[N];
	return 0;
}
