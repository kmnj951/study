#include <iostream>

using namespace std;

int main(void) {
	int A, B, V;
	cin >> A >> B >> V;
	V -= A;
	int day = V/(A-B) + 1;
	if( V%(A-B) != 0)
		day++;
	cout << day;
	return 0;
}
