#include <iostream>

using namespace std;

int main(void) {
	int X;
	int fraction[2];
	int sum;
	
	cin >> X;
	for (sum = 1; sum * (sum - 1) / 2 < X; ++sum)
		;
	int seq = X - (sum - 1) * (sum - 2) / 2;
	if (sum % 2 == 1) {		
		fraction[0] = seq;
		fraction[1] = sum - seq;
	}
	else {
		fraction[0] = sum - seq;
		fraction[1] = seq;
	}
	
	cout << fraction[0] << "/" << fraction[1];
	return 0;
}
