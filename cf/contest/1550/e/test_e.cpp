#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main() {
    system("g++ hack_e.cpp -o hack_e -O3 -std=c++17");
    srand(time(nullptr));
    int trials = 200;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("in.txt");
        int n, k = rnd(1, 17);
        int r = rnd(1, 8);
        if (r == 1) {
            n = rnd(1, 5);
        } else if (r == 2) {
            n = rnd(int(2e5) - 5, int(2e5));
        } else {
            n = rnd(1, int(2e5));
        }
        cout << n << " " << k << "\n";
        out << n << " " << k << "\n";
        for (int i = 0; i < n; ++i) {
            char c = rnd('a', 'a' + k - 1);
            r = rnd(1, 5);
            if (r <= 2) {
                //                cout << c;
                out << c;
            } else {
                //                cout << "?";
                out << "?";
            }
        }
        cout << "\n";
        out << "\n";
        out.close();
        system("./e < in.txt > out1.txt");
        system("./hack_e < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
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
    cout << "Good"
         << "\n";
}