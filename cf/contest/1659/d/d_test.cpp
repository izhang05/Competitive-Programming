#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main() {
    srand(time(nullptr));
    int trials = 100;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("in.txt");
        int t = 1;
        cout << t << "\n";
        out << t << "\n";
        int n = rnd(1, 1000);
        cout << n << "\n";
        out << n << "\n";
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = !(bool) rnd(0, 5);
            cout << a[i] << " \n"[i == n - 1];
        }
        vector<int> orig(a.begin(), a.end());
        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            sort(a.begin(), a.begin() + i + 1);
            for (int j = 0; j < n; ++j) {
                c[j] += a[j];
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << c[i] << " \n"[i == n - 1];
            out << c[i] << " \n"[i == n - 1];
        }

        out.close();
        system("./d < in.txt > out1.txt -Wall -Wextra -O2 -Wshadow -fsanitize=address -fsanitize=undefined");
        //        system("./brute < in.txt > out2.txt");

        ifstream in1("out1.txt");
        bool bad = false;
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            in1 >> res[i];
        }
        if (orig != res) {
            bad = true;
        }

        in1.close();
        if (bad) {
            for (int i = 0; i < n; ++i) {
                cout << res[i] << " \n"[i == n - 1];
            }
            cout << "bad\n";
            return 0;
        }
    }
    cout << "Good"
         << "\n";
}