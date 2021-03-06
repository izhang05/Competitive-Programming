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
void print(T a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

//#define DEBUG
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

vector<int> digits(int x) {
    return {x / 10, x % 10};
}
int h, m;

void add_hour(int &x) {
    if (x + 1 == h) {
        x = 0;
    } else {
        ++x;
    }
}

void add_minute(int &x, int &y) {
    if (x + 1 == m) {
        x = 0;
        add_hour(y);
    } else {
        ++x;
    }
}

set<int> good{0, 1, 2, 5, 8};
map<int, int> reflection{{0, 0},
                         {1, 1},
                         {2, 5},
                         {5, 2},
                         {8, 8}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        cin >> h >> m;
        string s;
        cin >> s;
        int a = 10 * (s[0] - '0') + s[1] - '0', b = 10 * (s[3] - '0') + s[4] - '0';
#ifdef DEBUG
        cout << a << " " << b << "\n";
#endif
        while (true) {
            vector<int> cur = digits(b);
            bool found = true;
            for (int i = 0; i < 2; ++i) {
                if (good.find(cur[i]) == good.end()) {
                    found = false;
                    break;
                }
            }
            if (found) {
                int next = 10 * reflection[cur[1]] + reflection[cur[0]];
#ifdef DEBUG
                cout << b << " " << next << "\n";
#endif
                if (next < h) {
                    break;
                } else {
                    add_minute(b, a);
                }
            } else {
                add_minute(b, a);
            }
        }
        while (true) {
            vector<int> cur = digits(a);
            bool found = true;
            for (int i = 0; i < 2; ++i) {
                if (good.find(cur[i]) == good.end()) {
                    found = false;
                    break;
                }
            }
            if (found) {
                int next = 10 * reflection[cur[1]] + reflection[cur[0]];
#ifdef DEBUG
                cout << a << " " << next << "\n";
#endif
                if (next < m) {
                    break;
                } else {
                    add_hour(a);
                }
            } else {
                add_hour(a);
            }
        }
        cout << a / 10 << a % 10 << ":" << b / 10 << b % 10 << "\n";
    }
    return 0;
}
