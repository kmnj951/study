#include <iostream>

using namespace std;

int main(void) {
	int kg;
	cin >> kg;
	int bag3 = 0, bag5 = 0;
	while( kg > 0 && kg%5 != 0 ) {
		kg -= 3;
		bag3++;
	}
	if (kg<0) {
		cout << -1;
		return 0;
	}
	bag5 = kg/5;
	cout << bag3+bag5;
	return 0;
}
