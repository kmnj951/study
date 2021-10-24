#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		int count = 0;
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		int n;
		std::cin >> n;
		for (int p = 0; p < n; ++p) {
			int xc, yc, r;
			std::cin >> xc >> yc >> r;
			if ((r * r > (x1 - xc) * (x1 - xc) + (y1 - yc) * (y1 - yc) ||
					r * r > (x2 - xc) * (x2 - xc) + (y2 - yc) * (y2 - yc)) &&
					!(r * r > (x1 - xc) * (x1 - xc) + (y1 - yc) * (y1 - yc) &&
					r * r > (x2 - xc) * (x2 - xc) + (y2 - yc) * (y2 - yc)) )
				++count;
		}
		std::cout << count << "\n";
	}
	return 0;
}
