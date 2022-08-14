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

        int n = rnd(2, 4), m = rnd(1, 4), q = rnd(1, n);
        cout << n << " " << m << " " << q << "\n";
        out << n << " " << m << " " << q << "\n";
        for (int i = 0; i < m; ++i) {
            int u = rnd(1, n), v = rnd(1, n), t = rnd(1, 3);
            while (v == u) {
                v = rnd(1, n);
            }
            cout << u << " " << v << " " << t << "\n";
            out << u << " " << v << " " << t << "\n";
        }
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }
        shuffle(nums.begin(), nums.end(), rng);
        for (int i = 0; i < q; ++i) {
            cout << nums[i] << "\n";
            out << nums[i] << "\n";
        }

        out.close();
        system("./6 < in.txt > out1.txt");
        system("./6_brute < in.txt > out2.txt");

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
    cout << "Good" << "\n";
}