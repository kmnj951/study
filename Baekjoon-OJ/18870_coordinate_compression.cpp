#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<std::pair<int, int>> coord;
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int X;
        std::cin >> X;
        coord.emplace_back(X, i);
    }
    std::sort(coord.begin(), coord.end(), [](auto&& a, auto&& b) {
        return a.first < b.first;
    });

    int i = -1;
    int pre = coord.begin()->first + 1;
    for (auto it = coord.begin(); it != coord.end(); ++it) {
        if (pre == it->first)
            it->first= i;
        else {
            pre = it->first;
            it->first = ++i;
        }
    }
    std::sort(coord.begin(), coord.end(), [](auto&& a, auto&& b) {
        return a.second < b.second;
    });
    for (const auto& X : coord) {
        std::cout << X.first << " ";
    }
    return 0;
}