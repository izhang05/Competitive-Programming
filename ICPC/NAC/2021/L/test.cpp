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

int main() {
    srand(time(nullptr));
    int trials = 1;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("in4.txt");
        int n = 2e5, m = n - 1, d = n;
        out << n << " " << m << " " << d << "\n";
        for (int i = 1; i < n; ++i) {
            out << i << " " << i + 1 << " " << rnd(1, 1e6) << "\n";
        }
        for (int i = 0; i < n; ++i) {
            out << rnd(0, 1e18) << "\n";
        }

        out.close();
//        system("./a < in.txt > out1.txt");
//        system("./brute < in.txt > out2.txt");
//        if (!equal("out1.txt", "out2.txt")) {
//            cout << "difference found\n";
//            return 0;
//        }
    }
    cout << "Good" << "\n";
}
