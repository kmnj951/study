#include <iostream>

void spread_truth(int from, const bool graph[][51], int node_num, bool know[]) {
    for (int n = 1; n <= node_num; ++n) {
        if (graph[from][n] && !know[n]) {
            know[n] = true;
            spread_truth(n, graph, node_num, know);
        }
    }
}

int main() {
    int N;
    bool relation[51][51] = {{}};
    int truth[50] = {};
    int truth_num = 0;
    int party[50] = {}; // representative
    int party_num = 0;
    std::cin >> N >> party_num >> truth_num;
    for (int i = 0; i < truth_num; ++i)
        std::cin >> truth[i];

    for (int i = 0; i < party_num; ++i) {
        int party_mem;
        std::cin >> party_mem >> party[i];
        for (int j = 0; j < party_mem - 1; ++j) {
            int mem;
            std::cin >> mem;
            relation[party[i]][mem] = true;
            relation[mem][party[i]] = true;
        }
    }

    bool know_truth[51] = {};
    for (int i = 0; i < truth_num; ++i) {
        if (!know_truth[truth[i]]) {
            know_truth[truth[i]] = true;
            spread_truth(truth[i], relation, N, know_truth);
        }
    }

    int talk = 0;
    for (int i = 0; i < party_num; ++i) {
        if (!know_truth[party[i]])
            ++talk;
    }

    std::cout << talk;

    return 0;
}