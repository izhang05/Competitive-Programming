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
    int trials = 1000;
    while (trials--) {
        cout << "testing: " << trials << endl;
        ofstream out("in.txt");
        int n = rnd(1, 5), m = rnd(1, 10);
        cout << n << " " << m << "\n";
        out << n << " " << m << "\n";
        for (int i = 0; i < n; ++i) {
            int a = rnd(1, 10);
            cout << a << " \n"[i == n - 1];
            out << a << " \n"[i == n - 1];
        }

        out.close();
        system("./g < in.txt > out1.txt");
        system("./g_correct < in.txt > out2.txt");
        if (!equal("out1.txt", "out2.txt")) {
            cout << "difference found\n";
            return 0;
        }
    }
    cout << "Good" << "\n";
}
