/*
ID: izhang01
TASK: brute_pieaters
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("pieaters.in", "r", stdin);
//    freopen("pieaters.out", "w", stdout);
//    freopen("pieaters.out", "w", stderr);
}
//#define DEBUG
struct cow {
    long long w, l, r;
};
const int maxn = 305;
bool used[maxn];
int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    vector<cow> a(m);
    vector<int> order(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].w >> a[i].l >> a[i].r;
        --a[i].l, --a[i].r;
        order[i] = i;
    }
    long long sol = 0;
    do {
        vector<cow> cur(m);
        for (int i = 0; i < m; ++i) {
            cur[i] = a[order[i]];
        }
        memset(used, false, sizeof(used));
        long long cur_w = 0;
        for (auto &i : cur) {
            bool good = false;
            for (int j = i.l; j <= i.r; ++j) {
                if (!used[j]) {
                    good = true;
                    used[j] = true;
                }
            }
            if (good) {
                cur_w += i.w;
            }
        }
        sol = max(sol, cur_w);
    } while (next_permutation(order.begin(), order.end()));
    cout << sol << "\n";
    return 0;
}
