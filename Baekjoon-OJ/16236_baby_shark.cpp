#include <iostream>
#include <vector>
#include <list>
#include <tuple>

// BFS
class Shark {
private:
    size_t row;
    size_t col;
    int size;
    int eat;
    int time;
public:
    Shark(size_t _row = 0, size_t _col = 0, int _size = 0, int _eat = 0, int _time = 0)
        : row(_row), col(_col), size(_size), eat(_eat), time(_time) {}
    //Shark(const Shark& s) ... default copy constructor

    bool find_food(std::vector<std::vector<int>>& sea) {
        static constexpr int r_d[4] = {-1, 0, 0, 1};
        static constexpr int c_d[4] = {0, -1, 1, 0};

        std::vector<std::vector<int>> visit(sea);
        std::list<std::tuple<size_t, size_t, int>> queue;
        queue.emplace_back(row, col, time);
        visit[row][col] = -1;
        bool is_found = false;
        Shark found;
        while (!queue.empty()) {
            auto [r, c, t] = queue.front();
            queue.pop_front();
            if (is_found && t > found.time)
                break;
            if (sea[r][c] != 0 && sea[r][c] < size) {
                if (!is_found || (is_found && (r < found.row || (r == found.row && c < found.col)))) {
                    is_found = true;
                    found = {r, c, size, eat, t};
                }
            }
            else {
                ++t;
                for (size_t d = 0; d < 4; ++d) {
                    size_t r_next = r + r_d[d];
                    size_t c_next = c + c_d[d];
                    if (r_next < sea.size() && c_next < sea.size() && sea[r_next][c_next] <= size && visit[r_next][c_next] != -1) {
                        visit[r_next][c_next] = -1;
                        queue.emplace_back(r_next, c_next, t);
                    }
                }
            }
        }
        if (is_found) {
            *this = found;
            sea[row][col] = 0;
            if (++eat == size) {
                eat = 0;
                ++size;
            }
            return true;
        }
        return false;
    }

    int get_time() {
        return time;
    }

};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t N;
    std::cin >> N;
    
    std::vector<std::vector<int>> sea(N);
    Shark shark;
    for (size_t i = 0; i < N; ++i) {
        sea[i].resize(N);
        for (size_t j = 0; j < N; ++j) {
            std::cin >> sea[i][j];
            if (sea[i][j] == 9) {
                shark = {i, j, 2, 0, 0};
                sea[i][j] = 0;
            }
                
        }
    }
    
    while (shark.find_food(sea))
        ;

    std::cout << shark.get_time();
    return 0;
}