#include <iostream>
#include <string>

using namespace std;

int main() {
	string A, B, sum;
	string tmp;
	cin >> A >> B;
	if (A.size() > B.size()) {
		sum.resize(A.size());
		tmp.resize(A.size() - B.size(), '0');
		tmp += B;
		B = tmp;
	}
	else if (A.size() < B.size()) {
		sum.resize(B.size());
		tmp.resize(B.size() - A.size(), '0');
		tmp += A;
		A = tmp;
	}
	else {
		sum.resize(B.size());
	}
	
	int C = 0;
	for (int i = sum.size()-1; i >= 0; --i) {
		int s = A[i] + B[i] - '0' - '0' + C;
		sum[i] = s%10 + '0';
		C = s/10;
	}
	
	if (C > 0)
		sum = "1" + sum;
		
	cout << sum; 
	return 0;
} 
