#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("Y 21.in", "r", stdin);
#endif
}
const int maxn = 2e5 + 5;
int sol[maxn];
bool visited[maxn];


int main() {
    setIO();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (sol[i]) {
            continue;
        }
        vector<int> past;
        int cur = i;
        visited[cur] = true;
        past.push_back(cur);
        while (true) {
            cur = a[cur];
            if (sol[cur] || visited[cur]) {
                break;
            }
            past.push_back(cur);
            visited[cur] = true;
        }
        int l = past.size();
        if (sol[cur]) {
            for (int j : past) {
                sol[j] = sol[cur] + l--;
            }
        } else if (visited[cur]) {
            int s = past.end() - find(past.begin(), past.end(), cur);
            sol[cur] = s;
            int j;
            for (j = (int) past.size() - 1; j >= 0 && past[j] != cur; --j) {
                sol[past[j]] = s;
            }
            l = past.size() - s;
            for (int k = 0; k < j; ++k) {
                sol[past[k]] = sol[cur] + l--;
            }
        } else {
            assert(false);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << " ";
    }
    cout << "\n";
    return 0;
}
