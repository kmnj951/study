#include <iostream>
#include <random>

int main() {
	int T;
	int P, M, F, C;
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> T;
	/*
	T = 20000;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> disP(1, 50000);
	std::uniform_int_distribution<int> disM(0, 1000000);
	std::uniform_int_distribution<int> disF(2, 1000);
	*/
	for (int t = 0; t < T; ++t) {
		std::cin >> P >> M >> F >> C;	
		/*
		P = disP(gen);
		M = disM(gen);
		F = disF(gen);
		std::uniform_int_distribution<int> disC(1, F-1);
		C = disC(gen);
		*/
		
		int coupon = M / P * C;	
		int chicken = coupon / F;

		int use = F - C;
		int remain = coupon % use;
		int reg_chicken = coupon / use - (F - remain) / use;
		if (coupon == 0)
			reg_chicken = 0;
		else if ((F - remain) % use == 0)
			++reg_chicken;
		std::cout << reg_chicken - chicken << "\n";	
		
		/*
		{
			coupon = coupon % F + chicken * C;
			int add_chicken = 0;
			int use = F - C;
			while (coupon >= F) {
				coupon -= use;
				++add_chicken;
			}
			if (reg_chicken - chicken != add_chicken) {
				std::cout << P << " " << M << " " << F << " " << C << std::endl;
				std::cout << add_chicken << "\n";
				std::cout << reg_chicken - chicken << "\n";
			}		
		}
		*/
	}
	return 0;
}

// regular_chicken = coupon // (F-C) - (remain + (F-C)*n) // (F-C) + 1
// = coupon // (F-C) - n + 1 (... remain < (F-C))

// remain + (F-C)*n >= F
// n >= (F-remain)/(F-C) (n:√÷º“)
// -n <= -(F-ramain)/(F-C)

// regular_chicken = coupon // (F-C) - (F-remain)//(F-C) + 1 - a
// (if (F-remain)%(F-C) > 0, a == 1)			--- ((ans1))

// coupon = (F-C) * x + remainder
// regular_chicken <= coupon // (F-C) - (F - coupon+(F-C)*x)/(F-C) + 1
// = x - (F-coupon)/(F-C) - x + 1
// = (coupon-F)/(F-C) + 1

// regular_chicken <= (coupon-F) / (F-C) + 1
// regular_chicken = (coupon-F) // (F-C) + 1	--- ((ans2))**
