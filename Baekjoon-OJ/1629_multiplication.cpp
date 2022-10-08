#include <iostream>

// exponentiation
int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    long long mul = 1;
    long long sq = A;
    while (B > 0) {
        if ((B & 1) == 1) {
            mul *= sq;
            if (mul > C)
                mul %= C;
        }
        B >>= 1;
        sq *= sq;
        if (sq > C)
            sq %= C;
    }
    std::cout << mul;
    return 0;
}