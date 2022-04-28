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
//        int n = rnd(1, 100), q = rnd(1, 100);
        int n = 1e4, q = 1e5;
//        cout << n << " " << q << "\n";
        out << n << " " << q << "\n";
        for (int i = 0; i < n; ++i) {
            int h = rnd(1, 500);
            h = 20;
//            cout << h;
            out << h;
            for (int j = 0; j < h; ++j) {
                int a = rnd(1, 1000);
                a = rnd(5e8, 1e9);
//                cout << " " << a;
                out << " " << a;
            }
//            cout << "\n";
            out << "\n";
        }
        for (int i = 0; i < q; ++i) {
            int l = rnd(1, n), r = rnd(l, n);
//            cout << l << " " << r << "\n";
            out << l << " " << r << "\n";
        }

        out.close();
        return 0;
        system("./11 < in.txt > out1.txt");
        system("./11_other < in.txt > out2.txt");

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