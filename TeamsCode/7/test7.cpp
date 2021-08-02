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
        for (int i = 0; i < t; ++i) {
            int n = rnd(1, 3);
            cout << n << "\n";
            out << n << "\n";
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    int a = rnd(1, 5);
                    cout << a << " \n"[k == n - 1];
                    out << a << " \n"[k == n - 1];
                }
            }
        }

        out.close();
        system("./7 < in.txt > out1.txt");
        system("./brute7 < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        long long a, b;
        in1 >> a;
        in2 >> b;
        if (a != b) {
            bad = true;
        }
        in1.close();
        in2.close();
        cout << a << " " << b << "\n";
        if (bad) {
            cout << "bad\n";
            return 0;
        }
    }
    cout << "Good" << "\n";
}