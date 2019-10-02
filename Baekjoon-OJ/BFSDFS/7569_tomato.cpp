#include <iostream>
#include <queue>
#include <tuple>

int tomato[100][100][100];

using namespace std;

int ripe_day(int tomato[][100][100], int M, int N, int H) {
	int day = 1;
	int count = 0;
	queue<tuple<int,int,int> > connected;
	
	for (int i = 0; i < M; ++i) {	
		for (int j = 0; j < N; ++j) {
			for (int h = 0; h < H; ++h) {
				if (tomato[i][j][h] > 0) {
					connected.push(make_tuple(i, j, h));
					++count;
				}
				else if (tomato[i][j][h] < 0)
					++count;
			}
		}
	}
	
	while (!connected.empty()) {
		int x, y, z;
		tie(x, y, z) = connected.front();
		connected.pop();
		day = tomato[x][y][z];
		
		if (x > 0 && tomato[x-1][y][z] == 0) {
			connected.push(make_tuple(x-1, y, z));
			tomato[x-1][y][z] = day+1;
			++count;
		} 
		if (y > 0 && tomato[x][y-1][z] == 0) {
			connected.push(make_tuple(x, y-1, z));
			tomato[x][y-1][z] = day+1;
			++count;
		} 
		if (z > 0 && tomato[x][y][z-1] == 0) {
			connected.push(make_tuple(x, y, z-1));
			tomato[x][y][z-1] = day+1;
			++count;
		} 
		if (x < M-1 && tomato[x+1][y][z] == 0) {
			connected.push(make_tuple(x+1, y, z));
			tomato[x+1][y][z] = day+1;
			++count;
		} 
		if (y < N-1 && tomato[x][y+1][z] == 0) {
			connected.push(make_tuple(x, y+1, z));
			tomato[x][y+1][z] = day+1;
			++count;
		} 
		if (z < H-1 && tomato[x][y][z+1] == 0) {
			connected.push(make_tuple(x, y, z+1));
			tomato[x][y][z+1] = day+1;
			++count;
		} 
	}
	
	if (count < M * N * H)
		return -1;
		
	return day-1;
}

int main(void) {
	int M, N, H;
	cin >> M >> N >> H;
	for (int h = 0; h < H; ++h) {
		for (int j = 0; j < N; ++j) {
			for (int i = 0; i < M; ++i) {
				cin >> tomato[i][j][h];
			}
		}
	}
	cout << ripe_day(tomato, M, N, H);
	return 0;
}
