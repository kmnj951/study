#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	getline(cin, str);
	istringstream ss(str);
	//ss >> std::noskipws;
	int count = 0;
	while ( ss >> str ) {
		count++;
	}
	cout << count;
	return 0;
}
