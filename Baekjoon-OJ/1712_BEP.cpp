#include <iostream>

using namespace std;

int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
	int A, B, C;
	int q;
	cin >> A >> B >> C;
	if (C > B)
		q = A / (C - B) + 1;
	else
		q = -1;
	cout << q;
	return 0;
}
