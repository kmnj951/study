#include <iostream>
#include <vector>
#include <iomanip>

#define abs(x) ((x) < 0 ? -(x) : (x))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define DST_MAX 100

int calculate_min(std::vector<std::vector<int>>& dsts, std::vector<int> home_min, int chick_num, int ch_num, int count) {	
	int dst_total_min = (unsigned)-1 >> 1;
	int dst_total = 0;
	if (chick_num <= count) {
		for (auto min : home_min)
			dst_total += min;
		return dst_total;
	}
	for (size_t ch = ch_num; ch < dsts.size(); ++ch) {
		std::vector<int> cur_home_min(dsts[0].size(), DST_MAX);
		//std::cout << std::setw(4 + count * 4) << std::right;
		//std::cout << "ch : " << ch << std::endl;
		for (size_t h = 0; h < home_min.size(); ++h) {
			cur_home_min[h] = min(home_min[h], dsts[ch][h]);
		}
		dst_total = calculate_min(dsts, cur_home_min, chick_num, ch+1, count+1);
		dst_total_min = min(dst_total_min, dst_total);
	}
	return dst_total_min;
}

int main() {
	int N, M;
	std::vector<std::vector<bool>> map;
	std::vector<std::pair<int,int>> chicken;
	std::vector<std::vector<int>> chick_dist;
	
	std::cin >> N >> M;
	map.resize(N);
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int e;
			std::cin >> e;
			if (e > 1) {
				chicken.push_back(std::make_pair(i, j));
				chick_dist.push_back(std::vector<int>());
				e = 0;
			}
			map[i].push_back((bool)e);
		}
	}
	
	for (size_t ch = 0; ch < chicken.size(); ++ch) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (map[i][j]) {
					int dist = abs(chicken[ch].first - i) + abs(chicken[ch].second - j);
					chick_dist[ch].push_back(dist);
				}
			}
		}
	}

	std::cout << calculate_min(chick_dist, std::vector<int>(chick_dist[0].size(), DST_MAX), M, 0, 0);
	return 0;
}

