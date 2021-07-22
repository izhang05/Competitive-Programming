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
        int t = rnd(2, 10);
        cout << t << "\n";
        out << t << "\n";
        for (int _ = 0; _ < t; ++_) {
            int n = rnd(1, 20);
            for (int i = 0; i < n; ++i) {
                char c = rnd('a', 'd');
                cout << c;
                out << c;
            }
            cout << "\n";
            out << "\n";
            int m = rnd(1, 2 * n - 1);
            for (int i = 0; i < m; ++i) {
                char c = rnd('a', 'd');
                cout << c;
                out << c;
            }
            cout << "\n";
            out << "\n";
        }
        out.close();
        system("./b < in.txt > out1.txt");
        system("./other_b < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        while (t--) {
            string a, b;
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