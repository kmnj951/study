#include <iostream>
#include <utility>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N;
	std::pair<int, int> people[50];
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		int x, y;
		std::cin >> x >> y;
		people[i] = std::make_pair(x, y);
	}
	
	for (int i = 0; i < N; ++i) {
		int count = 1;
		for (int j = 0; j < N; ++j) {
			if (i != j) {
				if (people[i].first < people[j].first && people[i].second < people[j].second) 
					++count;
			}
		}
		std::cout<< count << " ";
	}
	return 0;
}
