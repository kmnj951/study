#include <iostream>
#include <vector>
#include <string>

std::string preorder(const std::vector<std::pair<char,char>>& tree, char node) {
    std::string result;
    std::vector<char> stack;
    stack.push_back(node);
    while (!stack.empty()) {
        char n = stack.back();
        stack.pop_back();
        if (n != '.') {
            result += n;
            stack.push_back(tree[n - 'A'].second);
            stack.push_back(tree[n - 'A'].first);
        }
    }
    return result;
}

std::string inorder(const std::vector<std::pair<char,char>>& tree, char node) {
    std::string result;
    if (node != '.') {
        result += inorder(tree, tree[node - 'A'].first);
        result += node;
        result += inorder(tree, tree[node - 'A'].second);
    }
    return result;
}

std::string postorder(const std::vector<std::pair<char,char>>& tree, char node) {
    std::string result;
    if (node != '.') {
        result += postorder(tree, tree[node - 'A'].first);
        result += postorder(tree, tree[node - 'A'].second);
        result += node;
    }
    return result;
}

int main() {
    std::vector<std::pair<char,char>> tree;
    int N;
    std::cin >> N;
    tree.resize(N);
    for (int n = 0; n < N; ++n) {
        char p, c1, c2;
        std::cin >> p >> c1 >> c2;
        tree[p-'A'].first = c1;
        tree[p-'A'].second = c2;
    }
    std::cout << preorder(tree, 'A') << "\n";
    std::cout << inorder(tree, 'A') << "\n";
    std::cout << postorder(tree, 'A');
    return 0;
}