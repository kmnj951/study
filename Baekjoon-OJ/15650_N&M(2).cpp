#include <iostream>
#include <vector>

using namespace std;

void print_comb(int N, vector<int>& combination, int remain) {
	if (remain <= 0) {
		for (int n : combination) 
			cout << n << " ";
		cout << "\n";
		return;
	}
	int start;
	if (combination.size() < 1) 
		start = 1;
	else
		start = combination[combination.size()-1] + 1;
	for (int n = start; n <= N; ++n) {
		combination.push_back(n);
		print_comb(N, combination, remain-1);
		combination.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> combination;
	print_comb(N, combination, M);
	return 0;
}
