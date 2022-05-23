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

        int n = rnd(1, 5), m = rnd(1, 5);
        cout << n << " " << m << "\n";
        out << n << " " << m << "\n";
        for (int i = 0; i < n; ++i) {
            int t = rnd(1, m), e = rnd(t, m), c = rnd(1, 10);
            cout << t << " " << e << " " << c << "\n";
            out << t << " " << e << " " << c << "\n";
        }
        out.close();

        system("./7 < in.txt > out1.txt");
        system("./7_brute < in.txt > out2.txt");
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