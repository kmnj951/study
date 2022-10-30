#include <iostream>

#define LIMIT 1000000007LL

int main() {
    long long n;
    std::cin >> n;
    long long m_fibo[3] = {1, 1, 0};
    long long fibo[2] = {1, 0};
    long long tmp;
    n -= 1LL;
    while (n > 0LL) {
        if ((n & 1LL) == 1LL) {
            tmp = m_fibo[1] * fibo[0] + m_fibo[2] * fibo[1];
            fibo[0] = m_fibo[0] * fibo[0] + m_fibo[1] * fibo[1];
            fibo[1] = tmp;
            for (size_t i = 0; i < 2; ++i)
                fibo[i] %= LIMIT;
        }
        tmp = m_fibo[1] * m_fibo[1];
        m_fibo[1] = m_fibo[0] * m_fibo[1] + m_fibo[1] * m_fibo[2];
        m_fibo[0] = m_fibo[0] * m_fibo[0] + tmp;  
        m_fibo[2] = tmp + m_fibo[2] * m_fibo[2];
        
        for (size_t i = 0; i < 3; ++i)
            m_fibo[i] %= LIMIT;
        n >>= 1;
    }
    std::cout << fibo[0];
    return 0;
}