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
        cout << 1 << "\n";
        out << 1 << "\n";
        int n = rnd(12, 12);
        n = 11;
        cout << n << "\n";
        out << n << "\n";
        for (int i = 0; i < n; ++i) {
            int a = rnd(0, 1);
            cout << a << " \n"[i == n - 1];
            out << a << " \n"[i == n - 1];
        }
        cout.flush();

        out.close();
        system("./b < in.txt > out1.txt");

        ifstream in1("out1.txt");
        bool bad = false;

        string s;
        in1 >> s;
        cout << s << "\n";
        if (s != "NO" && s != "YES") {
            bad = true;
        }
        if (s == "YES") {
            int a;
            in1 >> a;
            if (a > n) {
                bad = true;
            }
            cout << a << "\n";
        }

        in1.close();
        if (bad) {
            cout << "bad\n";
            return 0;
        }
    }
    cout << "Good"
         << "\n";
}