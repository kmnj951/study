#include <iostream>
#include <set>

int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
	int N;
	std::cin >> N;
	std::multiset<std::pair<int, int>> start_end;

	for (int i = 0; i < N; ++i) {
		int start, end;
		std::cin >> start >> end;
		start_end.emplace(start, end);
	}
	
	int count = 0;
	int pre_end = 0;
	for (const auto& time : start_end) {
		if (pre_end <= time.first) {
			++count;
			pre_end = time.second;
		}
		else if (pre_end > time.second) 
			pre_end = time.second;
	}
	
	std::cout << count;
	
	return 0;
}
