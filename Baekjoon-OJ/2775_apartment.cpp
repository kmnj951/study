#include <iostream>

using namespace std;

//int combination(int n, int k) {
//	int result = 1;
//	for (int i = n; i > n-k; --i) {
//		result *= i;	// 너무 큰 수.. 
//	}
//	for (int i = k; i > 0; --i) {
//		result /= i;
//	}
//	return result;
//}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int count;
	cin >> count;
//	for (int i = 0; i < count; ++i) {
//		int k, n;
//		cin >> k >> n;
//		cout << combination(n+k, k+1) << "\n";
//	}
	
	int apart[15][15] = {{0}};
	for (int i = 1; i < 15; ++i) {
		apart[0][i] = i;
		apart[i][1] = 1;
	}
	for (int i = 1; i < 15; ++i)
		for (int j = 2; j < 15; ++j)
			apart[i][j] = apart[i-1][j] + apart[i][j-1];
		
	for (int i = 0; i < count; ++i) {
		int k, n;
		cin >> k >> n;
		cout << apart[k][n] << "\n";
	}

	return 0;
}
