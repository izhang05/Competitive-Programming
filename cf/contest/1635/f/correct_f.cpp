#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define MAXN 300300

int n, q;
ll x[MAXN], w[MAXN];
ll ans[MAXN];
vector<int> td[MAXN];
vector<pair<int,int>> query[MAXN];

template <typename T>
struct ST
{

	int n;
	int bstart, stsize;
	vector<T> st, up;

	/*

		To fill in

	*/
	const T zero = 5000000000000000000;
	const T noup = 5000000000000000000;

	T op(T a, T b) {
		return min(a, b);
	}

	void pushdown(int c, ll cmin, ll cmax) {
		if (up[c] == noup) return;
		st[c] = min(st[c], up[c]);
		if (c < bstart) {
			up[c * 2 + 1] = min(up[c * 2 + 1], up[c]);
			up[c * 2 + 2] = min(up[c * 2 + 2], up[c]);
		}
		up[c] = noup;
	}

	ST(int _n) {
		n = _n;
		bstart = 1;
		while (bstart < n) bstart *= 2;
		stsize = bstart * 2 - 1;
		bstart--;

		st.resize(stsize, zero);
		up.resize(stsize, noup);
	}

	void update(int c, int cmin, int cmax, int minb, int maxb, T v) {
		pushdown(c, cmin, cmax);
		if (cmin >= minb && cmax <= maxb) {
			up[c] = v;
			pushdown(c, cmin, cmax);
			return;
		}
		if (cmin > maxb || cmax < minb) return;
		update(c * 2 + 1, cmin, (cmin + cmax) / 2, minb, maxb, v);
		update(c * 2 + 2, 1 + (cmin + cmax) / 2, cmax, minb, maxb, v);
		st[c] = op(st[c * 2 + 1], st[c * 2 + 2]);
	}

	void update(int lo, int hi, T v) {
		update(0, 0, bstart, lo, hi, v);
	}

	T query(int c, int cmin, int cmax, int minb, int maxb) {
		pushdown(c, cmin, cmax);
		if (cmin >= minb && cmax <= maxb) return st[c];
		if (cmin > maxb || cmax < minb) return zero;
		return op(query(c * 2 + 1, cmin, (cmin + cmax) / 2, minb, maxb),
			      query(c * 2 + 2, 1 + (cmin + cmax) / 2, cmax, minb, maxb));
	}

	T query(int lo, int hi) {
		return query(0, 0, bstart, lo, hi);
	}

};

ll cost(int i, int j) {
	return abs(x[i] - x[j]) * (w[i] + w[j]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", &x[i], &w[i]);

	stack<int> curr;
	vector<pair<int,int>> good;
	for (int i = 1; i <= n; i++) {
		while (curr.size() && w[curr.top()] >= w[i]) {
			good.push_back({curr.top(), i});
			curr.pop();
		}
		if (curr.size()) good.push_back({curr.top(), i});
		curr.push(i);
	}

	/*

		sort queires by right endopoint

	*/

	for (auto [i, j] : good) {
		td[max(i, j)].push_back(min(i, j));
	}

	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		query[r].push_back({l, i});
	}
	for (int i = 2; i <= n; i++)
		td[i].push_back(i - 1);

	ST<ll> helper(n + 1);

	for (int i = 1; i <= n; i++) {

		for (int j : td[i]) {
			// min update
			helper.update(j, j, cost(i, j));
		}
		for (auto [l, ind] : query[i]) {
			// min query
			ans[ind] = helper.query(l, i);
		}

	}

	for (int i = 0; i < q; i++)
		printf("%lld\n", ans[i]);

}