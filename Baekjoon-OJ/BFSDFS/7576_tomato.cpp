#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ripe_time(vector<vector<int> > &tomato) {
	queue<pair<int,int> > ripe;
	int N = tomato.size();
	int M = tomato[0].size();
	int day = 1;
	int count = 0;

	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			if (tomato[i][j] == 1) {
				ripe.push(make_pair(i,j));
				++count;
			}
			else if (tomato[i][j] == -1)
				++count;
	
	while (!ripe.empty()) {
		pair<int, int> x_y = ripe.front();
		ripe.pop();
		int x = x_y.first;
		int y = x_y.second;
		day = tomato[x][y];
		
		if (x < N-1 && tomato[x+1][y] == 0 ) {
			tomato[x+1][y] = day+1;
			ripe.push(make_pair(x+1, y));
			++count;
		}
		if (y < M-1 && tomato[x][y+1] == 0 ) {
			tomato[x][y+1] = day+1;
			ripe.push(make_pair(x, y+1));
			++count;
		}
		if (x > 0 && tomato[x-1][y] == 0 ) {
			tomato[x-1][y] = day+1;
			ripe.push(make_pair(x-1, y));
			++count;
		}
		if (y > 0 && tomato[x][y-1] == 0 ) {
			tomato[x][y-1] = day+1;
			ripe.push(make_pair(x, y-1));
			++count;
		}
	}
	
	if (count < N * M)
		return -1;
	
	return day-1;
}

int main(void) {
	ios::sync_with_stdio(false);
	int M, N;
	cin >> M >> N; 
	vector<vector<int> > tomato(N);
	for(int i = 0; i < N; ++i) {
		tomato[i] = vector<int>(M);	
		for(int j = 0; j < M; ++j) {
			int k;
			cin >> k;
			tomato[i][j] = k;
		} 
	}
	
	cout << ripe_time(tomato);
	
	return 0;
}
