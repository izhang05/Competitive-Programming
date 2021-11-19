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
        int t = 10;
        cout << t << "\n";
        out << t << "\n";
        for (int _ = 0; _ < t; ++_) {
            int n = rnd(1, 5), m = rnd(1, 8);
            cout << n << " " << m << "\n";
            out << n << " " << m << "\n";
            for (int i = 0; i < n; ++i) {
                int a = rnd(0, 20);
                cout << a << " \n"[i == n - 1];
                out << a << " \n"[i == n - 1];
            }
            for (int i = 0; i < m; ++i) {
                int a = rnd(0, 10);
                cout << a << " \n"[i == m - 1];
                out << a << " \n"[i == m - 1];
            }
        }

        out.close();
        system("./FUNARR < in.txt > out1.txt");
        system("./FUNARR_brute < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        string a, b;
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
    cout << "Good" << "\n";
}