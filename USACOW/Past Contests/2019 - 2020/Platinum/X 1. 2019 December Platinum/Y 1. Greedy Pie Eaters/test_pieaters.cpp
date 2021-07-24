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
        ofstream out("pieaters.in");
        int n = rnd(1, 3), m = rnd(1, (n * (n + 1)) / 2);
        cout << n << " " << m << "\n";
        out << n << " " << m << "\n";
        set<pair<int, int>> used;
        for (int i = 0; i < m; ++i) {
            int w = rnd(1, 10), l = rnd(1, n), r = rnd(l, n);
            while (used.find({l, r}) != used.end()) {
                l = rnd(1, n), r = rnd(l, n);
            }
            used.insert({l, r});
            cout << w << " " << l << " " << r << "\n";
            out << w << " " << l << " " << r << "\n";
        }
        out.close();
        system("./pieaters > out1.txt");
        system("./brute_pieaters > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        long long a, b;
        in1 >> a;
        in2 >> b;
        cout << a << " " << b << "\n";
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