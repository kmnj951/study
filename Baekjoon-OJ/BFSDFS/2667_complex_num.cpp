#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int find_connect_num(const int N, bool map[][25], bool visit[][25], int x, int y) {
	
	// BFS
	int count = 0;
	queue<tuple<int, int>> candidate;
	candidate.push(make_tuple(x,y));
	while (!candidate.empty()) {
		tie(x, y) = candidate.front();
		candidate.pop();
		++count;
		if (x < N-1 && !visit[x+1][y] && map[x+1][y]) {
			candidate.push(make_tuple(x+1, y));
			visit[x+1][y] = true;
		}
		if (x > 0 && !visit[x-1][y] && map[x-1][y]) {
			candidate.push(make_tuple(x-1, y));
			visit[x-1][y] = true;
		}
		if (y < N-1 && !visit[x][y+1] && map[x][y+1]) {
			candidate.push(make_tuple(x, y+1));
			visit[x][y+1] = true;
		}
		if (y > 0 && !visit[x][y-1] && map[x][y-1]) {
			candidate.push(make_tuple(x, y-1));
			visit[x][y-1] = true;
		}
	}	
	
	//DFS
/*	int count = 1;
	if (x < N-1 && !visit[x+1][y] && map[x+1][y]) {
		visit[x+1][y] = true;
		count += find_connect_num(N, map, visit, x+1, y);
	}
	if (x > 0 && !visit[x-1][y] && map[x-1][y]) {
		visit[x-1][y] = true;
		count += find_connect_num(N, map, visit, x-1, y);
	}
	if (y < N-1 && !visit[x][y+1] && map[x][y+1]) {
		visit[x][y+1] = true;
		count += find_connect_num(N, map, visit, x, y+1);
	}
	if (y > 0 && !visit[x][y-1] && map[x][y-1]) {
		visit[x][y-1] = true;
		count += find_connect_num(N, map, visit, x, y-1);
	}*/
	
	return count;
}

int main(void) {
	int N;
	cin >> N;
	bool map[25][25];
	bool visit[25][25] = {{false}};
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			char c;
			cin >> c;
			if (c == '0')
				map[i][j] = false;
			else
				map[i][j] = true;
		}
	
	vector<int> answer;
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < N; ++j) 
			if (!visit[i][j]) {
				visit[i][j] = true;
				if (map[i][j])
					answer.push_back(find_connect_num(N, map, visit, i, j));	
			}
	
	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (int ans : answer)
		cout << ans << endl;
	
	return 0;
}
