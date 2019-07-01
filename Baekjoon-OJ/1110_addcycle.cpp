#include<iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int cycle = 0;
	
	const int N = n;
	do {
		int left = 0, right = n%10;
		while((n/=10) > 0) {
			left = n;
		}
		n = right*10 + (left+right)%10;
		cycle++;
	} while( N != n );
	
	cout << cycle;
	
	return 0;
}
