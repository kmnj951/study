#include <iostream>
#include <vector>

#define min(a, b) ((a) <= (b) ? (a) : (b))

class distance {
private:
	std::vector<std::vector<int>> dist;
	std::vector<int> choice = {-1, 0, 0};
	const int max_depth = 2;
public:
	distance(int size) : dist(size) {
		for (int i = 0; i < size; ++i) {
			dist[i].resize(size, 100);
			dist[i][i] = 0;
		}
	}
	const std::vector<int>& operator[](int i) const {
		return dist[i];
	}
	std::vector<int>& operator[](int i) {
		return dist[i];
	}
	int find_min(int depth, int* choice_min) {	
		int total = 0;
		if (depth == max_depth) {
			for (auto dst : dist) {
				total += min(dst[choice[1]], dst[choice[2]]);
			}
			choice_min[0] = choice[1];
			choice_min[1] = choice[2]; 
			/*
			for (int i = 0; i <= depth; ++i)
				std::cout << "\t";
			std::cout << choice_min[0] << " " << choice_min[1] << " (" << total << ")" << std::endl;
			*/
			return total;
		}
		
		int total_min = (unsigned)-1 >> 1;
		int ch_min[max_depth];
		for (size_t i = choice[depth] + 1; i <= dist.size() + depth - max_depth; ++i) {
			choice[depth + 1] = i;
			total = find_min(depth + 1, ch_min);
			if (total < total_min) {
				total_min = total;
				choice_min[0] = ch_min[0];
				choice_min[1] = ch_min[1];
			}
			else if (total == total_min) {
				if (choice_min[0] > ch_min[0]) {
					choice_min[0] = ch_min[0];
					choice_min[1] = ch_min[1];
				}
				else if (choice_min[0] == ch_min[0] && choice_min[1] > ch_min[1])
					choice_min[1] = ch_min[1];
			}
	
		}
		/*
		for (int i = 0; i < depth; ++i)
			std::cout << "\t";
		std::cout << choice_min[0] << " " << choice_min[1] << " (" << total_min << ")" << std::endl;
		*/
		return total_min;
	}
};

int main(void) { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;
	distance dist(N);
	
	for (int i = 0; i < M; ++i) {
		int e1, e2;
		std::cin >> e1 >> e2;
		dist[e1-1][e2-1] = 1;
		dist[e2-1][e1-1] = 1;
	}

	// Floyd-Warshall
	for (int i = 0; i < N; ++i) {
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				dist[r][c] = min(dist[r][c], dist[r][i] + dist[i][c]);
			}
		}
	}
	
	int v[2];
	int m = dist.find_min(0, v);
	
	std::cout << v[0]+1 << " " << v[1]+1 << " " << m*2;

	return 0;
}
