#include <iostream>
#include <vector>
#include <string>

enum Op {
    PLUS, MINUS, MUL, DIV, LPAREN, RPAREN
};
constexpr int precedence[6] = {1, 1, 2, 2, -1, 0};
constexpr char symbol[6] = {'+', '-', '*', '/', '(', ')'};

int main() {
    std::string postfix;
    std::vector<Op> op_stack;
    std::string expression;
    std::cin >> expression;

    for (char ch : expression) {     
        if (ch >= 'A' && ch <= 'Z') {
            postfix.push_back(ch);
        }
        else {
            Op op;
            if (ch == '+')
                op = PLUS;
            else if (ch == '-')
                op = MINUS;
            else if (ch == '*')
                op = MUL;
            else if (ch == '/')
                op = DIV;
            else if (ch == '(')
                op = LPAREN;
            else if (ch == ')')
                op = RPAREN;
            else
                continue;
            
            if (op != LPAREN) {
                while (!op_stack.empty() && precedence[op_stack.back()] >= precedence[op]) {
                    postfix.push_back(symbol[op_stack.back()]);
                    op_stack.pop_back();
                }
            }
            if (op == RPAREN)
                op_stack.pop_back();
            else
                op_stack.push_back(op);
        }
    }
    while (!op_stack.empty()) {
        postfix.push_back(symbol[op_stack.back()]);
        op_stack.pop_back();
    }
    std::cout << postfix;

    return 0;
}