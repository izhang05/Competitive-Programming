#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

const long long nph = 3.6e12, npm = 6e10, nps = 1e9, mxn = 4.32e13;

long long add(long long a, long long b) {
    return (a + b) % mxn;
}

vector<long long> sol(long long a, long long b, long long c) {
//    if (c % 720 != 0) {
//        long long diff = c % 720;
//        a = add(a, 720 - diff);
//        b = add(b, 720 - diff);
//        c = add(c, 720 - diff);
//    }
#ifdef DEBUG
    cout << a << " " << b << " " << c << " " << c % (long long) 1e9 << "\n";
#endif
    if (c % (long long) 1e9 != 0) {
        long long diff = c % (long long) 1e9;
        a = add(a, 1e9 - diff);
        b = add(b, 1e9 - diff);
        c = add(c, 1e9 - diff);
    }
#ifdef DEBUG
    cout << a << " " << b << " " << c << " " << c % (long long) 1e9 << "\n";
#endif
    //    if (b % 12 != 0) {
    //        return vector<long long>{-1};
    //    }
    for (int i = 0; i < 43200; ++i) {
        a = add(a, 1e9);
        b = add(b, 1e9);
        c = add(c, 1e9);
        long long h = a, m = b / 12, s = c / 720;
        //#ifdef DEBUG
        //        cout << h << " " << m << " " << s << "\n";
        //#endif
        if ((h - m) % nph != 0) {
            continue;
        }
        if ((h - s) % npm != 0) {
            continue;
        }
        vector<long long> sol;
        sol.push_back(h / nph);
        h %= nph;
        sol.push_back(h / npm);
        h %= npm;
        sol.push_back(h / nps);
        h %= nps;
        sol.push_back(h);
        return sol;
    }
    return vector<long long>{-1};
}

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;
    vector<long long> cur{a, b, c};
    sort(cur.begin(), cur.end());
    do {
        vector<long long> res = sol(cur[0], cur[1], cur[2]);
        if (res[0] != -1) {
            print(res);
            return;
        }
    } while (next_permutation(cur.begin(), cur.end()));
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}


//#include <bits/stdc++.h>
//
//using namespace std;
//
//#define DEBUG
//void setIO(string name) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen((name + ".in").c_str(), "r", stdin);
//    freopen((name + ".out").c_str(), "w", stdout);
//    freopen((name + ".out").c_str(), "w", stderr);
//#endif
//}
//template<class T>
//void print(T a, string sep = " ", string end = "\n") {
//    for (auto i : a) {
//        cout << i << sep;
//    }
//    cout << end;
//}
//
//const long long nph = 3.6e12, npm = 6e10, nps = 1e9, mxn = 4.32e13;
//
//vector<long long> sol(long long a, long long b, long long c) {
//    vector<long long> cur{a, b, c};
//    sort(cur.begin(), cur.end());
//    do {
//        if (cur[1] % 12 != 0 || cur[2] % 720 != 0) {
//            continue;
//        }
//        long long h = cur[0], m = cur[1] / 12, s = cur[2] / 720;
//        if ((h - m) % nph != 0) {
//            continue;
//        }
//        if ((h - s) % npm != 0) {
//            continue;
//        }
//        vector<long long> sol;
//        sol.push_back(h / nph);
//        h %= nph;
//        sol.push_back(h / npm);
//        h %= npm;
//        sol.push_back(h / nps);
//        h %= nps;
//        sol.push_back(h);
//        return sol;
//    } while (next_permutation(cur.begin(), cur.end()));
//}
//
//void solve() {
//    long long a, b, c;
//    cin >> a >> b >> c;
//    print(sol(a, b, c));
//}
//
//int main() {
//    setIO("1");
//    int t;
//    cin >> t;
//    for (int i = 1; i <= t; ++i) {
//        cout << "Case #" << i << ": ";
//        solve();
//    }
//}
