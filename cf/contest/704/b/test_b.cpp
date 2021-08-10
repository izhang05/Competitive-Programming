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
        int n = rnd(5000, 5000), s = rnd(1, n), e = rnd(1, n);
        while (e == s) {
            e = rnd(1, n);
        }
        cout << n << " " << s << " " << e << endl;
        out << n << " " << s << " " << e << "\n";
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int a = rnd(1, 1e9);
            while (find(nums.begin(), nums.end(), a) != nums.end()) {
                a = rnd(1, 1e9);
            }
            nums.push_back(a);
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
//            cout << nums[i] << " \n"[i == n - 1];
            out << nums[i] << " \n"[i == n - 1];
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < n; ++j) {
                int a = rnd(1, 1e9);
//                cout << a << " \n"[j == n - 1];
                out << a << " \n"[j == n - 1];
            }
        }

        out.close();
        system("./b < in.txt > out1.txt");
        system("./bkpt_b < in.txt > out2.txt");

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