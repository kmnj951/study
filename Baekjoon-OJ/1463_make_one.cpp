#include <iostream>
#include <vector>

int find_op_min(std::vector<int>& op_min, int num) {
	if (op_min[num] > 0)
		return op_min[num];
	
	int min = (unsigned)-1>>1;
	if (num % 6 != 0)
		min = find_op_min(op_min, num - 1);
	if (num % 3 == 0) {
		int cmp = find_op_min(op_min, num / 3);
		min = min <= cmp ? min : cmp;
	}
	if (num % 2 == 0) {
		int cmp = find_op_min(op_min, num / 2);
		min = min <= cmp ? min : cmp;
	}
	op_min[num] = ++min;
	return op_min[num]; 
}

int main() {
	int N;
	std::vector<int> op_min {1, 1};
	std::cin >> N;
	
	op_min.resize(N + 1);
	
	std::cout << find_op_min(op_min, N) - 1;
	return 0;
}
