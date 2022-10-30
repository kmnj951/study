#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> sum(N + 1);
    for (auto& m : sum)
        m.resize(N + 1);
    for (size_t i = 1; i < sum.size(); ++i)
        for (size_t j = 1; j < sum[0].size(); ++j) {
            std::cin >> sum[i][j];
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    
    int x[2], y[2];
    int prefix_sum;
    for (int i = 0; i < M; ++i) {
        std::cin >> x[0] >> y[0] >> x[1] >> y[1];
        prefix_sum = sum[x[1]][y[1]] - sum[x[0]-1][y[1]] 
                     - sum[x[1]][y[0]-1] + sum[x[0]-1][y[0]-1];
        std::cout << prefix_sum << "\n";
    }

    return 0;
}