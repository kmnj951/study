#include <iostream>
#include <vector>
#include <cassert>

class MinMaxHeap {
private:
	std::vector<int> heap = {0};
private:
	size_t find_min_child(size_t cur) const;
	size_t find_min_grandchild(size_t cur) const;
	size_t find_max_child(size_t cur) const;
	size_t find_max_grandchild(size_t cur) const;
	bool cmp_up_min(size_t cur, size_t start_cmp);
	bool cmp_up_max(size_t cur, size_t start_cmp);
public:
	void op(char inst, int num);
	void insert(int e);
	void delete_min();
	void delete_max();
	int min() const;
	int max() const;
	bool empty() const;
	void print(std::string) const;
};

size_t MinMaxHeap::find_min_child(size_t cur) const {
	size_t child[] = {cur<<1, (cur<<1) + 1};
	size_t min_i = cur;
	for (int i = 0; i < 2 && child[i] < heap.size(); ++i)
		min_i = heap[child[i]] < heap[min_i] ? child[i] : min_i;
	return min_i;
}

size_t MinMaxHeap::find_min_grandchild(size_t cur) const {
	size_t grandchild[] = {cur<<2, (cur<<2) + 1, (cur<<2) + 2, (cur<<2) + 3};
	size_t min_i = cur;
	for (int i = 0; i < 4 && grandchild[i] < heap.size(); ++i)
		min_i = heap[grandchild[i]] < heap[min_i] ? grandchild[i] : min_i;
	return min_i;
}

size_t MinMaxHeap::find_max_child(size_t cur) const {
	size_t child[] = {cur<<1, (cur<<1) + 1};
	size_t max_i = cur;
	for (int i = 0; i < 2 && child[i] < heap.size(); ++i)
		max_i = heap[child[i]] > heap[max_i] ? child[i] : max_i;
	return max_i;
}

size_t MinMaxHeap::find_max_grandchild(size_t cur) const {
	size_t grandchild[] = {cur<<2, (cur<<2) + 1, (cur<<2) + 2, (cur<<2) + 3};
	size_t max_i = cur;
	for (int i = 0; i < 4 && grandchild[i] < heap.size(); ++i)
		max_i = heap[grandchild[i]] > heap[max_i] ? grandchild[i] : max_i;
	return max_i;
}

bool MinMaxHeap::cmp_up_min(size_t cur, size_t start_cmp) {
	bool ret = false;
	size_t cmp = start_cmp;
	while (cmp >= 1 && heap[cur] < heap[cmp]) {
		std::swap(heap[cur], heap[cmp]);
		cur = cmp;
		cmp = cmp >> 2;
		ret = true;
	}
	return ret;
}

bool MinMaxHeap::cmp_up_max(size_t cur, size_t start_cmp) {
	bool ret = false;
	size_t cmp = start_cmp;
	while (cmp >= 1 && heap[cur] > heap[cmp]) {
		std::swap(heap[cur], heap[cmp]);
		cur = cmp;
		cmp = cmp >> 2;
		ret = true;
	}
	return ret;
}

void MinMaxHeap::op(char inst, int num) {
	if (inst == 'I')
		insert(num);
	else if (inst == 'D' && !empty()) {
		if (num == -1) 
			delete_min();
		else 
			delete_max();
	}
}

void MinMaxHeap::insert(int e) {
	size_t cur = heap.size();
	heap.push_back(e);
	int l = 0;
	for (size_t c = cur; c > 0; ++l) {
		c >>= 1;
	}
	if (l % 2 == 0) {
		if(!cmp_up_max(cur, cur>>2))
			cmp_up_min(cur, cur>>1);
	}
	else {
		if (!cmp_up_min(cur, cur>>2))
			cmp_up_max(cur, cur>>1);
	}	
}

void MinMaxHeap::delete_min() {
	assert(!empty());
	size_t cur = 1;
	heap[cur] = heap[heap.size()-1];
	heap.pop_back();
	size_t cur_swap;	
	while ((cur_swap = find_min_grandchild(cur)) != cur) {
		std::swap(heap[cur], heap[cur_swap]);
		cur = cur_swap;
	}	// ~ loc: min
	if (cur << 2 >= heap.size()) {
		if (cur << 1 >= heap.size())
			cmp_up_max(cur_swap, cur_swap>>1);
		else if ((cur_swap = find_min_child(cur)) != cur) {
			std::swap(heap[cur], heap[cur_swap]);
			cmp_up_max(cur_swap, cur_swap>>2);
		}
	}
}

void MinMaxHeap::delete_max() {
	assert(!empty());
	if (heap.size() <= 3) {
		heap.pop_back();
		return;
	}
	size_t cur = heap[2] > heap[3] ? 2 : 3;
	heap[cur] = heap[heap.size()-1];
	heap.pop_back();
	size_t cur_swap;
	while ((cur_swap = find_max_grandchild(cur)) != cur) {
		std::swap(heap[cur], heap[cur_swap]);
		cur = cur_swap;
	}	// ~ loc: max
	if (cur << 2 >= heap.size()) {
		if (cur << 1 >= heap.size())
			cmp_up_min(cur_swap, cur_swap>>1);
		else if ((cur_swap = find_max_child(cur)) != cur) {
			std::swap(heap[cur], heap[cur_swap]);
			cmp_up_min(cur_swap, cur_swap>>2);
		}
	}
}

int MinMaxHeap::min() const {
	return heap[1];
}

int MinMaxHeap::max() const {
	if (heap.size() == 2)
		return heap[1];
	if (heap.size() > 3 && heap[2] < heap[3])
		return heap[3];
	return heap[2];
}

bool MinMaxHeap::empty() const {
	return heap.size() == 1;
}

void MinMaxHeap::print(std::string str = "") const {
	std::cout << str;
	for (size_t i = 1; i < heap.size(); i <<= 1) {
		for (size_t j = i; j < i<<1 && j < heap.size(); ++j) {
			std::cout << heap[j] << " ";
		}
		std::cout << "\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		MinMaxHeap Q;
		int K;
		std::cin >> K;
		for (int k = 0; k < K; ++k) {
			char inst;
			int num;
			std::cin >> inst >> num;
			Q.op(inst, num);
		}
		if (Q.empty())
			std::cout << "EMPTY\n";
		else
			std::cout << Q.max() << " " << Q.min() << "\n";
	}
	return 0;
}

/**********
void op(std::multiset<int>& Q, char inst, int num) {
	if (inst == 'I')
		Q.insert(num);
	else if (inst == 'D' && !Q.empty())
		if (num == -1) 
			Q.erase(Q.begin());
		else 
			Q.erase(--Q.end());
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::multiset<int> Q;
		int K;
		std::cin >> K;
		for (int k = 0; k < K; ++k) {
			char inst;
			int num;
			std::cin >> inst >> num;
			op(Q, inst, num);
		}
		if (Q.empty())
			std::cout << "EMPTY\n";
		else
			std::cout << *Q.rbegin() << " " << *Q.begin() << "\n";
	}
	return 0;
}
*************/
