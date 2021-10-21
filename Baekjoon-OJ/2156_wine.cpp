#include <iostream>

int max(int* nums, int N) {
	int maximum = nums[0];
	for (int i = 1; i < N; ++i) {
		if (maximum < nums[i])
			maximum = nums[i];
	}
	return maximum;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int pre[3];
	int prepre;
	int preprepre;
	int n;
	int wine[10000];
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> wine[i];
	}
	
	preprepre = 0;
	prepre = wine[0];
	pre[0] = wine[1] + prepre;
	pre[1] = wine[1];
	pre[2] = wine[1]; 
	for (int i = 2; i < n; ++i) {
		int cur = wine[i];
		int tmp_prepre = prepre;
		int tmp_preprepre = preprepre;
		preprepre = prepre;
		prepre = max(pre, 3);
		pre[0] = cur + max(pre + 1, 2);
		pre[1] = cur + tmp_prepre;
		pre[2] = cur + tmp_preprepre;
	}
	
	int answer[] = {prepre, pre[0], pre[1], pre[2]};
	std::cout << max(answer, 4);
	
	return 0;
}

// me
// 1  1 0        pre[1]?pre[2]    --> pre[0]
// 1  0 1 [?     prepre           --> pre[1]
// 1  0 0 1 [?   preprepre        --> pre[2]
//pre[0]?pre[1]?pre[2] -> prepre

// 0 1 [?

// 100
// 1
// 1
// 100
// 100
// 1
// 100
// 1
// 100


// 100
// 1
// 100
// 1
// 1
// 100
