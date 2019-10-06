#include <iostream>

using namespace std;

enum {
	NORTH, EAST, SOUTH, WEST
};

enum {
	EMPTY, WALL, CLEAN
};

int main(void) {
	int map[50][50];
	int N, M;
	int x, y;
	int next_x, next_y;
	int dir;
	int clean_count = 1;
	bool working = true;
	
	cin >> N >> M;
	cin >> x >> y;
	cin >> dir;
	for (int i = 0; i< N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	} 
	
	map[x][y] = CLEAN;
	while (working) {
		working = false;
		int i;
		for (i = 0; i < 4; ++i) {
			next_x = x;
			next_y = y;
			dir = (dir + 3) % 4;
			switch (dir) {
				case NORTH:
					next_x -= 1;
					break;
				case EAST:
					next_y += 1;
					break;
				case SOUTH:
					next_x += 1;
					break;
				case WEST:
					next_y -= 1;
					break;
			}
			if (map[next_x][next_y] == EMPTY) {	// map 경계는 항상 1 
				x = next_x;
				y = next_y;
				map[x][y] = CLEAN;
				clean_count++;
				working = true;
				break;
			}
		}
		if (i == 4) {	// back
			switch (dir) {
				case NORTH:
					x += 1;
					break;
				case EAST:
					y -= 1;
					break;
				case SOUTH:
					x -= 1;
					break;
				case WEST:
					y += 1;
					break;
			}
			if (map[x][y] == CLEAN)
				working = true;
		}
	}
		
	cout << clean_count;
	return 0;
}
