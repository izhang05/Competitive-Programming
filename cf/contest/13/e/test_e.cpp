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
        int n = rnd(4, 8), m = rnd(1, 5);
        cout << n << " " << m << "\n";
        out << n << " " << m << "\n";
        for (int i = 0; i < n; ++i) {
            int a = rnd(1, n);
            cout << a << " \n"[i == n - 1];
            out << a << " \n"[i == n - 1];
        }
        for (int _ = 0; _ < m; ++_) {
            int t = rnd(0, 1), a = rnd(1, n);
            if (t == 0) {
                int b = rnd(1, n);
                cout << t << " " << a << " " << b << "\n";
                out << t << " " << a << " " << b << "\n";
            } else {
                cout << t << " " << a << "\n";
                out << t << " " << a << "\n";
            }
        }
        out.close();
        system("./e < in.txt > out1.txt");
        system("./brute_e < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;
        for (int i = 0; i < m; ++i) {
            long long a1, a2, b1, b2;
            in1 >> a1 >> a2;
            in2 >> b1 >> b2;
            if (a1 != b1 || a2 != b2) {
                bad = true;
            }
            cout << a1 << " " << a2 << " " << b1 << " " << b2 << "\n";
        }

        in1.close();
        in2.close();
        if (bad) {
            cout << "bad\n";
            return 0;
        }
    }
    cout << "Good\n";
}