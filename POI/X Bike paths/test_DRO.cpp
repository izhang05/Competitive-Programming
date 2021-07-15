#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main() {
    srand(time(nullptr));
    int trials = 200;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("1.in");
        int n = rnd(2, 10), m = rnd(1, 10);
        cout << n << " " << m << "\n";
        out << n << " " << m << "\n";
        set<pair<int, int>> seen;
        for (int i = 0; i < m; ++i) {
            int a = rnd(1, n), b = rnd(1, n);
            while (b == a || seen.find(make_pair(a, b)) != seen.end()) {
                b = rnd(1, n);
            }
            cout << a << " " << b << endl;
            out << a << " " << b << "\n";
            seen.insert({a, b});
        }
        out.close();
        system("./DRO > out1.txt");
        system("./brute_DRO > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        long long a, b;
        in1 >> a;
        in2 >> b;
        if (a != b) {
            bad = true;
        }

        in1.close();
        in2.close();
        if (bad) {
            cout << "bad\n";
            return 0;
        }
    }
    cout << "Good"
         << "\n";
}