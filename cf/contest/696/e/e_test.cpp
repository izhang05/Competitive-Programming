#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main() {
    srand(time(nullptr));
    int trials = 2000;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("in.txt");
        int n = 10, m = rnd(1, 100), q = 10;
        //        cout << n << " " << m << " " << q << "\n";
        out << n << " " << m << " " << q << "\n";
        int cnt = 0;
        for (int i = 2; i <= n; ++i) {
            int p = rnd(1, i - 1);
            //            cout << p << " " << i << "\n";
            out << p << " " << i << "\n";
        }
        for (int i = 0; i < m; ++i) {
            int c = rnd(1, n);
            //            cout << c << " \n"[i == m - 1];
            out << c << " \n"[i == m - 1];
        }
        for (int i = 0; i < q; ++i) {
            int t = rnd(1, 2);
            if (t == 1) {
                int u = rnd(1, n), v = rnd(1, n), k = rnd(1, 1);
                //                cout << 1 << " " << u << " " << v << " " << k << "\n";
                out << 1 << " " << u << " " << v << " " << k << "\n";
                ++cnt;
            } else {
                int v = rnd(1, n), k = rnd(1, 100);
                //                cout << 2 << " " << v << " " << k << "\n";
                out << 2 << " " << v << " " << k << "\n";
            }
        }

        out.close();
        system("./e < in.txt > out1.txt");
        system("./e_correct < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;
        if (system("diff out1.txt out2.txt -w")) {
            bad = true;
        }
        //
        //        for (int i = 0; i < cnt; ++i) {
        //            long long a, b;
        //            in1 >> a;
        //            in2 >> b;
        //            cout << a << " " << b << "\n";
        //            if (a != b) {
        //                bad = true;
        //            }
        //        }

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