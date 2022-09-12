#include <iostream>
#include <vector>

int greatest(std::vector<int>& num, std::vector<bool>& valid) {
	if (num.size() > valid.size())
		return 0;
	int max = 0;
	for (size_t i = 0; i < num.size(); ++i) {
		if (valid[i])
			max = max >= num[i] ? max : num[i];
	}
	return max;
}

int main() {
	int N, M;
	std::vector<std::vector<int>> satisfied;
	int max_satis = 0;
	
	std::cin >> N >> M;
	satisfied.resize(N);
	for (int i = 0; i < N; ++i) {
		satisfied[i].resize(M);
		for (int j = 0; j < M; ++j) {
			std::cin >> satisfied[i][j];
		}
	}
	
	std::vector<bool> choose(3, true);
	choose.resize(M);
	
	int num = M * (M - 1) * (M - 2) / 2 / 3;
	
	for (int n = 0; n < num; ++n) {
		int total = 0;
		for (int i = 0; i < N; ++i) {
			total += greatest(satisfied[i], choose);
		}
		max_satis = max_satis >= total ? max_satis : total;
		
		int i;
		for (i = choose.size() - 1; i >= 0 && !choose[i]; --i)
			;
		if (i < choose.size() - 1) {
			choose[i] = false;
			choose[i + 1] = true;
		}
		else {
			int j;
			for (j = i; j >= 0 && choose[j]; --j)
				;
			if (j >= 0) {
				int count = i - j;
				int from;
				for (from = j; from >= 0 && !choose[from]; --from)
					;
				if (from >= 0) {
					choose[from++] = false;
					for (int i = 0; i < count + 1; ++i) {
						choose[from++] = true;
					}
					while (from < choose.size()) {
						choose[from++] = false;
					}
				}
				else
					break;
			}
			else
				break;
		}
	}
	
	std::cout << max_satis;
	return 0;
}
