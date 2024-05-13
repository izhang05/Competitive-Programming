#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

unordered_map<long long, long long> sol;
set<long long> occ;

vector<long long> a;

void solve(int b, vector<long long> cur) {
    if (cur.empty()) {
        return;
    }
    if (int(cur.size()) == 1) {
        sol[*cur.begin()] = *cur.begin();
        return;
    }
    vector<long long> f, g;
    for (auto &i: cur) {
        if (i & (1ll << b)) {
            g.push_back(i);
        } else {
            f.push_back(i);
        }
    }
    solve(b + 1, f), solve(b + 1, g);
//    cout << "f:" << "\n";
    for (auto &i: f) {
        long long add = sol[i] ^ (1ll << b);
        if (occ.find(add) != occ.end()) {
            sol[i] ^= (1ll << b);
        }
//        cout << a[i] << " " << sol[a[i]] << "\n";
    }
//    cout << "g:" << "\n";
    for (auto &i: g) {
        sol[i] ^= (1ll << b);
//        cout << a[i] << " " << sol[a[i]] << "\n";
    }
//    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        occ.insert(a[i]);

//        ind[a[i]] = i;
    }
    vector<long long> cur;
    for (int i = 0; i < n; ++i) {
        cur.push_back(a[i]);
    }
    solve(0, cur);
    for (auto &i: a) {
        cout << sol[i] << "\n";
    }
}




//#include <bits/stdc++.h>
//
//using namespace std;
//#define rep(i, a, b) for(int i = a; i < (b); ++i)
//#define all(x) begin(x), end(x)
//#define sz(x) (int)(x).size()
//typedef long long ll;
//typedef pair<int, int> pii;
//typedef vector<int> vi;
//
//map<int, int> sol, ind;
//vector<int> a;
//const int mxn = (1 << 18);
//
//
//void solve(int b, set<int> cur) {
//    if (cur.empty()) {
//        return;
//    }
//    if (int(cur.size()) == 1) {
//        sol[a[*cur.begin()]] = a[*cur.begin()];
//        return;
//    }
//    set<int> f, g, h;
//    for (auto &i: cur) {
//        if (a[i] & (1 << b)) {
//            h.insert(i);
//        } else {
//            int add = a[i] ^ (1 << b);
//            if (ind.find(add) != ind.end() && cur.find(ind[add]) != cur.end()) {
//                f.insert(i);
//            } else {
//                g.insert(i);
//            }
//        }
//    }
//    cout << "f: ";
//    for (auto &i: f) {
//        cout << i << " ";
//    }
//    cout << "\n";
//    cout << "g: ";
//    for (auto &i: g) {
//        cout << i << " ";
//    }
//    cout << "\n";
//    cout << "h: ";
//    for (auto &i: h) {
//        cout << i << " ";
//    }
//    cout << "\n";
//
//
//    solve(b + 1, f), solve(b + 1, g);
//    // swap f and h pairings
//    for (auto &i: h) {
//        int rem = a[i] ^ (1 << b);
//        sol[a[i]] = sol[a[ind[rem]]];
//        sol[a[ind[rem]]] |= (1 << b);
//    }
//}
//
//int main() {
//    cin.tie(0)->sync_with_stdio(0);
//    cin.exceptions(cin.failbit);
//    int n;
//    cin >> n;
//    a.resize(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//        ind[a[i]] = i;
//    }
//    set<int> cur;
//    for (int i = 0; i < n; ++i) {
//        cur.insert(i);
//    }
//    solve(0, cur);
//    for (auto &i: a) {
//        cout << sol[i] << "\n";
//    }
//
//}