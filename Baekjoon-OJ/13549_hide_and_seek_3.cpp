#include <iostream>
#include <queue>

int find_fastest_time(int from, int to) {
    constexpr int max = 100000;
    int fastest_time = max;
    bool visit[max + 1] = {};
    std::queue<std::pair<int,int>> loc;
    visit[from] = true;
    loc.emplace(from, 0);
    while (!loc.empty()) {
        std::pair<int,int> loc_time = loc.front();
        loc.pop();
        if (loc_time.second > fastest_time)
            break;
        if (loc_time.first == to) {
            fastest_time = loc_time.second < fastest_time ? loc_time.second : fastest_time;
        }
        if (loc_time.first < to)  {
            int doubling = loc_time.first<<1;
            while (doubling <= max && !visit[doubling] && doubling < to) {
                visit[doubling] = true;
                loc.emplace(doubling, loc_time.second);
                doubling <<= 1;
            }
            if (doubling <= max && !visit[doubling]) {
                visit[doubling] = true;
                loc.emplace(doubling, loc_time.second);
            }
            if (loc_time.first + 1 <= max && !visit[loc_time.first + 1]) {
                visit[loc_time.first + 1] = true;
                loc.emplace(loc_time.first + 1, loc_time.second + 1);
            }
            if (loc_time.first - 1 >= 0 && !visit[loc_time.first - 1]) {
                visit[loc_time.first - 1] = true;
                loc.emplace(loc_time.first - 1, loc_time.second + 1);
            }     
        }
        else if (loc_time.first - 1 >=0 && !visit[loc_time.first - 1]) {
            visit[loc_time.first - 1] = true;
            loc.emplace(loc_time.first - 1, loc_time.second + 1);
        }
    }
    return fastest_time;
}

int main() {
    int N, K;
    std::cin >> N >> K;
    std::cout << find_fastest_time(N, K);
    return 0;
}