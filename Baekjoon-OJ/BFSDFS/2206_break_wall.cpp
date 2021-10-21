#include <iostream>
#include <queue>
#include <tuple>

char map[1000][1000];
int depth[1000][1000] = {{1}};	// > short
int depth_break[1000][1000] = {{1}};

int find_shortest(char map[][1000], int N, int M) {
	static const int dir[4] = {0, 0, -1, 1};
	std::queue<std::tuple<int, int, bool> > bfs_q;
	bfs_q.push(std::make_tuple(0, 0, false));

	while (!bfs_q.empty()) {
		int x, y, wall_break;
		std::tie(x, y, wall_break) = bfs_q.front();
		bfs_q.pop();
		if (x == N-1 && y == M-1) {
			if(wall_break)
				return depth_break[x][y];
			else
				return depth[x][y];
		}

		for (int i = 0; i < 4; ++i) {
			int next_x = x + dir[i];
			int next_y = y + dir[3-i];
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && depth[next_x][next_y] == 0) {
				if (wall_break) {
					if (depth_break[next_x][next_y] == 0 && map[next_x][next_y] == '0') {	
						depth_break[next_x][next_y] = depth_break[x][y] + 1;
						bfs_q.push(std::make_tuple(next_x, next_y, wall_break));
					}	
				}
				else {
					if (map[next_x][next_y] == '0') {
						depth[next_x][next_y] = depth[x][y] + 1;
						bfs_q.push(std::make_tuple(next_x, next_y, wall_break));
					}
					else if (depth_break[next_x][next_y] == 0) {	// time save...
						depth_break[next_x][next_y] = depth[x][y] + 1;
						bfs_q.push(std::make_tuple(next_x, next_y, !wall_break));
					}
				}
			}
		}
	}
	return -1;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, M;	
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			std::cin >> map[i][j];
			
	std::cout << find_shortest(map, N, M);

	return 0;
}
