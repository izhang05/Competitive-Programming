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
        ofstream out("in.txt");
        int n = rnd(1, 10);
        cout << n << "\n";
        out << n << "\n";
        for (int i = 2; i <= n; ++i) {
            int p = rnd(1, i - 1);
            cout << i << " " << p << "\n";
            out << i << " " << p << "\n";
        }
        int q = rnd(1, 10);
        cout << q << "\n";
        out << q << "\n";
        for (int i = 0; i < q; ++i) {
            int t = rnd(1, 3), v = rnd(1, n);
            cout << t << " " << v << "\n";
            out << t << " " << v << "\n";
        }
        out.close();
        system("./d < in.txt > out1.txt");
        system("./brute_d < in.txt > out2.txt");

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
}