#include <iostream>
#include <string>
#include <list>
#include <stdexcept>

void op(std::string inst, std::list<int>& nums, bool& reverse) {
	for (char c : inst) {
		if (c == 'R') 
			reverse = !reverse;
		else if (c == 'D') {
			if (nums.empty())
				throw std::out_of_range("error");
			if (reverse) 
				nums.pop_back();
			else
				nums.pop_front();
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T, n;
	int x;
	char ch;

	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::string p;
		std::list<int> nums;	// vector -> save start, end index 
		bool reverse = false;
		std::cin >> p >> n;
		nums.resize(n);
		for (auto& num : nums) {
			std::cin >> ch >> x;
			num = x;
		}
		if (n == 0)
			std::cin >> ch;
		std::cin >> ch;
		try {
			op(p, nums, reverse);
			if (nums.empty()) {
				std::cout << "[";
			}
			else if (!reverse) {
				for (auto it = nums.begin(); it != nums.end(); ++it) {
					if (it == nums.begin())
						std::cout << "[";
					else
						std::cout << ",";
					std::cout << *it;
				}
			}
			else {
				for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
					if (it == nums.rbegin())
						std::cout << "[";
					else
						std::cout << ",";
					std::cout << *it;
				}	
			}
			std::cout << "]\n";
		}
		catch (const std::out_of_range& e) {
			std::cout << e.what() << "\n";
		}
	}
	return 0;
}
