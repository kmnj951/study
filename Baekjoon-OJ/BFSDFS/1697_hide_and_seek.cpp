#include <iostream>
#include <queue>

using namespace std;

int find_sibling(int me, const int sibling) {
	queue<pair<int,int>> going;
	bool visit[100001] = {0};
	int sec = 0;
	
	going.push(make_pair(me, 0));
	visit[me] = true;
	
	while (!going.empty()) {
		pair<int, int> me_sec = going.front();
		me = me_sec.first;
		sec = me_sec.second;
		going.pop();
		if (me == sibling)
			break;
		if (me > 0 && !visit[me-1]) {
			visit[me-1] = true;
			going.push(make_pair(me-1, sec+1));
		}
		if (me < 100000 && !visit[me+1]) {
			visit[me+1] = true;
			going.push(make_pair(me+1, sec+1));
		}
		if (me <= 50000 && me < sibling && !visit[me*2]) {
			visit[me*2] = true;
			going.push(make_pair(me*2,sec+1));
		}
	}
	return sec;
} 

int main(void) {
	int N, K;
	int sec = 0;
	cin >> N >> K;

	cout << find_sibling(N,K);
	
	return 0;
}
