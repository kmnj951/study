#include <iostream>
#include <vector>

int build_time(const std::vector<int>& time, std::vector<int>& all_time, const std::vector<std::vector<int> >& need, int building) {
	int max_required = 0;
	for (size_t i = 0; i < need[building].size(); ++i) {
		int pre = need[building][i];
		int required;
		if (all_time[pre] < 0)
			all_time[pre] = build_time(time, all_time, need, pre);
		required = all_time[pre];
		if (required > max_required)
			max_required = required;
	}
	return max_required + time[building];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int T;
	int N, K;
	int W;
	std::vector<int> time;
	std::vector<int> all_time;
	std::vector<std::vector<int> > need;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> N >> K;
		time.resize(N + 1);
		all_time.resize(N + 1, -1);
		need.resize(N + 1);
		for (int b = 1; b <= N; ++b) {
			std::cin >> time[b];
		}
		for (int i = 0; i < K; ++i) {
			int pre, cur;
			std::cin >> pre >> cur;
			need[cur].push_back(pre);
		}
		std::cin >> W;
		std::cout << build_time(time, all_time, need, W) << "\n";
		need.resize(0);
		all_time.resize(0);
	}
	
	return 0;
}
