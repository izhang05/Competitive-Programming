#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front

typedef long long lli;
typedef pair<int, int> ii;
typedef pair<lli, lli> ll;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> os;

int a[100005];

int main() {
	/*os x;
	x.order_of_key(v); // banyak objek < v
	*x.find_by_order(v); // objek ke-v (0-based)*/
	int tc, n;
	multiset<int> odd, even;
	multiset<int>::iterator it;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		odd.clear();
		even.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (i & 1)
				odd.insert(a[i]);
			else
				even.insert(a[i]);
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++) {
			if (i & 1) {
				it = odd.find(a[i]);
				if (it == odd.end())
					break;
				odd.erase(it);
			}
			else {
				it = even.find(a[i]);
				if (it == even.end())
					break;
				even.erase(it);
			}
		}
		if (odd.empty() && even.empty())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}