#include <iostream>
#include <vector>
#include <forward_list>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<std::forward_list<int>> tree(N + 1);

    int n1, n2;
    while (std::cin >> n1 >> n2) {
        tree[n1].push_front(n2);
        tree[n2].push_front(n1);
    }

    std::vector<int> stack;
    std::vector<int> visit(N + 1);
    int node;
    stack.push_back(1);
    visit[1] = 1;
    while (!stack.empty()) {
        node = stack.back();
        stack.pop_back();
        auto pre_it = tree[node].before_begin();
        for (auto it = tree[node].begin(); it != tree[node].end();) {
            if (visit[*it] == 0) {
                visit[*it] = 1;
                stack.push_back(*it);
                it = tree[node].erase_after(pre_it);
            }
            else {
                ++pre_it;
                ++it;
            }
        }
    }
    for (size_t i = 2; i < tree.size(); ++i) {
        std::cout << tree[i].front() << "\n";
    }
    
    return 0;
}

/******************************
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<std::vector<int>> tree(N + 1);

    int n1, n2;
    while (std::cin >> n1 >> n2) {
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    std::vector<int> stack;
    std::vector<int> visit(N + 1);
    std::vector<int> parent(N + 1);
    int node;
    stack.push_back(1);
    visit[1] = 1;
    while (!stack.empty()) {
        node = stack.back();
        stack.pop_back();
        for (auto it = tree[node].begin(); it != tree[node].end(); ++it) {
            if (visit[*it] == 0) {
                visit[*it] = 1;
                stack.push_back(*it);
            }
            else {
                parent[node] = *it;
            }
        }
    }
    for (size_t i = 2; i < parent.size(); ++i) {
        std::cout << parent[i] << "\n";
    }
    
    return 0;
}
***************************/