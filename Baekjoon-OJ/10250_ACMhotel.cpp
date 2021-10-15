#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int count;
	cin >> count;
	for (int i = 0; i < count; ++i) {
		int H, W, N;
		int room;
		cin >> H >> W >> N;
		room = (N % H) * 100 + (N - 1) / H + 1;
		if (room < 100)
			room += H * 100;
		cout << room << "\n";
	}
	return 0;
}
