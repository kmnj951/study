#include <iostream>
#include <vector>

int squares_count(int num) {
    int count = 4;
    std::vector<int> square;
    for (int sq, i = 0; (sq = i * i) <= num; ++i)
        square.push_back(sq);
    
    for (auto rit = square.rbegin(); *rit >= num/3; ++rit) {
        int num2 = num - *rit;
        if (num2 == 0)
            return 1;
        for (auto it2 = square.begin(); *it2 <= num2>>1; ++it2) {
            int num3 = num2 - *it2;
            for (auto it3 = it2; *it3 <= num3; ++it3) {
                if (*it3 == num3) {
                    if (*it2 == 0) 
                        return 2;
                    count = 3;
                }
            }
        }
    }
    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << squares_count(n);
    return 0;
}