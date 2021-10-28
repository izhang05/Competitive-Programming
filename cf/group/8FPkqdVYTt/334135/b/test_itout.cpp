#include <bits/stdc++.h>

#include <random>
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
        ofstream out("itout.in");
        int n = rnd(5, 7), k = 1;
        cout << n << " " << k << "\n";
        out << n << " " << k << "\n";
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }
        shuffle(nums.begin(), nums.end(), rng);
        for (int i = 0; i < n; ++i) {
            cout << nums[i] << " \n"[i == n - 1];
            out << nums[i] << " \n"[i == n - 1];
        }

        out.close();
        system("./itout > out1.txt");
        system("./correct_itout");

        ifstream in1("out1.txt"), in2("itout.out");
        bool bad = false;

        long long a, b;
        in1 >> a;
        in2 >> b;
        cout << a << " " << b << "\n";
        if (a != b) {
            bad = true;
        }
        for (int i = 0; i < a; ++i) {
            int c, d;
            in1 >> c;
            in2 >> d;
            cout << c << " " << d << "\n";
            if (c != d) {
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