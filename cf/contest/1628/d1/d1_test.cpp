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
        int t = 1;
        cout << t << "\n";
        out << t << "\n";
        int n = rnd(1, 2e3), m = rnd(n - 5, n), k = rnd(0, 1e9 + 6);
        cout << n << " " << m << " " << k << "\n";
        out << n << " " << m << " " << k << "\n";

        out.close();
        system("./d1 < in.txt > out1.txt");
        system("./d11 < in.txt > out2.txt");

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