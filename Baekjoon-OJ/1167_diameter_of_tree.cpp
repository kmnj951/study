#include <iostream>
#include <vector>
#include <queue>

std::pair<int,int> max_length(const std::vector<std::vector<std::pair<int,int>>>& tree, int v, int pre_len) {
    // In every node, calculate max in every direction
    static bool visit[100001] = {};
    std::priority_queue<int> len;
    int max_candidate = 0;  // not passing root
    len.push(pre_len);  // root ~ v
    visit[v] = true;
    for (const auto& cv : tree[v]) {
        if (!visit[cv.first]) {
            auto [l, c] = max_length(tree, cv.first, pre_len + cv.second);
            len.push(l - pre_len);
            max_candidate = c > max_candidate ? c : max_candidate;
        }
    }
    visit[v] = false;
    int max_len = len.top();
    len.pop();
    if (len.empty()) 
        return {max_len, max_candidate};
        
    if (max_len != pre_len && len.top() != pre_len) {   /* if max_len does not include root. (e.g. /\) */
        max_candidate = max_len + len.top() > max_candidate ? max_len + len.top() : max_candidate;
        max_len += pre_len;
    }
    else
        max_len += len.top();
    return {max_len, max_candidate};
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int V;
    std::cin >> V;
    std::vector<std::vector<std::pair<int,int>>> tree(V + 1);
    for (int i = 0; i < V; ++i) {
        int v, cv, dist;
        std::cin >> v;
        while (std::cin >> cv && cv != -1) {
            std::cin >> dist;
            tree[v].emplace_back(cv, dist);
        }
    }
    int v = 1;
    auto [max, max_candidate] = max_length(tree, v, 0);
    max = max_candidate > max ? max_candidate : max;
    std::cout << max;
    return 0;
}

// 10
// 1 2 1 -1
// 2 1 1 3 1 8 1 -1
// 3 2 1 4 1 5 1 -1
// 4 3 1 -1
// 5 3 1 6 1 -1
// 6 5 1 -1
// 7 8 1 -1
// 8 2 1 7 1 9 1 -1
// 9 8 1 10 1-1
// 10 9 1 -1
// ----6 (6 5 3 2 8 9 10)
//                 1
//             2
//     3                   8
// 4       5           7       9
//             6                   10

/*****************************************
int max_length(const std::vector<std::vector<std::pair<int,int>>>& graph, int start_v, int& end_v) {
    // DFS for each leaf : timeout --> choose leaves which just need DFS 2 times
    bool visit[100001] = {};
    int max = 0;
    std::vector<std::pair<int,int>> stack;
    visit[start_v] = true;
    for (const auto& v : graph[start_v]) {
        stack.push_back(v);
    }
    std::pair<int,int> v;
    while (!stack.empty()) {
        v = stack.back();
        stack.pop_back();
        visit[v.first] = true;
        bool leaf = true;
        for (auto cv : graph[v.first]) {
            if (!visit[cv.first]) {
                cv.second += v.second; 
                stack.push_back(cv);
                leaf = false;
            }
        }
        if (leaf && v.second > max) {
            max = v.second;
            end_v = v.first;
        }
            
    }
    return max;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int V;
    std::cin >> V;
    std::vector<std::vector<std::pair<int,int>>> tree(V + 1);
    std::vector<int> leaf;
    for (int i = 0; i < V; ++i) {
        int v, cv, dist;
        int count = 0;
        std::cin >> v;
        while (std::cin >> cv && cv != -1) {
            std::cin >> dist;
            tree[v].emplace_back(cv, dist);
            ++count;
        }
        if (count == 1) {
            leaf.push_back(v);
        }
    }
    
    int max_leaf = 0;
    int v = 1;
    max_length(tree, v, max_leaf);
    int max = max_length(tree, max_leaf, v);
    std::cout << max;

    return 0;
}
*******************************************/