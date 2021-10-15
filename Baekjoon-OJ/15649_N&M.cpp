#include <iostream>
#include <vector>

using namespace std;

void print_perm(int N, vector<int>& permutation, bool* candidate, int remain) {
	if (remain <= 0) {
		for (int n : permutation) 
			cout << n << " ";
		cout << "\n";
		return;
	}
	for (int n = 1; n <= N; ++n) {
		if (candidate[n]) {
			permutation.push_back(n);
			candidate[n] = false;
			print_perm(N, permutation, candidate, remain-1);
			permutation.pop_back();
			candidate[n] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	bool candidate[9] = {false};
	for (int i = 1; i <= N; ++i) {
		candidate[i] = true;
	}
	vector<int> permutation;
	print_perm(N, permutation, candidate, M);
	return 0;
}
