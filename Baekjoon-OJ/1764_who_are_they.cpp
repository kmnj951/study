#include <iostream>
#include <map>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
	int N, M;
	std::cin >> N >> M;
	
	std::map<std::string, bool> lst;
	std::string str;
	for (int i = 0; i < N; ++i) {
		std::cin >> str;
		lst.emplace(str, false);
	}
	
	int count = 0;
	std::map<std::string, bool>::iterator it;
	for (int i = 0; i < M; ++i) {
		std::cin >> str;
		it = lst.find(str);
		if (it != lst.end()) {
			++count;
			it->second = true;
		}
	}
	
	std::cout << count << "\n";
	for (auto i : lst) {
		if (i.second) 
			std::cout << i.first << "\n";		
	}
	
	return 0;
}
