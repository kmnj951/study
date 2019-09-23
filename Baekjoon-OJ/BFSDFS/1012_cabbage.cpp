#include <iostream>
#include <queue>

using namespace std;

void erase_connect(vector<vector<bool> > &cabbage, int x, int y) {
	int M = cabbage.size();
	int N = cabbage[0].size();
	queue<pair<int, int> > next;
	
	next.push(make_pair(x,y));
	cabbage[x][y] = false;
	
	while (!next.empty()) {
		pair<int, int> x_y = next.front();
		int x = x_y.first;
		int y = x_y.second;
		next.pop();
		
		int pos[4] = {-1, 1, 0, 0};
		for (int i = 0; i < 4; ++i) { 
			int nx = x + pos[i];
			int ny = y + pos[3-i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N && cabbage[nx][ny]) {
				cabbage[nx][ny] = false;
				next.push(make_pair(nx, ny));
			}
		}
	}
	
	/* DFS
	if (x > 0 && cabbage[x-1][y]) {
		cabbage[x-1][y] = false;
		erase_connect(cabbage, x-1, y);
	}
	if (y > 0 && cabbage[x][y-1]) {
		cabbage[x][y-1] = false;
		erase_connect(cabbage, x, y-1);
	}
	if (x < M-1 && cabbage[x+1][y]) {
		cabbage[x+1][y] = false;
		erase_connect(cabbage, x+1, y);
	}
	if (y < N-1 && cabbage[x][y+1]) {
		cabbage[x][y+1] = false;
		erase_connect(cabbage, x, y+1);
	}
	*/	
		
}

int earthworm(vector<vector<bool> > &cabbage) {
	int M = cabbage.size();
	int N = cabbage[0].size();
	int count = 0;
	
	for (int i = 0; i < M; ++i) 
		for (int j = 0; j < N; ++j)
			if(cabbage[i][j]) {
				erase_connect(cabbage, i, j);
				++count;
			}

	return count;
}

int main(void) {
	int T;
	int M, N, K;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> M >> N >> K;
		vector<vector<bool> > cabbage(M);
		for (int i = 0; i < M; ++i) {
			cabbage[i] = vector<bool>(N);
		}
		for (int i = 0; i < K; ++i) {
			int x, y;
			cin >> x >> y;
			cabbage[x][y] = true;
		}
		cout << earthworm(cabbage) << endl;
	}
	
	return 0;
}
