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
        ofstream out("yinyang.in");
        int n = rnd(6, 12);
        cout << n << "\n";
        out << n << "\n";
        for (int i = 2; i <= n; ++i) {
            int p = rnd(1, i - 1), w = rnd(0, 1);
            cout << p << " " << i << " " << w << "\n";
            out << p << " " << i << " " << w << "\n";
        }
        out.close();
        system("./yinyang");
        system("./brute_yinyang");

        ifstream in1("yinyang.out"), in2("brute_yinyang.out");
        bool bad = false;

        long long a, b;
        in1 >> a;
        in2 >> b;
        if (a != b) {
            bad = true;
        }
        cout << a << " " << b << "\n";
        in1.close();
        in2.close();
        if (bad) {
            cout << "bad\n";
            return 0;
        }
    }
}