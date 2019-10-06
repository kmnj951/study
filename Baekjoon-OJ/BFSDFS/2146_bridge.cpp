#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define max ((unsigned)-1>>1)

using namespace std;

vector<pair<int,int> > find_boundary(int map[][100], int N, const pair<int,int> &start, int zone_num) {
	vector<pair<int, int> > boundary;
	queue<pair<int, int> > candidate;
	candidate.push(start); // ..
	
	while (!candidate.empty()) {
		pair<int, int> land = candidate.front();
		int x = land.first;
		int y = land.second;
		candidate.pop();
		
		for (int i = 0; i < 4; ++i) {
			int direct[4] = {-1, 1, 0, 0};
			int next_x = x + direct[i];
			int next_y = y + direct[3-i];
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
				if (map[next_x][next_y] == 1) {
					map[next_x][next_y] = -1;
					candidate.push(make_pair(next_x, next_y));
				}
				else if (map[x][y] != zone_num && map[next_x][next_y] == 0) {
					map[x][y] = zone_num;
					boundary.push_back(make_pair(x, y));
				}
			}
		}
	}
	
	return boundary;
}

int find_shortest(int map[][100], int N, const vector<vector<pair<int,int> > > &bounds) {
	int dist[100][100] = {{0}};
	queue<pair<int, int> > find_land;
	int shortest = max;
	for (int i = 0; i < bounds.size(); ++i)
		for (int j = 0; j < bounds[i].size(); ++j)
			find_land.push(bounds[i][j]);
	
	// map
	int distance[100][100] = {{0}};
	while (!find_land.empty()) {
		pair<int, int> find = find_land.front();
		int x = find.first;
		int y = find.second;
		find_land.pop();
		if (map[x][y] < 0)
			map[x][y] = -map[x][y];
		//cout << x << " " << y <<  ": " << distance[x][y] << endl;
		
		for (int i = 0; i < 4; ++i) {
			int direct[4] = {-1, 1, 0, 0};
			int next_x = x + direct[i];
			int next_y = y + direct[3-i];
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
				if (map[next_x][next_y] == 0) {
					map[next_x][next_y] = -map[x][y];	// just branch
					distance[next_x][next_y] = distance[x][y] + 1;
					//cout << next_x << " " << next_y <<  " " << distance[next_x][next_y] << endl;
					find_land.push(make_pair(next_x, next_y));
				}
				else if (map[next_x][next_y] > 0 && map[next_x][next_y] != map[x][y]) {
					shortest = distance[next_x][next_y] + distance[x][y];
					//cout << next_x << " " << next_y << " " << x << " " << y << endl;
					return shortest;
				}
			}
		}
	}
	return shortest;
}

int main(void) {
	vector<vector<pair<int,int> > > boundarys;
	int N;
	int map[100][100] = {{0}};
	// land: 1 -> ( -1 or zone_num), zone_num: 2 ~
	
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> map[i][j];
	
	int zone = 2;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (map[i][j] == 1)
				boundarys.push_back(find_boundary(map, N, make_pair(i,j), zone++));
	
	cout << find_shortest(map, N, boundarys) << endl;
	
	return 0;
}
