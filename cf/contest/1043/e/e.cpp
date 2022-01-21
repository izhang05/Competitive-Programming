/* Author: izhang
 * Time: 01-20-2022 21:50:02
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];

void test_case() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> val(n);
    vector<pair<pair<long long, long long>, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second;
        val[i] = a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < m; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    sort(a.begin(), a.end(), [](auto left, auto right) {
        return left.first.first - left.first.second < right.first.first - right.first.second;
    });
    vector<long long> sol(n);
    long long l_sum = 0, r_sum = 0;
    set<int> l, r;
    for (auto &i : a) {
        r_sum += i.first.second;
        r.insert(i.second);
    }
    for (auto &i : a) {
        r_sum -= i.first.second;
        r.erase(i.second);
        long long sum = l_sum + r_sum, l_cnt = int(l.size()), r_cnt = int(r.size());
        for (auto &j : adj[i.second]) {
            if (l.find(j) != l.end()) {
                --l_cnt;
                sum -= val[j].first;
            } else {
                --r_cnt;
                sum -= val[j].second;
            }
        }
        sol[i.second] = sum + i.first.first * r_cnt + i.first.second * l_cnt;
        l_sum += i.first.first;
        l.insert(i.second);
    }

    for (auto &i : sol) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
