#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("SZP.in", "r", stdin);
    freopen("SZP.out", "w", stdout);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
int out[maxn], deg[maxn];
vector<int> in[maxn];
bitset<maxn> used, visited;

int main() {
#ifdef LOCAL
    auto start_time = std::chrono::high_resolution_clock::now();
#endif
    setIO();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> out[i];
        --out[i];
        in[out[i]].push_back(i);
    }
    queue<int> nums;
    for (int i = 0; i < n; ++i) {
        deg[i] = in[i].size();
        if (deg[i] <= 1) {
            nums.push(i);
        }
    }
    int sol = 0;
    while (!nums.empty()) {
        int cur = nums.front(), p = out[cur];
#ifdef DEBUG
        cout << cur << endl;
#endif
        nums.pop();
        if (!used[cur] && !used[p]) {
            ++sol;
            used[cur] = used[p] = true;
        }
        visited[cur] = true;
        if (--deg[p] <= 1 && !visited[p]) {
            nums.push(p);
        }
    }
    cout << sol << "\n";
#ifdef LOCAL
    auto end_time = std::chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
