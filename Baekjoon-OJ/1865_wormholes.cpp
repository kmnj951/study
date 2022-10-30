#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

/***
constexpr int inf = (unsigned)-1 >> 1;

bool bellman_ford(const std::vector<std::tuple<int,int,int>>& edge, std::vector<int>& dist) {
    for (size_t i = 1; i < dist.size(); ++i) {
        for (const auto& e : edge) {
            auto [v1, v2, c] = e;
            if (dist[v1] != inf && dist[v1] + c < dist[v2]) {
                dist[v2] = dist[v1] + c;
            }
        }
    }
    for (const auto& e : edge) {
        auto [v1, v2, c] = e;
        if (dist[v1] != inf && dist[v1] + c < dist[v2]) {
            return true;
        }
    }
    return false;
}
***/

bool negative_cycle(const std::vector<std::tuple<int,int,int>>& edge, int vertex_num) {
    std::vector<int> dist(vertex_num + 1);  // If it has negative cycle, distance < 0.
    for (size_t i = 1; i < dist.size(); ++i) {
        for (const auto& e : edge) {
            auto [v1, v2, c] = e;
            if (dist[v1] + c < dist[v2]) {
                dist[v2] = dist[v1] + c;
            }
        }
    }
    for (const auto& e : edge) {
        auto [v1, v2, c] = e;
        if (dist[v1] + c < dist[v2]) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::tuple<int,int,int>> edge;

    int TC;
    int N, M, W;
    int S, E, T;
    std::cin >> TC;
    for (int tc = 0; tc < TC; ++tc) {
        edge.clear();
        std::cin >> N >> M >> W;
        for (int m = 0; m < M; ++m) {
            std::cin >> S >> E >> T;
            edge.emplace_back(S, E, T);
            edge.emplace_back(E, S, T);
        }
        for (int w = 0; w < W; ++w) {
            std::cin >> S >> E >> T;
            edge.emplace_back(S, E, -T);
        }
        
        if (negative_cycle(edge, N))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";

    }
    return 0;
}