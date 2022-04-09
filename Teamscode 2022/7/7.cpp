#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG

#include <debug.h>

#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}


typedef long long ll;

const int MAX_N = 2e5 + 5;
int deg[MAX_N];
bitset<10000> b1[MAX_N], b2[MAX_N];

int N, M, Q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> Q;
    fill(deg, deg + N, N - 1);

    set<ll> s;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        deg[a]--;
        deg[b]--;
        s.insert((ll) MAX_N * a + b);
        s.insert((ll) MAX_N * b + a);
    }

    vector<int> two, three;

    int add = 0;

    for (int i = 0; i < N; ++i) {
        if (deg[i] == 2) {
            two.push_back(i);
            // cerr << "two " << i << "\n";
        } else if (deg[i] == 3) {
            //  cerr << "three " << i << "\n";
            three.push_back(i);
        } else if (deg[i] <= 1) {
            add++;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < (int) two.size(); ++j) {
            if (two[j] == i) continue;
            if (s.find((ll) two[j] * MAX_N + i) == s.end()) {
                b1[i][j] = 1;
                // cerr << "join " << two[j] << " " << i << "\n";
            }
        }
        for (int j = 0; j < (int) three.size(); ++j) {
            if (three[j] == i) continue;
            if (s.find((ll) three[j] * MAX_N + i) == s.end()) {
                b2[i][j] = 1;
            }
        }
    }

    //   cerr << b1[0][0] << "\n";
    //    cerr << b1[3][0] << "\n";

    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int rem = 0;
        if (deg[a] == 2 && s.find((ll) MAX_N * a + b) == s.end()) {
            rem++;
        }
        if (deg[b] == 2 && s.find((ll) MAX_N * b + a) == s.end()) {
            rem++;
        }
        cout << add + (b1[a] | b1[b]).count() + (b2[a] & b2[b]).count() - rem
             << "\n";
        //  cerr << (b1[a] | b1[b]).count() << " " << (b2[a] & b2[b]).count()
        //       << "\n";
        //  cerr << (b1[a] | b1[b]) << "\n";
    }
}