#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;
	std::vector<std::pair<int, int>> contestant;
	
	std::cin >> N;
	
	int prob, penalty;
	for (int i = 0; i < N; ++i) {
		std::cin >> prob >> penalty;
		contestant.push_back(std::make_pair(prob, penalty)); 
	}
	
	std::sort(contestant.begin(), contestant.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
		return a.second < b.second;
	});
	
	std::sort(contestant.begin(), contestant.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
		return a.first > b.first;
	});
	
	int count = 0;
	for (int i = 5; i < N && !(contestant[4].first != contestant[i].first); ++i, ++count)
		;
	
	std::cout << count;
	
	return 0;
}
