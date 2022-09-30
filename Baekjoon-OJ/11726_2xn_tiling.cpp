#include <iostream>

int rectangle_num(int width) {
	static int num[1001] = {-1, 1, 2};
	if (num[width] == 0)
		num[width] = (rectangle_num(width - 2) + rectangle_num(width - 1)) % 10007;
	return num[width];
}

int main() {
	int n;
	std::cin >> n;
	std::cout << rectangle_num(n);
	return 0;
}
