#include <iostream>
//#include <queue>

class min_heap {
private:
	int heap[100001] = {0};
	int size = 1;
	void print(std::string str = "") {
		std::cout << str;
		for (int i = 1; i < size; i *= 2) {
			for (int j = i; j < i * 2 && j < size; ++j) {
				std::cout << heap[j] << " ";
			}
			std::cout << "\n";
		}
	}
public:
	void push(int e) {
		int cur = size++;
		heap[cur] = e;
		while(cur > 1 && heap[cur] < heap[cur/2]) {
			int tmp = heap[cur];
			heap[cur] = heap[cur/2];
			heap[cur/2] = tmp;
			cur /= 2;
		}
		//print("push\n");
	}
	void pop() {
		int cur = 1;
		heap[1] = heap[--size];
		while (cur * 2 < size) {
			int child[2] = {cur * 2, cur * 2 + 1};
			int i;
			for (i = 0; i < 2 && child[i] < size && heap[cur] <= heap[child[i]]; ++i)
				;
			if (i < 2 && child[i] < size) {
				if (i == 0 && child[1] < size && heap[child[0]] > heap[child[1]]) {
					i = 1;
				}
				int tmp = heap[cur];
				heap[cur] = heap[child[i]];
				heap[child[i]] = tmp;
				cur = child[i];
			}
			else
				break;
		}
		//print("pop\n");
	}
	int top() {
		return heap[1];
	}
	bool empty() {
		return size == 1;
	}
};


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	//std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
	min_heap heap;
	int N;
	std::cin >> N;
	
	int x;
	for (int i = 0; i < N; ++i) {
		std::cin >> x;
		if (x == 0) {
			if (!heap.empty()) {
				x = heap.top();
				heap.pop();
				std::cout << x << "\n";
			}
			else
				std::cout << "0\n";
		}
		else
			heap.push(x);
	}
	
	return 0;
}
