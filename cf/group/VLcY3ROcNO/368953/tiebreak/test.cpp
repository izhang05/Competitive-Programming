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
        //        int n = rnd(1, 100000), q = rnd(1, 10);
        int n = 1e5, q = 1e5;
        cout << n << " " << q << "\n";
        out << n << " " << q << "\n";
        for (int i = 0; i < n; ++i) {
            int c = rnd(1e5 - 5, 1e5);
            //            cout << c << " \n"[i == n - 1];
            out << c << " \n"[i == n - 1];
        }
        for (int i = 2; i <= n; ++i) {
            int p = rnd(1, i - 1);
            //            cout << i << " " << p << "\n";
            out << i << " " << p << "\n";
        }
        int cnt = 0;
        for (int i = 0; i < q; ++i) {
            int t = rnd(1, 2), a = rnd(1, n);
            //            cout << t << " " << a << " ";
            out << t << " " << a << " ";
            if (t == 1) {
                int c = rnd(1e5 - 5, 1e5);
                //                cout << c << "\n";
                out << c << "\n";
            } else if (t == 2) {
                ++cnt;
                int b = rnd(1, n), c = rnd(1e5 - 5, 1e5);
                //                cout << b << " " << c << "\n";
                out << b << " " << c << "\n";
            }
        }
        out.close();
        system("./chessbot_orz < in.txt > out1.txt");
        system("./bkpt_orz < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        for (int i = 0; i < cnt; ++i) {
            long long a, b;
            in1 >> a;
            in2 >> b;
            //            cout << a << " " << b << "\n";
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