#include <iostream>
#include <tuple>

#define INTMAX 0x7fffffff
#define INTMIN 0x80000000

enum OP {
	ADD, SUB, MUL, DIV
};

void add_i(int* num, int i) {
	if (i > 0) 
		num[i] = num[i-1] + num[i];
}

void sub_i(int* num, int i) {
	if (i > 0) 
		num[i] = num[i-1] - num[i];
}

void mul_i(int* num, int i) {
	if (i > 0)
		num[i] = num[i-1] * num[i];
}

void div_i(int* num, int i) {
	if (i > 0)
		num[i] = num[i-1] / num[i];
}

void (* const calculate[])(int* num, int i) = {add_i, sub_i, mul_i, div_i};

std::pair<int, int> find_max_min(int* num, int* op_count, int i) {
	int max = INTMIN;
	int min = INTMAX;
	bool finish = true;
	for(int oc = 0; oc < 4; ++oc) {
		if (op_count[oc] > 0) {
			int cur_max, cur_min;
			int n_tmp = num[i+1];
			finish = false;			
			--op_count[oc];
			calculate[oc](num, i+1);
			std::tie(cur_max, cur_min) = find_max_min(num, op_count, i+1);
			max = cur_max > max ? cur_max : max;
			min = cur_min < min ? cur_min : min;
			++op_count[oc];
			num[i+1] = n_tmp;
		}
	}
	if (finish) {
		max = num[i];
		min = num[i];
	}
	return std::make_pair(max, min);
}

int main() {
	int N;
	int num[11] = {0};
	int op_count[4] = {0};
	int max, min;

	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> num[i];
	}
	for (int i = 0; i < 4; ++i) {
		std::cin >> op_count[i];
	}
	
	std::tie(max, min) = find_max_min(num, op_count, 0);

	std::cout << max << "\n" << min;
	return 0;
}
