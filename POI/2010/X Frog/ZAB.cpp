#include <bits/stdc++.h>


using namespace std;
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//#define DEBUG
const int maxn = 1e6 + 5, maxs = 20;

int up[maxn][maxs], t[maxn], cycle_size[maxn], cnt = 1;
bool visited[maxn];

int jmp(int x, long long d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x; // modification to return -1 if not found
}

void find_cycle(int node) {
    stack<int> path;
    while (true) {
        path.push(node);
        visited[node] = cnt;
        node = t[node];
        if (visited[node]) {
            if (visited[node] == cnt) {
                vector<int> cycle;
                cycle.push_back(node);
                while (path.top() != node) {
                    int cur = path.top();
                    path.pop();
                    cycle.push_back(cur);
                }
                for (auto i : cycle) {
                    cycle_size[i] = cycle.size();
                }
            }
            break;
        }
    }
}

int main() {
    setIO();
    long long n, k, m;
    cin >> n >> k >> m;
    vector<long long> a(n + 1);
    indexed_set<long long> nums;
    unordered_map<long long, int> num_to_ind;
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i];
        nums.insert(a[i]);
        num_to_ind[a[i]] = i;
    }
    for (int i = 1; i < n + 1; ++i) {
#ifdef DEBUG
        cout << i << ":"
             << "\n";
#endif
        long long lo = 1, hi = 1e18, mid, sol = -1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            int cur = nums.order_of_key(a[i] + mid + 1) - nums.order_of_key(a[i] - mid) - 1;
            if (cur == k) {
                if (nums.find(a[i] - mid) != nums.end()) {
#ifdef DEBUG
                    cout << a[i] - mid << " ";
#endif
                    sol = num_to_ind[a[i] - mid];
                    break;
                } else if (nums.find(a[i] + mid) != nums.end()) {
#ifdef DEBUG
                    cout << a[i] + mid << " ";
#endif
                    sol = num_to_ind[a[i] + mid];
                    break;
                }
            }
            if (cur == k + 1 && nums.find(a[i] - mid) != nums.end() && nums.find(a[i] + mid) != nums.end()) {
#ifdef DEBUG
                cout << a[i] - mid << " ";
#endif
                sol = num_to_ind[a[i] - mid];
            }
            if (cur >= k) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
#ifdef DEBUG
        cout << sol << "\n";
        cout << endl;
#endif
        assert(sol != -1);
        up[i][0] = sol;
        t[i] = sol;
    }
    for (int i = 1; i < maxs; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        if (!visited[i]) {
            find_cycle(i);
            ++cnt;
        }
    }
#ifdef DEBUG
    for (int i = 1; i < n + 1; ++i) {
        cout << cycle_size[i] << " ";
    }
    cout << "\n";
#endif
    for (int i = 1; i < n + 1; ++i) {
        if (m <= n) {
            cout << jmp(i, m) << " ";
        } else {
            int cur = jmp(i, n);
#ifdef DEBUG
            cout << cur << " ";
#endif
            cout << jmp(cur, (m - n) % cycle_size[cur]) << " ";
#ifdef DEBUG
            cout << "\n";
#endif
        }
    }
    cout << "\n";
    return 0;
}
