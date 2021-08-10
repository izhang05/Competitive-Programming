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
        int n = rnd(1, 10);
        int m = rnd(1, n - 1);
        m = n - 1;
        cout << n << " " << m << "\n";
        out << n << " " << m << "\n";
        for (int i = 0; i < n; ++i) {
            int d = rnd(1, 5);
            cout << d << " \n"[i == n - 1];
            out << d << " \n"[i == n - 1];
        }
        for (int i = 2; i <= n; ++i) {
            int p = rnd(1, i - 1);
            cout << i << " " << p << "\n";
            out << i << " " << p << "\n";
        }
        int q = rnd(1, 3);
        cout << q << "\n";
        out << q << "\n";
        for (int i = 0; i < q; ++i) {
            int num = rnd(1, 10);
            cout << num << "\n";
            out << num << "\n";
        }
        out.close();
        system("./dzumbus < in.txt > out1.txt");
        system("./brute_dzumbus < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        for (int i = 0; i < q; ++i) {
            long long a, b;
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