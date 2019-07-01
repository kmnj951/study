#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[2];
	for(int i=0; i<n; ++i) {
		cin >> a[0];
		cin >> a[1];
		cout << a[0]+a[1] << '\n';
	}
	return 0;
}
