#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("1.in", "r", stdin);
#endif
}
const int maxn = 1e5 + 5;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<int, null_type> sol[maxn], visit[maxn];
int edge[maxn], rep[maxn];

bool visited[maxn];

int main() {
    setIO();
    int n, k;
    long long m;
    cin >> n >> k >> m;
    if (m > (long long) n * k) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = i;
            visit[i].insert(i);
        }
        vector<pair<int, int>> swaps(k);
        for (int i = 0; i < k; ++i) {
            cin >> swaps[i].first >> swaps[i].second;
            --swaps[i].first, --swaps[i].second;
        }
        for (int i = 0; i < k; ++i) {
            int tmp = a[swaps[i].second];
            visit[a[swaps[i].first]].insert(swaps[i].second);
            a[swaps[i].second] = a[swaps[i].first];
            visit[tmp].insert(swaps[i].first);
            a[swaps[i].first] = tmp;
        }
        for (int i = 0; i < n; ++i) {
            sol[i] = visit[i];
        }
        for (int i = 0; i < n; ++i) {
            edge[a[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            int cow = a[i];
            if (visited[i]) {
                //            for (int j : sol[rep[i]]) {
                //                sol[cow].insert(j);
                //            }
                continue;
            }
            int loc = i;
            while (loc != cow) {
                if (visited[loc]) {
                    //                for (int j : sol[rep[loc]]) {
                    //                    sol[cow].insert(j);
                    //                }
                    break;
                }
                visited[loc] = true;
                rep[loc] = cow;
                for (int j : visit[loc]) {
                    sol[cow].insert(j);
                }
                loc = edge[loc];
            }
            if (loc == cow) {
                visited[loc] = true;
                rep[loc] = loc;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!visited[i] || rep[i] == i) {
                cout << sol[i].size() << "\n";
            } else {
                cout << sol[rep[i]].size() << "\n";
            }
        }
    } else {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = i;
            sol[i].insert(i);
        }
        vector<pair<int, int>> swaps(k);
        for (int i = 0; i < k; ++i) {
            cin >> swaps[i].first >> swaps[i].second;
            --swaps[i].first, --swaps[i].second;
        }
        for (int r = 0; r < m;) {
            for (int i = 0; i < k; ++i) {
                ++r;
                if (r > m) {
                    break;
                }
                int tmp = a[swaps[i].second];
                sol[a[swaps[i].first]].insert(swaps[i].second);
                a[swaps[i].second] = a[swaps[i].first];
                sol[tmp].insert(swaps[i].first);
                a[swaps[i].first] = tmp;
            }
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (a[i] != i) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << sol[i].size() << "\n";
        }
    }

    return 0;
}
