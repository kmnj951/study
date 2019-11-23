#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int count_trust_chain(const vector<vector<int>>& trusted, int from) {
	int count = 1;
	queue<int> bfs_q;
	bool hacking[10001] = {0};
	bfs_q.push(from);
	hacking[from] = true;
	
	while(!bfs_q.empty()) {
		from = bfs_q.front();
		bfs_q.pop();
		for (auto t : trusted[from]) {
			if (!hacking[t]) {
				bfs_q.push(t);
				hacking[t] = true;
				++count;
			}		
		}
	}
	return count;	
}

int main(void) {
	int N;
	int M;
	vector<vector<int>> trusted;
	
	cin >> N >> M;
	trusted.resize(N+1);
	for (int i = 0; i < M; ++i) {
		int A, B;
		cin >> A >> B;
		trusted[B].push_back(A);
	}
	
	int max_count = 0;
	vector<int> max_count_PC;
	for (int i = 1; i <= N; ++i) {
		int count = count_trust_chain(trusted, i);
		if (count > max_count) {
			max_count_PC.clear();
			max_count_PC.push_back(i);
			max_count = count;
		}
		else if(count == max_count)
			max_count_PC.push_back(i);
	}
	
	for (auto PC : max_count_PC)
		cout << PC << " ";
}
