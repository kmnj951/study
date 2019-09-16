#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int main(void) {
	int N;
	int M;
	cin >> N >> M;
	//bool maze[100][100];
	//bool skip[100][100] = {{0}};
	vector<vector<bool> > maze(N);
	vector<vector<bool> > skip(N);
	queue<tuple<int, int, int>> candidate;
	char c;
	for(int i = 0; i < N; ++i) {
		maze[i] = vector<bool>(M);
		skip[i] = vector<bool>(M);
		for(int j = 0; j < M; ++j) {
			cin >> c;
			if( c == '0' )
				maze[i][j] = false;
			else
				maze[i][j] = true;
		}
	}
	
	candidate.push(make_tuple(0,0,1));
	skip[0][0] = true;
	
	int distance;
	while (!candidate.empty()) {
		int i, j, depth;
		tie(i, j, depth) = candidate.front();
		candidate.pop();
		if(i == N-1 && j == M-1) {
			distance = depth;
			break;
		}
		
		if (i < N-1 && !skip[i+1][j] && maze[i+1][j]) {
			candidate.push(make_tuple(i+1, j, depth+1));
			skip[i+1][j] = true;
		}	
		if (j < M-1 && !skip[i][j+1] && maze[i][j+1]) {
			candidate.push(make_tuple(i, j+1, depth+1));
			skip[i][j+1] = true;
		}
		if (i > 0 && !skip[i-1][j] && maze[i-1][j]) {
			candidate.push(make_tuple(i-1, j, depth+1));
			skip[i-1][j] = true;
		}
		if (j > 0 && !skip[i][j-1] && maze[i][j-1]) {
			candidate.push(make_tuple(i, j-1, depth+1));
			skip[i][j-1] = true;
		}
	}
	cout << distance;
	
	return 0;
}
