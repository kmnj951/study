#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int* score[n];
	for(int i=0; i<n; ++i) {
		int case_num;
		cin >> case_num;
		score[i] = new int[case_num+1];
		score[i][0] = case_num;
		for(int j=1; j<=case_num; ++j) {
			cin >> score[i][j];
		}
	}
	
	double percent[n] = {0};
	for(int i=0; i<n; ++i) {
		double avg = 0;
		int case_num = score[i][0];
		for(int j=1; j<=case_num; ++j) {
			avg += (double)score[i][j];
		}
		avg /= (double)case_num;
		
		for(int j=1; j<=case_num; ++j) {
			if( avg < (double)score[i][j] )
				percent[i] += 100;
		}
		percent[i] /= case_num;
	}
	
	cout << fixed;
	cout.precision(3);
	for(int i=0; i<n; ++i) {
		cout << percent[i] << '%' << '\n';
	}
	
	return 0;
}
