#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b);++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    vector<vector<int>> sol(m);
    vector<long long> prize(m), skills(m);
    for (int i = 0; i < m; ++i) {
        cin >> prize[i];
    }
    for (auto &i: a) {
        pair<long double, int> best;
        for (int j = 0; j < m; ++j) {
            best = max(best, {(long double) prize[j] * i.first / (long double) (i.first + skills[j]), j});
        }
        skills[best.second] += i.first;
        sol[best.second].push_back(i.second);
    }
    for (auto &i: sol) {
        cout << i.size();
        for (auto &j: i) {
            cout << " " << j;
        }
        cout << "\n";
    }

//    for (int i = 0; i < n; ++i) {
//        long double best = 0;
//        for (int j = 0; j < m; ++j) {
//            if (j != allocate[a[i].second]) {
//                best = max(best, (long double) prize[j] * a[i].first / (long double) (a[i].first + skills[j]));
//            }
//        }
//        if (best >
//            (long double) prize[allocate[a[i].second]] * a[i].first / (long double) (skills[allocate[a[i].second]])) {
//            cout << "bad" << " " << a[i].first << " " << a[i].second << " " << best << "\n";
//            exit(0);
//        }
//    }
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    solve();
}
