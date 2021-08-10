#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 5050
#define ll long long
#define FUNNINUBER 694206942069420

ll n, s, e;
ll a[MAXN], b[MAXN], c[MAXN], d[MAXN], x[MAXN];
int nextv[MAXN];

ll cost(ll n1, ll n2) {
	if (n1 < n2)
		return abs(x[n1] - x[n2]) + d[n1] + a[n2];
	return abs(x[n1] - x[n2]) + c[n1] + b[n2];
}

int main() {

	scanf(" %lld%lld%lld", &n, &s, &e);

	for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &d[i]);

	nextv[s] = e;
	ll ans = cost(s, e);

	for (int i = 1; i <= n; i++) {
		if (i == s || i == e) continue;

		ll mincost = FUNNINUBER, node = -1;
		int cnode = s;

		while (cnode != e) {
			ll newcost = cost(cnode, i) + cost(i, nextv[cnode]) - cost(cnode, nextv[cnode]);
			if (newcost < mincost)
				mincost = newcost, node = cnode;
			cnode = nextv[cnode];
		}

		nextv[i] = nextv[node];
		nextv[node] = i;
		ans += mincost;

	}

	printf("%lld\n", ans);



}