#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void deactivate_from(int zone[][100], int N, int rain, int x, int y) {
	queue<pair<int,int> > connected;
	connected.push(make_pair(x, y));
	
	while (!connected.empty()) {
		pair<int, int> xy = connected.front();
		connected.pop();
		x = xy.first;
		y = xy.second;
		
		if (x > 0 && zone[x-1][y] > rain) {
			zone[x-1][y] = -zone[x-1][y];
			connected.push(make_pair(x-1, y));
		}
		if (y > 0 && zone[x][y-1] > rain) {
			zone[x][y-1] = -zone[x][y-1];
			connected.push(make_pair(x, y-1));
		}
		if (x < N-1 && zone[x+1][y] > rain) {
			zone[x+1][y] = -zone[x+1][y];
			connected.push(make_pair(x+1, y));
		}
		if (y < N-1 && zone[x][y+1] > rain) {
			zone[x][y+1] = -zone[x][y+1];
			connected.push(make_pair(x, y+1));
		}
	}
	
}

int safety(int zone[][100], int N, int rain) {
	int num = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (zone[i][j] > rain) {
				zone[i][j] = -zone[i][j];
				++num;
				deactivate_from(zone, N, rain, i, j);
			}
		}
	}

	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < N; ++j) 
			if (zone[i][j] < 0)
				zone[i][j] = -zone[i][j];
	
	return num;
}

int main(void) {
	int N;
	int zone[100][100];
	int max_high = 1;
	int max_num = 1;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> zone[i][j];
			max_high = (zone[i][j] > max_high) ? zone[i][j] : max_high;
		}
	}
	
	for (int rain = 1; rain < max_high; ++rain) {
		int num = safety(zone, N, rain);
		max_num = num > max_num ? num : max_num;
	}
	
	cout << max_num;
		
	return 0;
}
