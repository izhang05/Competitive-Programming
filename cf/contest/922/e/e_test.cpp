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
        int n = 1, w = rnd(0, 1e9), B = rnd(0, 1e9), x = rnd(0, 1e9);
        cout << n << " " << w << " " << B << " " << x << "\n";
        out << n << " " << w << " " << B << " " << x << "\n";
        for (int i = 0; i < n; ++i) {
            int c = rnd(0, 1e2);
            cout << c << " \n"[i == n - 1];
            out << c << " \n"[i == n - 1];
        }
        for (int i = 0; i < n; ++i) {
            int cost = rnd(0, 1e9);
            cout << cost << " \n"[i == n - 1];
            out << cost << " \n"[i == n - 1];
        }

        out.close();
        system("./e < in.txt > out1.txt");
        system("./e_brute < in.txt > out2.txt");

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