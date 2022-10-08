#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#define min(a, b) ((a) <= (b) ? (a) : (b))

constexpr int inf = (unsigned)-1 >> 1;

class Distance {
private:
    int v;
    int dist;
public:
    Distance (int _v, int _dist) : v(_v), dist(_dist) {}
    bool operator<(const Distance& d) const {
        return dist < d.dist;
    }
    bool operator>(const Distance& d) const {
        return dist > d.dist;
    }
    int get_v() const {
        return v;
    }
};

int dijkstra(std::vector<std::vector<int>>& graph, size_t start, size_t end) {
    //std::vector<int> dist(graph[start].begin(), graph[start].end());
    std::priority_queue<Distance, std::vector<Distance>, std::greater<Distance>> queue;
    for (size_t i = 1; i < graph[start].size(); ++i) {
        if (graph[start][i] != 0 && graph[start][i] != inf)
            queue.emplace(i, graph[start][i]);
    }
    bool visit[801] = {};
    while (!queue.empty()) {
        int v = queue.top().get_v();
        queue.pop();
        if (!visit[v])
            for (size_t i = 1; i < graph[1].size(); ++i) {
                if (graph[v][i] != inf) {
                    if (graph[start][i] > graph[start][v] + graph[v][i]) {
                        graph[start][i] = graph[start][v] + graph[v][i];
                        queue.emplace(i, graph[start][i]);
                    }
                }
            }
        visit[v] = true;
    }
    int ans = graph[start][end] != inf ? graph[start][end] : -1;
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, E;
    std::cin >> N >> E;
    std::vector<std::vector<int>> graph(N + 1);
    for (auto& g : graph) {
        g.resize(N + 1, inf);
    }
    int v1, v2;
    for (int i = 0; i < E; ++i) {
        std::cin >> v1 >> v2;
        std::cin >> graph[v1][v2];
        graph[v2][v1] = graph[v1][v2];
    }
    for (int i = 1; i <= N; ++i) {
        graph[i][i] = 0; 
    }
    std::cin >> v1 >> v2;
    int dst = -1;
    int d[3];
    if ((d[0] = dijkstra(graph, 1, v1)) != -1
        && (d[1] = dijkstra(graph, v1, v2)) != -1
        && (d[2] = dijkstra(graph, v2, N)) != -1) {
        dst = dijkstra(graph, 1, v2) + dijkstra(graph, v2, v1) + dijkstra(graph, v1, N);
        dst = d[0] + d[1] + d[2] < dst ? d[0] + d[1] + d[2] : dst;
    }
    std::cout << dst;
    return 0;
}