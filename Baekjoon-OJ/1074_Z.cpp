#include <iostream>

/*void fill(std::vector<std::vector<int>>& arr, int rb, int re, int cb, int ce) {
	static int num = 0;
	if (re - rb <= 1) {
		arr[rb][cb] = num++;
		return;
	}

	int rm = (rb + re) / 2;
	int cm = (cb + ce) / 2;
	fill(arr, rb, rm, cb, cm);
	fill(arr, rb, rm, cm, ce);
	fill(arr, rm, re, cb, cm);
	fill(arr, rm, re, cm, ce);
}*/

int num(int r, int c, int N) {
	int number = 0;
	while(N > 1) {
		int n = N >> 1;
		if (r < n && c >= n) {
			number += n * n;
			c -= n;
		}
		else if (r >= n && c < n)  {
			number += n * n * 2;
			r -= n;
		}
		else if (r >= n && c >= n) {
			number += n * n * 3;
			r -= n;
			c -= n;
		}
		N = n;
	}
	return number;
}

int main() {
	int N, r, c;
	std::cin >> N >> r >> c;
	
	int size = 1 << N;
	std::cout << num(r, c, size);
	
	return 0;
}
