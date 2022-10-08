#include <iostream>
#include <array>
#include <list>
#include <tuple>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<int, 101> board = {};    // initialize
    int N, M;
    int from, to;
    std::cin >> N >> M;
    for (int i = 0; i < N + M; ++i) {
        std::cin >> from >> to;
        board[from] = to;
    }

    int count = 0;
    int player = 1;
    std::list<std::pair<int,int>> queue; 
    queue.emplace_back(player, count);
    while (!queue.empty() && player != 100) {
        std::tie(player, count) = queue.front();
        queue.pop_front();
        int move = player;
        for (int dice = 1; dice <= 6; ++dice) {
            int dice_move = player + dice;
            if (dice_move == 100) {
                player = move = dice_move;
                ++count;
                break;
            }
            if (board[dice_move] == 0)
                move = dice_move;
            else if (board[dice_move] - player > 6)
                queue.emplace_back(board[dice_move], count+1);
            else if (board[dice_move] < player)
                queue.emplace_back(board[dice_move], count+1);
        }
        if (player != move)
            queue.emplace_back(move, ++count);
    }
    std::cout << count;
    return 0;
}

// 2 1
// 2 52
// 51 99
// 53 50