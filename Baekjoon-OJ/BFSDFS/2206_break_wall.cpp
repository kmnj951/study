#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char map[1000][1000];
short depth[1000][1000] = {{1}};
short depth_break[1000][1000] = {{1}};

int find_shortest(char map[][1000], int N, int M) {
	int dir[4] = {0, 0, -1, 1};
	queue<tuple<int, int, bool> > bfs_q;
	bfs_q.push(make_tuple(0, 0, false));

	while (!bfs_q.empty()) {
		int x, y, wall_break;
		tie(x, y, wall_break) = bfs_q.front();
		bfs_q.pop();
		if (x == N-1 && y == M-1)
			if(wall_break)
				return depth_break[x][y];
			else
				return depth[x][y];
		
		/* if (wall_break)
			cout << depth_break[x][y];
		else
			cout << depth[x][y];
		cout << ": " << x << " " << y << " " << wall_break << endl; */
		for (int i = 0; i < 4; ++i) {
			int next_x = x + dir[i];
			int next_y = y + dir[3-i];
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M &&
					depth[next_x][next_y] == 0) {
				if (wall_break) {
					if (depth_break[next_x][next_y] == 0 && map[next_x][next_y] == '0') {	
						depth_break[next_x][next_y] = depth_break[x][y] + 1;
						bfs_q.push(make_tuple(next_x, next_y, wall_break));
					}	
				}
				else {
					if (map[next_x][next_y] == '0') {
						depth[next_x][next_y] = depth[x][y] + 1;
						bfs_q.push(make_tuple(next_x, next_y, wall_break));
					}
					else {
						depth_break[next_x][next_y] = depth[x][y] + 1;
						bfs_q.push(make_tuple(next_x, next_y, !wall_break));
					}
				}
			}
		}
	}
	return -1;
}

int main(void) {
	int N, M;	
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> map[i][j];

	cout << find_shortest(map, N, M);
	return 0;
}
