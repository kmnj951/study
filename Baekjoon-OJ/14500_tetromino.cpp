#include <iostream>
#include <vector>
#include <tuple>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::vector<int>> paper;
    int N, M;
    std::cin >> N >> M;
    paper.resize(N);
    for (auto& line : paper) {
        line.resize(M);
        for (int& space : line) {
            std::cin >> space;
        }
    }

    std::vector<std::tuple<int,int,int,int,int>> stack;
    int r, c, pre, depth, sum;
    int max_sum = 0;
    int direct[4] = {-1, 0, 1, 0};  // clockwise
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            stack.emplace_back(i, j, 4, 0, 0);
            while (!stack.empty()) {
                std::tie(r, c, pre, depth, sum) = stack.back();
                stack.pop_back();
                if (r >= 0 && r < N && c >= 0 && c < M) {
                    sum += paper[r][c];
                    ++depth;
                    if (depth == 4)
                        max_sum = sum > max_sum ? sum : max_sum;
                    else
                        for (int d = 0; d < 4; ++d)
                            if (d != pre)
                                stack.emplace_back(r + direct[d], c + direct[3-d], (d+2)%4, depth, sum);
                }
            }
            // shape which can't be found in dfs
            sum = paper[i][j];
            int min = 1000; 
            for (int d = 0; d < 4; ++d) {
                std::pair<int,int> adj{i + direct[d], j + direct[3-d]};      
                if (adj.first >= 0 && adj.first < N && adj.second >= 0 && adj.second < M) {
                    min = paper[adj.first][adj.second] < min ? paper[adj.first][adj.second] : min;
                    sum += paper[adj.first][adj.second];
                }
                else
                    min = 0;
            }
            max_sum = sum - min > max_sum ? sum - min : max_sum;
        }
    }
    std::cout << max_sum;

    return 0;
}