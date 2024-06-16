#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

bool equal(string file1, string file2) {
    auto read_file = [&](string f) {
        vector<string> words;
        ifstream in(f);
        string token;
        while (in >> token) words.push_back(token);
        return words;
    };
    return read_file(file1) == read_file(file2);
}

bool flip(long double p) {
    return uniform_real_distribution<long double>(0, 1)(rng) < p;
}

int main() {
    srand(time(nullptr));
    int trials = 1000;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("in.txt");
        int t = 1;
        cout << t << "\n";
        out << t << "\n";

        int n = rnd(1, 15);
        vector<int> div;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                div.push_back(i);
            }
        }
        int k = div[rnd(0, int(div.size()) - 1)];
        cout << n << " " << k << "\n";
        out << n << " " << k << "\n";

        if (flip(0.5)) {
            string s;
            for (int i = 0; i < n / k; ++i) {
                for (int j = 0; j < k; ++j) {
                    s += char('0' + i % 2);
                }
            }
            int rot = rnd(0, n);
            string new_s;
            for (int i = n - 1; i >= rot; --i) {
                new_s += s[i];
            }
            for (int i = 0; i < rot; ++i) {
                new_s += s[i];
            }
            cout << new_s << "\n";
            out << new_s << "\n";
        } else {
            for (int i = 0; i < n; ++i) {
                int x = rnd(0, 1);
                cout << x;
                out << x;
            }
            cout << "\n";
            out << "\n";
        }
        out.close();
        system("./d < in.txt > out1.txt");
        system("./brute_d < in.txt > out2.txt");
        if (!equal("out1.txt", "out2.txt")) {
            cout << "difference found\n";
            return 0;
        }
    }
    cout << "Good"
         << "\n";
}
