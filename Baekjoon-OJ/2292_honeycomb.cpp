#include <iostream>

using namespace std;

int main(void) {
	int N;
	int value = 1;
	int level = 1;
	cin >> N;
	for (level = 1; value <= N; ++level)
		value = 3 * level * (level - 1) + 2;
	cout << level - 1;
	
	
	//2 8 20 38 62
	
	return 0;
}
