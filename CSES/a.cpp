#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

string rearrangedString(string s) {
    map<char, int> a;
    for (char i : s) {
        if (i >= '0' && i <= '9') {
            ++a[i];
        } else if (i >= 'a' && i <= 'z') {
            ++a[i];
        } else if (i >= 'A' && i <= 'Z') {
            ++a[i];
        }
    }
    map<int, vector<char>, greater<int>> b;
    for (auto i : a) {
        b[i.second].push_back(i.first);
    }
    string res;
    int count = 0;
    for (auto i : b) {
        res += to_string(i.first);
        if (count % 2 == 1) {
            reverse(i.second.begin(), i.second.end());
        }
        ++count;
        for (char j : i.second) {
            res.push_back(j);
        }
        if (i.first != 1) {
            res.push_back(',');
        }
    }
    return res;
}

int main() {
#ifdef LOCAL
    auto start_time = std::chrono::high_resolution_clock::now();
#endif
    setIO();

    string s = "This is an Example of Sorting an interesting string";
    cout << s << "\n";
    cout << rearrangedString(s) << "\n";

#ifdef LOCAL
    auto end_time = std::chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
