#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int x, y;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> x >> y;
		int diff = y - x;
		int count;
		int n;
		for (n = 1; n < 46341 && diff > n * n; ++n) 
			;
		count = 2 * n - 1;
		if (diff <= n * (n-1))
			--count;
		cout << count << "\n";
	
	}
	return 0;
}


// 1 2 1	[[4]]
// 1 2 1 1	5
// 1 2 2 1	[6]
// 1 2 2 1 1 7
// 1 2 2 2 1	8	
// 1 2 3 2 1	[[9]]
// 1 2 3 2 1 1
// 1 2 3 2 2 1
// 1 2 3 3 2 1	[12]
// 
// 1 2 3 4 3 2 1  - [[16]]
// 1 4 9 16 25 왜이러지 -- n(n-1)/2 + (n-1)(n-2)/2 = 1/2(2n^2 - 4n + 2) = (n-1)^2
// <=1 , <=(4-2), <=4 , <=(9-3), <=9 .... 
// <= 1^2, <=1*2, <=2^2, <= 2*3, ..
// < 46,340^ < 46,341^2 - 46,341 < 2^31 < 46,341^2
