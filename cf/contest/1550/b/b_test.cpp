#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main() {
    system("g++ hack_b.cpp -o hack_b -O3 -std=c++17");
    srand(time(nullptr));
    int trials = 400;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("in.txt");
        int t = rnd(50, 100);
//        cout << t << "\n";
        out << t << "\n";
        for (int _ = 0; _ < t; ++_) {
            int n, a = rnd(-100, 100), b = rnd(-100, 100);
            if (rnd(1, 8) == 1) {
                n = rnd(1, 5);
            } else {
                n = rnd(1, 100);
            }
//            cout << n << " " << a << " " << b << "\n";
            out << n << " " << a << " " << b << "\n";
            for (int i = 0; i < n; ++i) {
                int s = rnd(0, 1);
//                cout << s;
                out << s;
            }
//            cout << "\n";
            out << "\n";
        }
        out.close();
        system("./b < in.txt > out1.txt");
        system("./hack_b < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;
        for (int i = 0; i < t; ++i) {
            long long a, b;
            in1 >> a;
            in2 >> b;
            if (a != b) {
                bad = true;
            }
//            cout << a << " " << b << "\n";
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