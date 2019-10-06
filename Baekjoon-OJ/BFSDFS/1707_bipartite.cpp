#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool divide_two_zone(vector<int>* connect, int* zone, int start_v) {
	queue<int> bfs_q;
	bfs_q.push(start_v);
	zone[start_v] = 1;
	
	while (!bfs_q.empty()) {
		int vertex = bfs_q.front();
		bfs_q.pop();
		for (int next_v : connect[vertex]) {
			if (zone[next_v] == zone[vertex])
				return false;
			if (zone[next_v] == 0) {
				bfs_q.push(next_v);
				zone[next_v] = zone[vertex]%2+1;
			}
		}
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int>* connect;
	int* zone;	// 0 --> 1 or 2
	bool bipartite;
	int K, V, E;
	cin >> K;
	for (int k = 0; k < K; ++k) {
		cin >> V >> E;
		connect = new vector<int>[V+1]();
		for (int e = 0; e < E; ++e) {
			int v1, v2;
			cin >> v1 >> v2;
			connect[v1].push_back(v2);
			connect[v2].push_back(v1);
		}
		
		zone = new int[V+1]{};
		bipartite = true;
		for (int v = 1; v <= V; ++v) {
			if (zone[v] == 0 && !divide_two_zone(connect, zone, v)) {
				bipartite = false;
				break;
			}	
		}
		
		if (bipartite)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
			
		delete[] connect;
		delete[] zone;
	}
	return 0;
}
