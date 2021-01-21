#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1e6;
int num_comp;
bool in_comp[maxn];


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        num_comp = 1;
        set<pair<int, int>> cur;
        int a;
        for (int i = 0; i < n; ++i) {
            getchar();
            a = getchar() - '0';
            cur.insert(make_pair(a, i));
            in_comp[i] = true;
        }
        vector<int> sol(d);
        vector<pair<int, int>> queries(d);
        for (int i = 0; i < d; ++i) {
            getchar();
            queries[i].first = getchar() - '0';
            queries[i].second = i;
        }
        sort(queries.begin(), queries.end());
        for (int i = 0; i < d; ++i) {
            while (!cur.empty() && cur.begin()->first <= queries[i].first) {
                int ind = cur.begin()->second;
                in_comp[ind] = false;
                if (ind != 0 && ind != n - 1 && in_comp[ind - 1] && in_comp[ind + 1]) {
                    ++num_comp;
                } else if (!in_comp[max(0, ind - 1)] && !in_comp[min(n - 1, ind + 1)]) {
                    --num_comp;
                }
                cur.erase(cur.begin());
            }
            sol[queries[i].second] = num_comp;
        }
        for (int i = 0; i < d - 1; ++i) {
            cout << sol[i] << " ";
        }
        cout << sol[d - 1] << "\n";
    }
    return 0;
}
