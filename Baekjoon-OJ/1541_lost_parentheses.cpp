#include <iostream>
#include <vector>

int min(const std::vector<char>& op, const std::vector<int>& operand) {
	int cal = 0;
	size_t plus;
	for (plus = 0; plus < op.size() && op[plus] != '-'; ++plus)
		;
	for (size_t i = 0; i <= plus; ++i) {
		cal += operand[i];
	}
	for (size_t i = plus + 1; i < operand.size(); ++i) {
		cal -= operand[i];
	}
	return cal;
}

int main() {
	std::vector<char> op;
	std::vector<int> operand;
	char ch;
	int num;
	while (std::cin >> num >> ch) {
		operand.push_back(num);
		op.push_back(ch);
	}
	operand.push_back(num);
	
	std::cout << min(op, operand);
	
	return 0;
}
