#include <iostream>
#include <vector>
#include <algorithm>

void print_seq(const std::vector<int>& nums, int seq_size, int depth) {
    static bool visit[10001] = {};
    static int choice[8] = {};
    if (seq_size == depth) {
        for (int s = 0; s < seq_size; ++s)
            std::cout << choice[s] << " ";
        std::cout << "\n";
        return;
    }
    for (size_t i = 0; i < nums.size(); ++i) {
        if (!visit[i]) {
            visit[i] = true;
            choice[depth] = nums[i];
            print_seq(nums, seq_size, depth + 1);
            visit[i] = false;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    std::vector<int> nums(N);
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end());
    print_seq(nums, M, 0);

    return 0;
}