#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

std::ostream& operator<<(std::ostream& os, __uint128_t n) {
    std::string n_str;
    if (n == 0)
        n_str = "0";
    while (n > 0) {
        n_str.push_back(n % 10 + '0');
        n /= 10;
    }
    std::reverse(n_str.begin(), n_str.end());
    return os << n_str;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    m = n - m < m ? n - m : m;
    std::vector<int> nums(n + 1, 1);
    for (size_t i = n - m + 1; i < nums.size(); ++i) {
        nums[i] = i;
    }
    for (int div = m; div >= 2; --div) {
        nums[div] = div;
        for (size_t i = n - m + 1; i < nums.size() && nums[div] != 1; ++i) {
            int d = gcd(nums[div], nums[i]);
            nums[div] /= d;
            nums[i] /= d;
        }
    }

    __uint128_t ans = 1;
    for (size_t i = n - m + 1; i < nums.size(); ++i)
        ans *= nums[i];
    std::cout << ans;
    return 0;
}

/*
int combination(int n, int m) {
    static int comb[101][101] = {};
    if (m == n || m == 0)
        return comb[n][m] = 1;
    return comb[n][m] = combination(n-1, m) + combination(n-1, m-1);
}
*/