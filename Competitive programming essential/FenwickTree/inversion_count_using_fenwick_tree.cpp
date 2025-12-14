#include<bits/stdc++.h>

using namespace std;

struct fenwick {
	vector<int> fn;
	int n;
	fenwick() {}
	fenwick(int n) {
		init(n);
	}
	void init(int _n) {
		n = _n + 10;
		fn.clear(); fn.resize(n, 0);
	}
	void add(int x, int val) {
		x++;// 1 based indexing
		while (x < n) {
			fn[x] += val;
			x += (x & (-x));
		}
	}
	int sum(int x) {
		x++;//1 basaed indexing
		int ans = 0;
		while (x) {
			ans += fn[x];
			x -= (x & (-x));
		}
		return ans;
	}
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};

int main()
{
	// freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::vector<int> arr { 283, 653, 87, 305, 604, 703, 589, 937, 674, 784, 576, 882, 308, 209, 651, 828, 140, 650, 316, 898, 67, 107, 660, 51, 619 } ;
	int n = arr.size() ;
	// cin >> n; 
	pair<int, int> a[arr.size()];

	for (int i = 0; i < n; i++) {
		a[i].first = arr[i];
		a[i].second = i;
	}

	sort(a, a + n);
	fenwick tree(n);
	int inversion_count = 0, b[n];

	for (int i = 0; i < n; i++) {
		int element = a[i].first;
		int index = a[i].second;

		b[index] = tree.sum(index + 1, n - 1);

		inversion_count += b[index];
		tree.add(index, 1);

	}

	cout << inversion_count;








	return 0;
}