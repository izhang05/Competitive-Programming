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
        int t = 2;
        cout << t << "\n";
        out << t << "\n";
        for (int i = 0; i < t; ++i) {
            int n = rnd(9e8, 1e9), k = rnd(1, 2);
            cout << n << " " << k << "\n";
            out << n << " " << k << "\n";
        }
        out.close();
        system("./f1 < in.txt > out1.txt");
        system("./f2 < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        long long a, b;
        for (int i = 0; i < t; ++i) {
            in1 >> a;
            in2 >> b;
            cout << a << " " << b << "\n";
            if (a != b) {
                bad = true;
            }
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