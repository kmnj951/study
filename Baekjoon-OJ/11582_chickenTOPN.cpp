#include <iostream>
#include <vector>

void merge_sort_adj_same_size(std::vector<int>& num, const int beg, const int end) {
	int mid = (end + beg) / 2;
	std::vector<int> merge;
	merge.resize(end-beg);
	
	int i = 0;
	int cur1, cur2;
	for (cur1 = beg, cur2 = mid; cur1 < mid && cur2 < end; ++i) {
		if (num[cur1] < num[cur2])
			merge[i] = num[cur1++];
		else
			merge[i] = num[cur2++];
	}
	while (cur1 < mid) {
		merge[i++] = num[cur1++];
	}
	while (cur2 < end) {
		merge[i++] = num[cur2++];
	}
	for (int j = 0; j < i; ++j) {
		num[beg+j] = merge[j];
	}
}

void sort(std::vector<int>& num, int mem, int depth, int beg, int end) {
	if (end - beg <= 1)
		return;

	int mid = (end + beg) / 2; 	
	sort(num, mem, depth*2, beg, mid);
	sort(num, mem, depth*2, mid, end);
	if (mem <= depth)
		merge_sort_adj_same_size(num, beg, end);
}

int main() {
	int N, k;
	std::vector<int> tastes;
	
	std::cin >> N;
	tastes.resize(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> tastes[i];
	}
	std::cin >> k;
	
	sort(tastes, k, 1, 0, N);
	for (int i = 0; i < N; ++i) {
		std::cout << tastes[i] << " ";
	}
	
	return 0;
}
