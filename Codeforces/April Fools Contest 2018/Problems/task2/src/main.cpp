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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
set<string> normal{"don't think so", "great", "don't touch me", "not bad", "cool"};
set<string> grumpy{"don't even", "no way", "are you serious", "go die in a hole", "worse", "terrible"};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        cout << i << endl;
        string s;
        getline(cin, s);
        if (s == "no") {
            ++count;
        }
        if (count > 3 || normal.find(s) != normal.end()) {
            cout << "normal" << "\n";
            return 0;
        }
        if (grumpy.find(s) != grumpy.end()) {
            cout << "grumpy" << "\n";
            return 0;
        }
    }
    return 0;
}
