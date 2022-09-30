#include <iostream>
#include <vector>

#define min(a, b) ((a) <= (b) ? (a) : (b))

int main() {
	std::vector<std::vector<int>> dist;
	int n, m;
	
	std::cin >> n >> m;
	dist.resize(n);
	for (int i = 0; i < n; ++i) {
		dist[i].resize(n, 10000000);
		dist[i][i] = 0;
	}
	
	for (int i = 0; i < m; ++i) {
		int e1, e2, d;
		std::cin >> e1 >> e2 >> d;
		dist[e1-1][e2-1] = min(dist[e1-1][e2-1], d);
	}
	
	for (int i = 0; i < n; ++i)
		for (int r = 0; r < n; ++r) 
			for (int c = 0; c < n; ++c) 
				dist[r][c] = min(dist[r][c], dist[r][i] + dist[i][c]);

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < n; ++c){
			if (r != c && dist[r][c] == 10000000)
				std::cout << 0 << " ";
			else
				std::cout << dist[r][c] << " ";
		}
			
		std::cout << "\n";
	}
	
	return 0;
}
