#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string str1, str2;
    std::cin >> str1 >> str2;
    std::vector<std::vector<int>> LCS(str1.size() + 1);

    for (size_t i = 0; i < LCS.size(); ++i) {
        LCS[i].resize(str2.size() + 1);
    }

    for (size_t i = 1; i < LCS.size(); ++i) {
        for (size_t j = 1; j < LCS[i].size(); ++j) {
            if (str1[i-1] == str2[j-1])
                LCS[i][j] = LCS[i-1][j-1] + 1;
            else
                LCS[i][j] = LCS[i][j-1] > LCS[i-1][j] ? LCS[i][j-1] : LCS[i-1][j];
        }
    }

    std::string subsq(LCS.back().back(), '-');
    size_t sub_i = LCS.back().back() - 1; 
    for (size_t i = LCS.size()-1, j = LCS[i].size()-1; sub_i < subsq.size();) {
        if (LCS[i][j] == LCS[i][j-1]) 
            --j;
        else if (LCS[i][j] == LCS[i-1][j])
            --i;
        else {
            subsq[sub_i--] = str1[i-1];
            --i, --j;
        }
    }

    std::cout << subsq;

    return 0;
}