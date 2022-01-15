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
        int n = rnd(1, 5);
        n = 100;
        cout << n << "\n";
        out << n << "\n";
        set<int> occ;
        //        for (int i = 0; i < n; ++i) {
        //            int a = rnd(1, 10);
        //            while (occ.find(a) != occ.end()) {
        //                a = rnd(1, 10);
        //            }
        //            occ.insert(a);
        //            cout << a << " \n"[i == n - 1];
        //            out << a << " \n"[i == n - 1];
        //        }
        for (int i = 1e6; i >= 1e6 - 99; --i) {
            cout << i << " ";
            out << i << " ";
        }
        cout << "\n";
        out.close();
        system("./d < in.txt > out1.txt");
        system("./brute_d < in.txt > out2.txt");

        ifstream in1("out1.txt"), in2("out2.txt");
        bool bad = false;

        long long a, b;
        in1 >> a;
        in2 >> b;
        cout << a << " " << b << "\n";
        if (a != b) {
            bad = true;
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