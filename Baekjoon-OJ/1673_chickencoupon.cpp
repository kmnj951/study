#include <iostream>

int main() {
	int n, k;
	int coupon;
	int chicken;
	int stamp;
	
	std::cin >> n >> k;
	while (!std::cin.fail()) {
		chicken = 0;
		stamp = 0;
		coupon = n;
		while (coupon > 0) {	
			chicken += coupon;
			stamp += coupon;
			coupon = stamp/k;
			stamp %= k;
		}
		std::cout << chicken << std::endl;
		std::cin >> n >> k;
	}
	
	return 0;
}

