#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
	std::unordered_map<std::string, int> mem_str;
	std::vector<std::string> mem_num;
	int N, M;
	std::cin >> N >> M;
	
	mem_str.reserve(N);
	mem_num.resize(N+1);
	std::string str;
	for (int i = 1; i <= N; ++i) {
		std::cin >> str;
		mem_str.emplace(str, i);
		mem_num[i] = str;
	}
	
	int num;
	for (int i = 0; i < M; ++i) {
		if (std::cin >> num)
			std::cout << mem_num[num] << "\n";
		else {
			std::cin.clear();
			std::cin >> str;
			std::cout << mem_str.find(str)->second << "\n";
		}	
	}
	return 0;
} 
