#include <iostream>

using namespace std;

bool find(bool (*edge)[100], bool *visit, int i, int j) {
	if (edge[i][j])
		return true;
	if (!visit[i]) {
		visit[i] = true;
		for (int next = 0; next < 100; ++next) {
			if (edge[i][next]) {
				edge[i][j] = find(edge, visit, next, j);
				if (edge[i][j])
					return true;
			}
		}
	}
	
	return false;
}

int main(void) { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	bool edge[100][100] = {{0}};
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			char c;
			cin >> c;
			if (c == '1') 
				edge[i][j] = true;
		}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			bool visit[100] = {0};
			cout << find(edge, visit, i, j) << " ";
		}
		cout << endl;
	}

	return 0;
}
