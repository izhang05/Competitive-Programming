#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5005;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long sol = INFL;
int x[maxn], a[maxn], b[maxn], c[maxn], d[maxn], n, e, s;
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

void gen(vector<int> vec) {
    if ((int) vec.size() == n) {
        long long cur = 0;
        for (int i = 0; i < n - 1; ++i) {
            cur += abs(x[vec[i]] - x[vec[i + 1]]);
            if (vec[i] < vec[i + 1]) {
                cur += d[vec[i]] + a[vec[i + 1]];
            } else {
                cur += c[vec[i]] + b[vec[i + 1]];
            }
        }
        sol = min(sol, cur);
        return;
    }
    if ((int) vec.size() == n - 1) {
        vec.push_back(e);
        gen(vec);
        return;
    } else {
        for (int i = 0; i < n; ++i) {
            if (i != e && find(vec.begin(), vec.end(), i) == vec.end()) {
                vec.push_back(i);
                gen(vec);
                vec.pop_back();
            }
        }
    }
}

int main() {
    setIO("1");
    cin >> n >> s >> e;
    --e, --s;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    gen(vector<int>{s});
    cout << sol << "\n";
    return 0;
}
