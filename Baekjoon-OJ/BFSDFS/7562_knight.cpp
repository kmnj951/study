#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int knight(int L, int x, int y, int dst_x, int dst_y) {
	bool visit[300][300] = {{0}};
	queue<tuple<int,int,int> > next;
	int step = 0;
	next.push(make_tuple(x,y,step));
	
	while (!next.empty()) {
		tie(x, y, step) = next.front(); 
		next.pop();
		
		if (x == dst_x && y == dst_y)
			return step;
		
		int direct[8] = {1,1,-1,-1,-2,2,-2,2};
		for (int i = 0; i < 8; ++i) {
			int nx = x + direct[i];
			int ny = y + direct[7-i];
			
			if (nx >= 0 && ny >= 0 && nx < L && ny < L && !visit[nx][ny]) {
				visit[nx][ny] = true;
				next.push(make_tuple(nx, ny, step+1));	
			}
		}
	}
	return -1;
}

int main(void) {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int L;
		int x, y;
		int dst_x, dst_y;
		cin >> L;
		cin >> x >> y >> dst_x >> dst_y;
		cout << knight(L, x, y, dst_x, dst_y) << endl;
	}
	return 0;
}
