#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
}
//#define DEBUG
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

const int maxc = 20, inf = 0x3f3f3f3f;

int occ[26][26], dp[1 << maxc];


int main() {
    setIO();
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - 'a';
    }

    set<int> c;
    for (int i = 0; i < n - 1; ++i) {
        ++occ[a[i]][a[i + 1]];
        c.insert(a[i]);
    }
    c.insert(a[n - 1]);
    vector<int> chars(c.begin(), c.end());
    int m = chars.size();
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 1;
#ifdef DEBUG
    for (int i : chars) {
        cout << char(i + 'a') << " ";
    }
    cout << "\n";
#endif
    for (int mask = 1; mask < (1 << m); ++mask) {

        for (int i = 0; i < m; ++i) {
#ifdef DEBUG
            cout << bool(mask & (1 << i)) << " ";
#endif
            if ((mask & (1 << i))) {
                int prev = mask - (1 << i), cur = dp[prev];
                for (int j = 0; j < m; ++j) {
                    if (mask & (1 << j)) {
                        cur += occ[chars[j]][chars[i]];
                    }
                }
                dp[mask] = min(dp[mask], cur);
            }
        }
#ifdef DEBUG
        cout << "\n";
        cout << dp[mask] << "\n";
        cout << "\n";
#endif
    }
    cout << dp[(1 << m) - 1] << "\n";

#ifdef DEBUG
    cout << "  ";
    for (int k = 0; k < maxc; ++k) {
        cout << char(k + 'a') << " ";
    }
    cout << "\n";
    for (int i = 0; i < maxc; ++i) {
        cout << char(i + 'a') << " ";
        for (int j = 0; j < maxc; ++j) {
            cout << occ[i][j] << " ";
        }
        cout << "\n";
    }
#endif
#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}


//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
//#endif
//}
//#define DEBUG
//template<class T>
//void print(T a, string sep = " ", string end = "\n") {
//    for (auto i : a) {
//        cout << i << sep;
//    }
//    cout << end;
//}
//
//const int maxc = 26;
//
//int occ[maxc][maxc];
//
//int main() {
//    setIO();
//#ifdef LOCAL
//    auto start_time = chrono::high_resolution_clock::now();
//#endif
//    string s;
//    cin >> s;
//    int n = s.size();
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        a[i] = s[i] - 'a';
//    }
//
//    set<int> c;
//    for (int i = 0; i < n - 1; ++i) {
//        ++occ[a[i]][a[i + 1]];
//        c.insert(a[i]);
//    }
//    c.insert(a[n - 1]);
//    vector<int> chars(c.begin(), c.end());
//    int m = chars.size(), sol = 1e9;
//#ifdef DEBUG
//    cout << "  ";
//    for (int k = 0; k < maxc; ++k) {
//        cout << char(k + 'a') << " ";
//    }
//    cout << "\n";
//    for (int i = 0; i < maxc; ++i) {
//        cout << char(i + 'a') << " ";
//        for (int j = 0; j < maxc; ++j) {
//            cout << occ[i][j] << " ";
//        }
//        cout << "\n";
//    }
//#endif
//    do {
//        int cur = 1;
//        for (int i = 0; i < m; ++i) {
//            for (int j = i; j < m; ++j) {
//                cur += occ[chars[j]][chars[i]];
//            }
//        }
//        sol = min(sol, cur);
//#ifdef DEBUG
//        for (int i : chars) {
//            cout << char(i + 'a') << " ";
//        }
//        cout << "\n";
//        cout << cur << "\n";
//        if (cur == 2) {
//            cout << "WHY AREN'T YOU WORKING YOU STUPID THING"
//                 << "\n";
//        }
//
//#endif
//    } while (next_permutation(chars.begin(), chars.end()));
//
//    cout << sol << "\n";
//
//#ifdef LOCAL
//    auto end_time = chrono::high_resolution_clock::now();
//    cout << setprecision(6) << fixed;
//    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
//#endif
//    return 0;
//}
