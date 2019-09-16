#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	int M;
	int V;
	cin >> N >> M >> V;

	vector<vector<int>> graph(N+1);
	for (int i = 0; i < M; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	for (vector<int>& v : graph) {
		sort(v.begin(), v.end());
	}
	
	//DFS
	vector<bool> skip(N+1);
	vector<int> dfs;
	vector<int> stack;
	int pop = V;
	vector<int> cur = graph[V];
	skip[pop] = true;
	dfs.push_back(pop);
	for(auto it = cur.rbegin(); it!=cur.rend(); ++it)
		stack.push_back(*it);

	while (!stack.empty()) {
		pop = stack.back();
		stack.pop_back();
		if (!skip[pop]) {
			cur = graph[pop];
			dfs.push_back(pop);
			for (auto it = cur.rbegin(); it != cur.rend(); ++it)
				stack.push_back(*it);
			skip[pop] = true;
		}
	}
	
	//BFS
	vector<bool> skip2(N+1);
	vector<int> bfs;
	list<int> queue;
	pop = V;
	skip2[pop] = true;
	cur = graph[V];
	bfs.push_back(pop);
	for (auto v : cur)
		queue.push_back(v);

	while (!queue.empty()) {
		pop = queue.front();
		queue.pop_front();
		if (!skip2[pop]) {
			cur = graph[pop];
			bfs.push_back(pop);
			for (auto v : cur)
				queue.push_back(v);
			skip2[pop] = true;
		}
	}
	
	for (auto v : dfs)
		cout << v << " ";
	cout << endl;

	for (auto v : bfs)
		cout << v << " ";

	return 0;
}
