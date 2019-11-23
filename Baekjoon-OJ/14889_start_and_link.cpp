#include <iostream>

#define abs(a) (((a) > 0) ? (a) : -(a))

using namespace std;

int main(void) {
	int N;
	int S[20][20] = {0};
	
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> S[i][j];
			
	bool* member = new bool[N];
	int diff_stats;
	int min_diff_stats = ((unsigned)-1>>1);
	long long repeat = 1;
	int i;
	for (i = N; i > N/2; --i)
		repeat *= i; 
	for (; i > 0; --i)
		repeat /= i;	
	repeat /= 2;
	
	for (i = 0; i < N/2; ++i)
		member[i] = true;
	for (; i < N; ++i)
		member[i] = false;
		
	for (i = 0; i < repeat; ++i) {
		int select[20][20] = {{0}};
		
		int m;
		for (m = 0; m < N; ++m) {
			if (member[m]) {
				for (int c = 0; c < m; ++c)
					if (member[c]) {
						select[m][c] = 1;
						select[c][m] = 1;
					}
			}
			else {
				for (int c = 0; c < m; ++c)
					if (!member[c]) {
						select[m][c] = -1;
						select[c][m] = -1;
					}
			}	
		}
		
		diff_stats = 0;
		for (int r = 0; r < N; ++r)
			for (int c = 0; c < N; ++c)
				diff_stats += S[r][c] * select[r][c];

		diff_stats = abs(diff_stats);
		min_diff_stats = diff_stats < min_diff_stats ? diff_stats : min_diff_stats;
		
		m = N-1;
		while (member[m]) {
			--m;
		}
		while (!member[m]) {
			--m;
		}
		member[m++] = false;
		member[m++] = true;
		for (int j = m; j < N; ++j)
			if (member[j]) {
				member[j] = false;
				member[m++] = true;
			}
	}

	cout << min_diff_stats;
	
	return 0;
}
