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
        out << 1 << "\n";
        cout << 1 << "\n";
        out << 203 - trials << "\n";
        cout << 203 - trials << "\n";

        out.close();
        system("./2B > out1.txt");
        system("./brute_b > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;
        string _;
        in1 >> _;
        in1 >> _;
        in2 >> _;
        in2 >> _;

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
            cout << a << " " << b << "\n";
            //            return 0;
        }
    }
}