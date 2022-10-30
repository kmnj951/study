#include <iostream>
#include <vector>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::vector<int> stickers[2];
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        std::cin >> n;
        for (int i = 0; i < 2; ++i)
            stickers[i].resize(n);
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < n; ++j)
                std::cin >> stickers[i][j];
        
        int max_total[2] = {};
        for (int i = 0; i < n; ++i) {
            int tmp = max(stickers[0][i] + max_total[1], max_total[0]);
            max_total[1] = max(stickers[1][i] + max_total[0], max_total[1]);
            max_total[0] = tmp;
        }
        std::cout << max(max_total[0], max_total[1]) << "\n";
    }
    return 0;
}