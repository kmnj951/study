#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

bool is_connected(const std::vector<int>& con, int v1, int v2) {
    int cv1 = con[v1];
    while (cv1 != v1) {
        v1 = cv1;
        cv1 = con[v1];
    }
    int cv2 = con[v2];
    while (cv2 != v2) {
        v2 = cv2;
        cv2 = con[v2];
    }
    if (cv1 == cv2)
        return true;
    return false;
}

void connect(std::vector<int>& con, int v1, int v2) {
    int cv1 = con[v1];
    while (cv1 != v1) {
        v1 = cv1;
        cv1 = con[v1];
    }
    int cv2 = con[v2];
    while (cv2 != v2) {
        v2 = cv2;
        cv2 = con[v2];
    }
    if (cv1 < cv2)
        con[cv2] = cv1;
    else
        con[cv1] = cv2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int V, E;
    std::cin >> V >> E;
    std::vector<std::tuple<int,int,int>> edge;
    for (int i = 0; i < E; ++i) {
        int v, cv, dist;
        std::cin >> v >> cv >> dist;
        edge.emplace_back(v, cv, dist);
    }
    
    // Kruskal
    std::sort(edge.begin(), edge.end(), [](auto&& a, auto&& b){
        return std::get<2>(a) < std::get<2>(b);
    }); 

    std::vector<int> con(V + 1);
    for (size_t i = 0; i < con.size(); ++i)
        con[i] = i;
    int v1, v2, dist;
    int MST_dist = 0;
    for (const auto& e : edge) {
        std::tie(v1, v2, dist) = e;
        if (!is_connected(con, v1, v2)) {
            connect(con, v1, v2);
            MST_dist += dist;
        }
    }
    std::cout << MST_dist;

    return 0;
}