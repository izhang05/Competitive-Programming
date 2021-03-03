/*
ID: izhang01
TASK: guard
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
}
//#define DEBUG

struct cow {
    long long h, w, s;
};

int maxn= 20;
long long height[1 << maxn], ;

int main() {
    setIO();
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    long long n, h;
    cin >> n >> h;
    vector<cow> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].h >> a[i].w >> a[i].s;
    }


#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
