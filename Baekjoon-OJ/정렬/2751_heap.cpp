#include <iostream>
#include <iomanip>

using namespace std;

template <typename node>
class min_heap {
private:
	node *tree;
	int size;
	int max_size;
private:
	static void swap(node &n1, node &n2);
	static void copy_tree(node *src, node *dst, int size);
public:
	min_heap();
	~min_heap();
	void push(node n);
	void pop();
	node front();
	bool empty();
	void print(const int digit);
};

template <typename node>
void min_heap<node>::swap(node &n1, node &n2) {
	node tmp = n1;
	n1 = n2;
	n2 = tmp;
}

template <typename node>
void min_heap<node>::copy_tree(node *src, node *dst, int size) {
	for (int i = 1; i <= size; ++i)
		dst[i] = src[i];
}

template <typename node>
min_heap<node>::min_heap() : tree(new node[2]), size(0), max_size(1) {}

template <typename node>
min_heap<node>::~min_heap() {
	delete[] tree;
}

template <typename node>
void min_heap<node>::push(node n) {
	if (size == max_size) {
		max_size *= 2;
		node *new_tree = new node[max_size+1];
		copy_tree(tree, new_tree, size);
		delete[] tree;
		tree = new_tree;
	}
	tree[++size] = n;
	int node_loc = size;
	while (node_loc > 1 && tree[node_loc] < tree[node_loc/2]) {
		swap(tree[node_loc], tree[node_loc/2]);
		node_loc /= 2;
	} 
}

template <typename node>
void min_heap<node>::pop() {
	if (empty()) {
		throw std::out_of_range("Empty");
	}
	
	int node_loc = 1;
	int pre_loc;
	int min_loc;
	swap(tree[1], tree[size--]);
	do {
		pre_loc = node_loc;
		if (node_loc*2 <= size) {
			if (node_loc*2+1 <= size) 
				min_loc = (tree[node_loc*2] < tree[node_loc*2+1]) ? node_loc*2 : node_loc*2+1;
			else 
				min_loc = node_loc*2;
			if (tree[node_loc] > tree[min_loc]) {
				swap(tree[node_loc], tree[min_loc]);
				node_loc = min_loc;
			}
		}			
	} while (pre_loc != node_loc);
}

template <typename node>
node min_heap<node>::front() {
	if (empty()) {
		throw std::out_of_range("Empty");
	}
	return tree[1];	
}

template <typename node>
bool min_heap<node>::empty() {
	return size==0;
}

template <typename node>
void min_heap<node>::print(const int digit) {
	/*
	d : max_depth
	n자리
	리프 사이 k칸 (2칸)
	[사이 칸 개수]
	처음 : (k+n) * x - n/2
	이후 : (k+n) * x * 2 - n = (처음 + n/2) * 2 - n 
	x = 1<<(d - depth - 1) (: d>depth)
	*/
	int depth = 0;
	int max_depth = 0;
	int base_sp = 2;
	int space; 
	bool change_depth = true;
	while ((1<<max_depth) <= size)
		++max_depth;
	for (int i = 1; i <= size; ++i) {
		if (i < (1<<depth)) {
			if (max_depth > depth) {
				if (change_depth) {
					space = 2 * (base_sp + digit) * (1 << (max_depth - depth - 1)) - digit;
					change_depth = false;
				}
				for (int sp = 0; sp < space; ++sp)
					cout << " ";
				cout << setw(digit) << tree[i];	
			}
			else {
				for (int sp = 0; sp < base_sp; ++sp)
					cout << " ";
				cout << setw(digit) << tree[i];	
			}
		}
		else {
			++depth;
			change_depth = true;
			if (max_depth > depth)
				space = (base_sp + digit) * (1 << (max_depth - depth - 1)) - digit/2;
			else
				space = (base_sp+1)/2; 
			cout << endl;
			for (int sp = 0; sp < space; ++sp)
				cout << " ";
			cout << setw(digit) << tree[i];	
		}
	}
	cout << endl;
}

template <typename node>
void heap_sort(int *num, int size, min_heap<node>& hp) {
	for (int i = 0; i < size && !hp.empty(); ++i) {
		num[i] = hp.front();
		hp.pop();
	}
}

int main(void) {
	int N;
	int num[1000000];
	min_heap<int> hp;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int e;
		scanf("%d", &e);
		hp.push(e);
	}
	
	heap_sort(num, N, hp);
	for (int i = 0; i < N; ++i)
		printf("%d\n", num[i]);
	
	return 0;
}
