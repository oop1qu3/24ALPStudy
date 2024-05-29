#include <bits/stdc++.h>
#define fastio std::cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
	return a.back() < b.back();
}

int main() {
	fastio;

	int n; cin >> n;
	vector<vector<int>> heap(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		vector<int> e;
		heap.push_back(e);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int u; cin >> u;
			heap[j].push_back(u);
		}
	}

	make_heap(heap.begin(), heap.end(), cmp);
	for (int i = 0; i < n - 1; i++) {
		heap[0].pop_back();
		make_heap(heap.begin(), heap.end(), cmp);
	}

	cout << heap[0].back();
}
