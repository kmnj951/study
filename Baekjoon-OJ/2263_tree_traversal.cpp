#include <iostream>
#include <vector>

using std::vector;

void make_preorder(size_t size, const vector<size_t>& order, size_t in_beg, 
                   const vector<int>& postorder, size_t post_rbeg, vector<int>& r_preorder) {
    size_t p = order[postorder[post_rbeg]];
    size_t size1 = p - in_beg;
    size_t size2 = size - size1 - 1;
    if (size2 != 0)
        make_preorder(size2, order, p + 1, postorder, post_rbeg - 1, r_preorder);
    if (size1 != 0)
        make_preorder(size1, order, in_beg, postorder, post_rbeg - size2 - 1, r_preorder);
    r_preorder.push_back(postorder[post_rbeg]);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    size_t inorder;
    vector<size_t> order(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> inorder;
        order[inorder] = i;
    }
        
    vector<int> postorder(n);
    for (int i = 0; i < n; ++i)
        std::cin >> postorder[i];

    vector<int> r_preorder;
    make_preorder(n, order, 0, postorder, n - 1, r_preorder);
    for (auto it = r_preorder.rbegin(); it != r_preorder.rend(); ++it)
        std::cout << *it << " ";

    return 0;
}

// 10
// 1 2 3 4 5 6 7 8 9 10
// 1 3 5 4 2 8 10 9 7 6
// 6 2 1 4 3 5 7 9 8 10