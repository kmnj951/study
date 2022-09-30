#include <iostream>
#include <vector>

int worm_num(std::vector<bool>& worm, const std::vector<std::vector<int>>& con, int cur) {
	int num = 0;
	for (size_t i = 0; i < con[cur].size(); ++i) {
		if (!worm[con[cur][i]]) {
			worm[con[cur][i]] = true;
			++num;
			num += worm_num(worm, con, con[cur][i]);
		}
	}
	return num;
}

int main() {
	int num, pair_num;
	std::cin >> num >> pair_num;
	
	std::vector<std::vector<int>> connect(num + 1);
	for (int i = 0; i < pair_num; ++i) {
		int a, b;
		std::cin >> a >> b;
		connect[a].push_back(b);
		connect[b].push_back(a);
	}
	
	std::vector<bool> worm(num + 1);
	worm[1] = true;
	std::cout << worm_num(worm, connect, 1);
	
	return 0;
}
