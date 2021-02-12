#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int n;
    cin >> n;
    vector<pair<int, int> > movie(n);
    for (int i = 0; i < n; ++i) {
        cin >> movie[i].second >> movie[i].first;
    }
    sort(movie.begin(), movie.end());
    int sol = 1, pre = movie[0].first;
    for (int i = 1; i < n; ++i) {
        if (movie[i].second >= pre) {
            pre = movie[i].first;
            ++sol;
        }
    }
    cout << sol << "\n";
    return 0;
}
