#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <random>
#include <ctime>

class BigNum {
private:
    std::string num;
    bool minus;
private:
    void del_zero();
    BigNum mul(const BigNum&) const; // Karatsuba algorithm
    BigNum operator<<(int) const;
public:
    BigNum();
    BigNum(int n);
    BigNum(const std::string& n, bool m = false);
    BigNum(const BigNum& bn);
    ~BigNum();
    BigNum operator-() const;
    bool operator==(const BigNum&) const;
    bool operator!=(const BigNum&) const;
    bool operator<=(const BigNum&) const;
    bool operator>=(const BigNum&) const;
    bool operator<(const BigNum&) const;
    bool operator>(const BigNum&) const;
    BigNum& operator+=(const BigNum&);
    BigNum& operator-=(const BigNum&);
    BigNum& operator*=(const BigNum&);
    BigNum operator+(const BigNum&) const;
    BigNum operator-(const BigNum&) const;
    BigNum operator*(const BigNum&) const;
    friend std::istream& operator>>(std::istream& is, BigNum& bn);
    friend std::ostream& operator<<(std::ostream& os, const BigNum& bn);
    BigNum basic_mul(const BigNum&) const;
};

BigNum::BigNum() : minus(false) {}
BigNum::BigNum(int n) : minus(false) {
    if (n < 0) {
        minus = true;
        n = -n;
    }
    while (n > 0) {
        num.push_back(n % 10 + '0');
        n /= 10;
    }
}
BigNum::BigNum(const std::string& n, bool m) : num(n), minus(m) {del_zero();}
BigNum::BigNum(const BigNum& bn) : num(bn.num), minus(bn.minus) {}
BigNum::~BigNum() {}

