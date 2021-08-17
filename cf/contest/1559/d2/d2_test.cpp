#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}
const int maxn = 1e3 + 5;
struct forest {
    int m{};
    vector<int> adj[maxn];
    int par[maxn]{}, depth[maxn]{};
    vector<int> comp[maxn];

    int get(int x) {
        return par[x] == x ? x : par[x] = get(par[x]);
    }

    bool merge(int x, int y) {
        int xroot = get(x), yroot = get(y);
        if (depth[xroot] > depth[yroot]) {
            swap(xroot, yroot);
        }
        if (xroot != yroot) {
            par[xroot] = yroot;
            depth[yroot] = max(depth[yroot], depth[xroot] + 1);
            return true;
        }
        return false;
    }

    bool same(int x, int y) {
        return get(x) == get(y);
    }
};

int main() {
    srand(time(nullptr));
    int trials = 200;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("in.txt");
        forest a, b;
        int n = rnd(1, 10);
        for (int i = 0; i < n; ++i) {
            a.par[i] = i;
            b.par[i] = i;
        }
        a.m = rnd(0, n - 1), b.m = rnd(0, n - 1);
        cout << n << " " << a.m << " " << b.m << endl;
        out << n << " " << a.m << " " << b.m << "\n";
        for (int i = 0; i < a.m; ++i) {
            int c = rnd(0, n - 1), d = rnd(0, n - 1);
            while (a.same(c, d)) {
                c = rnd(0, n - 1), d = rnd(0, n - 1);
            }
            a.merge(c, d);
            cout << c + 1 << " " << d + 1 << endl;
            out << c + 1 << " " << d + 1 << "\n";
        }
        for (int i = 0; i < b.m; ++i) {
            int c = rnd(0, n - 1), d = rnd(0, n - 1);
            while (b.same(c, d)) {
                c = rnd(0, n - 1), d = rnd(0, n - 1);
            }
            cout << c + 1 << " " << d + 1 << endl;
            out << c + 1 << " " << d + 1 << "\n";
        }

        out.close();
        system("./d2 < in.txt > out1.txt");
        system("./d2_correct < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        long long h1, h2;
        in1 >> h1;
        in2 >> h2;
        cout << h1 << " " << h2 << "\n";
        if (h1 != h2) {
            bad = true;
        }
        vector<pair<int, int>> same_comp;
        for (int i = 0; i < h1; ++i) {
            int c, d;
            in1 >> c >> d;
            --c, --d;
            if (a.same(c, d) || b.same(c, d)) {
                bad = true;
                same_comp.emplace_back(c, d);
            }
            a.merge(c, d);
            b.merge(c, d);
        }
        in1.close();
        in2.close();
        if (bad) {
            cout << "bad\n";
            for (auto &i : same_comp) {
                cout << i.first << " " << i.second << "\n";
            }

            return 0;
        }
    }
    cout << "Good"
         << "\n";
}