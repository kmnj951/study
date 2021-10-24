#include <iostream>
#include <vector>

#define max(a, b) (a) > (b) ? (a) : (b)

struct item {
	int weight;
	int value;
//public:
//	item(int w = 0, int v = 0) : weight(w), value(v) {}
//	item operator+(const item& i) const& {
//		return item(weight + i.weight, value + i.value);
//	}
//	bool calculated() {
//		return weight + value > 0;
//	}
};

int pack(const std::vector<item>& weight_value, std::vector<std::vector<int> >& in_bag, int num, int weight) {
	if (num == -1 || weight == 0) {
		return 0;
	}
	if (in_bag[num][weight] == -1) {
		int v1 = 0, v2; 
	
		if (weight_value[num].weight <= weight) {
			v1 = pack(weight_value, in_bag, num - 1, weight - weight_value[num].weight) + weight_value[num].value;
		}
		v2 = pack(weight_value, in_bag, num - 1, weight);
		in_bag[num][weight] = max(v1, v2);
	}
	return in_bag[num][weight];
}

int main() {
//	std::ios::sync_with_stdio(false);	//????? why?? no diff
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
	
	int N, K;
	std::vector<item> weight_value;
	std::vector<std::vector<int> > in_bag;
	
	std::cin >> N >> K;
	weight_value.resize(N);
	in_bag.resize(N);
	for (auto& num : in_bag) {
		num.resize(100001, -1);
	}
	for (auto& wv : weight_value) {
		std::cin >> wv.weight >> wv.value;
	}
	
	std::cout << pack(weight_value, in_bag, N-1, K);
	
	return 0;
}

//      bag
//6 13  6 13 0 0
//4 8   4 8  6 13 
//3 6   7 14 6 13
//5 12  7: 2:  5: 0:
//2 22    7:    5: 
