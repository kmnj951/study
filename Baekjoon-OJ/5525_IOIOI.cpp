#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    char s;
    std::cin >> N >> M;
    int length = 0;
    const int min_len = N * 2 + 1;
    char pre_s = 'O';
    int count = 0;
    for (int i = 0; i < M; ++i) {
        std::cin >> s;
        if (length > 0) {
            if (s != pre_s)
                ++length;
            else {
                if (length >= min_len) 
                    count += length / 2 - (length + 1) % 2 - N + 1;
                length = 0;
            }   
        }
        if (length == 0 && s == 'I') {
            ++length;  
        }
        pre_s = s;
    }
    if (length >= min_len) 
        count += length / 2 - (length + 1) % 2 - N + 1;
    std::cout << count;

    return 0;
}