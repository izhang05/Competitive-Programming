#include <bits/stdc++.h>

using namespace std;

const int N = 502;

int A, B, n, dp[N][N];
char a[N];

int sol(int l, int r) {
	if (l > r) {
		return 0;
	}
	if (l == r) {
		return A + B;
	}
	int& ret = dp[l][r];
	if (ret != -1) {
		return ret;
	}
	ret = A + B + sol(l + 1, r);
	for (int m = l + 1; m <= r; m++) {
		if (a[l] == a[m]) {
			ret = max(ret, A + sol(l, m - 1) + sol(m + 1, r));
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		memset(dp, -1, sizeof dp);
		cin >> n >> A >> B;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << sol(0, n - 1) << '\n';
	}
	return 0;
}
//........................
//........................
//........................
//...........