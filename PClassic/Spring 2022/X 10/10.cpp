#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG

#include <debug.h>

#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;


void test_case() {
    int n;
    cin >> n;
    vector<int> a(n), visited(n), dist(n);
    vector<vector<int>> rev_adj(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        rev_adj[a[i]].push_back(i);
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i]) {
            continue;
        }
        if (a[a[i]] == i) {
            dbg() << i << " " << a[i] << " " << a[a[i]];
            visited[i] = visited[a[i]] = true;
            sol += 2;
            int mx = 0;
            queue<int> qu;
            qu.push(i);
            while (!qu.empty()) {
                int cur = qu.front();
                qu.pop();
                mx = max(mx, dist[cur]);
                for (auto &j: rev_adj[cur]) {
                    if (!visited[j]) {
                        visited[j] = true;
                        dist[j] = dist[cur] + 1;
                        qu.push(j);
                    }
                }
            }
            sol += mx;
            mx = 0;
            qu.push(a[i]);
            while (!qu.empty()) {
                int cur = qu.front();
                qu.pop();
                mx = max(mx, dist[cur]);
                for (auto &j: rev_adj[cur]) {
                    if (!visited[j]) {
                        visited[j] = true;
                        dist[j] = dist[cur] + 1;
                        qu.push(j);
                    }
                }
            }
            sol += mx;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (visited[i]) {
            continue;
        }
        int cur = i;
        vector<int> seen;
        while (!visited[cur]) {
            dbg() << cur;
            visited[cur] = true;
            seen.push_back(cur);
            cur = a[cur];
        }
        int cnt = 0;
        bool found = false;
        while (!seen.empty()) {
            ++cnt;
            if (seen.back() == cur) {
                found = true;
                break;
            }
            seen.pop_back();
        }
        if (found) {
            sol = max(sol, cnt);
        }
    }
    cout << (sol == 1 ? 0 : sol) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