void BigNum::del_zero() {
    size_t count = 0;
    for (auto rit = num.rbegin(); rit != num.rend() && (*rit == '0'); ++rit) {
        ++count;
    }
    num.resize(num.size()-count);
    if (num.size() == 0)
        minus = false;
}
BigNum BigNum::operator<<(int n) const {
    BigNum result;
    result.num.resize(n, '0');
    for (char ch : num) {
        result.num.push_back(ch);
    }
    result.minus = minus;
    return result;
}
BigNum BigNum::operator-() const {
    return BigNum(num, !minus);
}
bool BigNum::operator==(const BigNum& bn) const {
    if (minus == bn.minus && num.size() == bn.num.size()) {
        size_t i;
        for (i = 0; i < num.size() && num[i] == bn.num[i]; ++i)
            ;
        if (i == num.size())
            return true;
    }
    return false;
}
bool BigNum::operator!=(const BigNum& bn) const {
    return !(*this == bn);
}
bool BigNum::operator<=(const BigNum& bn) const {
    if (minus != bn.minus) {
        if (minus)
            return true;
        else
            return false;
    }
    if (num.size() < bn.num.size())
        return true;
    if (num.size() > bn.num.size())
        return false;
    std::string::const_reverse_iterator rit1, rit2;
    for (rit1 = num.rbegin(), rit2 = bn.num.rbegin(); rit1 != num.rend() && *rit1 == *rit2; ++rit1, ++rit2)
        ;
    if (rit1 != num.rend()) {
        if (minus && *rit1 < *rit2)
            return false;
        if (!minus && *rit1 > *rit2)
            return false;
    }
    return true;
}
bool BigNum::operator>=(const BigNum& bn) const {
    return bn <= *this;
}
bool BigNum::operator<(const BigNum& bn) const {
    return !(*this >= bn);
}
bool BigNum::operator>(const BigNum& bn) const {
    return !(*this <= bn);
}
BigNum& BigNum::operator+=(const BigNum& bn) {
    if (minus == bn.minus) {
        if (num.size() < bn.num.size())
            num.resize(bn.num.size(), '0');
        
        bool carry = false;
        size_t i;
        for (i = 0; i < bn.num.size(); ++i) {
            num[i] += bn.num[i] - '0';
            if (carry) {
                ++num[i];
                carry = false;
            }
            if (num[i] > '9') {
                num[i] -= 10;
                carry = true;
            }
        }
        while (carry) {      
            if (i >= num.size()) {
                num.push_back('0');
            }
            ++num[i];
            carry = false;
            if (num[i] > '9') {
                num[i] -= 10;
                carry = true;
            }
            ++i;
        }
    }
    else {
        BigNum minuend, subtrahend;
        if (minus) {
            if (-*this > bn) {
                minuend = *this;
                subtrahend = bn;
            }
            else {
                minuend = bn;
                subtrahend = -*this;
            }
        }
        else {
            if (*this > -bn) {
                minuend = *this;
                subtrahend = -bn;
            }
            else {
                //negative = true;
                minuend = bn; // -bn
                subtrahend = *this;
            }
        }
        
        bool regroup = false;
        size_t i;
        for (i = 0; i < subtrahend.num.size(); ++i) {
            minuend.num[i] -= subtrahend.num[i] - '0';
            if (regroup) {
                --minuend.num[i];
                regroup = false;
            }
            if (minuend.num[i] < '0') {
                minuend.num[i] += 10;
                regroup = true;
            }
        }
        while (regroup) {      
            --minuend.num[i];
            regroup = false;
            if (minuend.num[i] < '0') {
                minuend.num[i] += 10;
                regroup = true;
            }
            ++i;
        }

        *this = minuend;
    }
    del_zero();
    return *this;
}
BigNum& BigNum::operator-=(const BigNum& bn) {
    *this += -bn;
    return *this;
}
BigNum BigNum::basic_mul(const BigNum& bn) const {
    BigNum result;
    const size_t size = num.size() + bn.num.size();
    std::vector<int> tmp(size);

    for (size_t i = 0; i < num.size(); ++i)
        for (size_t j = 0; j < bn.num.size(); ++j)
            tmp[i+j] += (num[i] - '0') * (bn.num[j] - '0');

    size_t carry = 0;
    for (size_t i = 0; i < tmp.size(); ++i) {
        result.num.push_back((tmp[i] + carry) % 10 + '0');
        carry = (tmp[i] + carry) / 10;
    }
    result.minus = (minus != bn.minus);
    result.del_zero();
    return result;
}
BigNum BigNum::mul(const BigNum& bn) const {
    BigNum result;
    int mid = num.size() < bn.num.size() ? num.size()/2 : bn.num.size()/2;
    if (mid == 0) {
        return basic_mul(bn);
    }
    BigNum low1, high1;
    BigNum low2, high2;
    std::copy(num.begin(), num.begin() + mid, std::back_inserter(low1.num));
    std::copy(num.begin() + mid, num.end(), std::back_inserter(high1.num));
    std::copy(bn.num.begin(), bn.num.begin() + mid, std::back_inserter(low2.num));
    std::copy(bn.num.begin() + mid, bn.num.end(), std::back_inserter(high2.num));

    BigNum ab = high1.mul(high2);
    BigNum cd = low1.mul(low2);
    BigNum ad_bc = (low1 + high1).mul(low2 + high2) - ab - cd;
    result = (ab << (mid<<1)) + (ad_bc << mid) + cd;
    result.minus = (minus != bn.minus);
    return result;
}
BigNum& BigNum::operator*=(const BigNum& bn) {
    *this = mul(bn);
    del_zero();
    return *this;
}
BigNum BigNum::operator+(const BigNum& bn) const {
    BigNum tmp(*this);
    tmp += bn;
    return tmp;
}
BigNum BigNum::operator-(const BigNum& bn) const {
    BigNum tmp(*this);
    tmp -= bn;
    return tmp;
}
BigNum BigNum::operator*(const BigNum& bn) const {
    BigNum tmp(*this);
    tmp *= bn;
    return tmp;
}
std::istream& operator>>(std::istream& is, BigNum& bn) {
    is >> bn.num;
    bn.minus = false;
    std::reverse(bn.num.begin(), bn.num.end());
    while (bn.num.back() == '-') {
        bn.num.pop_back();
        bn.minus = !bn.minus;
    }
    while (bn.num.back() == '0') {
        bn.num.pop_back();
    }
    return is;
}
std::ostream& operator<<(std::ostream& os, const BigNum& bn) {
    if (bn.num.size() == 0)
        return os << "0";
    if (bn.minus)
        os << "-";
    std::string::const_reverse_iterator rit;
    for (rit = bn.num.rbegin(); rit != bn.num.rend() && *rit == '0'; ++rit)
        ; 
    for (; rit != bn.num.rend(); ++rit)
        os << *rit;
    return os;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

	// //std::random_device rd;
    // std::mt19937 gen(static_cast<unsigned long>(time(0)));
    // std::uniform_int_distribution<char> dis_ch('0', '9');
	// std::uniform_int_distribution<int> dis_break(0, 999); 
    // std::uniform_int_distribution<int> dis_minus(0, 1);
    // while (true) {
        
    //     std::string a, b;
    //     if (dis_minus(gen) == 1)
    //         a.push_back('-');
    //     for (int i = 0; i < 1000; ++i) {   
    //         a.push_back(dis_ch(gen));
    //         if (dis_break(gen) == 1)
    //             break;
    //     }
    //     if (dis_minus(gen) == 1)
    //         b.push_back('-');
    //     for (int i = 0; i < 1000; ++i) {
    //         b.push_back(dis_ch(gen));
    //         if (dis_break(gen) == 1)
    //             break;
    //     }
    //     std::istringstream iss(a + " " + b);
    //     BigNum A, B;
    //     iss >> A >> B;
    //     std::cout << " (" << A << ") (" << B << ")\n";
    //     std::cout << A + B << "\n";
    //     std::cout << A - B << "\n";
    //     std::cout << A * B << "\n";
    //     std::cout << A.basic_mul(B) << "\n";
    //     std::cout << "=====================================================================================================================================" << "\n";
    // }

    BigNum A, B;
    std::cin >> A >> B;
    std::cout << A + B << "\n";
    std::cout << A - B << "\n";
    std::cout << A.basic_mul(B) << "\n";
    //std::cout << A * B << "\n";

    return 0;
}