#include <iostream>
#include <string>
#include <list>

class Calculator {
private:
    int num;
    std::string history;
public:
    Calculator(int n = 0) : num(n%10000) {}
    Calculator(const Calculator& c) : num(c.num), history(c.history) {}
    ~Calculator() {}
    operator int() const {
        return num;
    }
    bool operator==(const Calculator c) const {
        return num == c.num;
    }
    void doubling() {
        num = num * 2 % 10000;
        history.push_back('D');
    }
    void decrement() {
        --num;
        if (num < 0)
            num = 9999;
        history.push_back('S');
    }
    void left() {
        num = num * 10 % 10000 + num / 1000;
        history.push_back('L');
    }
    void right() {
        num = num / 10 + num % 10 * 1000;
        history.push_back('R');
    }
    void find_inst_to(const Calculator& to, std::string& list) {
        typedef void (Calculator::* const inst_type)();
        static inst_type inst[4] = {&Calculator::doubling, &Calculator::decrement, &Calculator::left, &Calculator::right};
        
        std::list<Calculator> queue;
        Calculator cur;
        bool check[10000] = {};
        bool find_inst = false;

        queue.push_back(*this);
        while (!queue.empty() && !find_inst) {
            for (int i = 0; i < 4; ++i) {
                cur = queue.front();
                (cur.*inst[i])();
                if (!check[cur]) {
                    queue.push_back(cur);
                    if (cur == to) {
                        list = cur.history;
                        find_inst = true;
                        break;
                    } 
                    check[cur] = true;
                }
            }
            queue.pop_front();
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    int A, B;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        std::cin >> A >> B;
        Calculator from(A);
        std::string inst_list;
        from.find_inst_to(B, inst_list);
        std::cout << inst_list << "\n";
    }
    return 0;
}