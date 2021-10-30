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
        long long t = 1, a = rnd(1, 100000), b = rnd(1, 100000);
        a *= 2, b *= 2;
        cout << t << "\n";
        out << t << "\n";
        cout << a << " " << b << "\n";
        out << a << " " << b << "\n";
        out.close();
        system("./b < in.txt > out1.txt");

        ifstream in1("out1.txt");
        bool bad = false;

        long long x;
        in1 >> x;
        cout << x << "\n";
        if (x % a != b % x) {
            bad = true;
        }

        in1.close();
        if (bad) {
            cout << "bad\n";
            return 0;
        }
    }
    cout << "Good"
         << "\n";
}