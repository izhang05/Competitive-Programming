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
        int t = 1;
        cout << t << "\n";
        out << t << "\n";
        int x = rnd(0, 10), y = rnd(0, 10), z = rnd(0, 10);
        while (x + y + z == 0) {
            z = rnd(0, 10);
        }
        cout << x << " " << y << " " << z << "\n";
        out << x << " " << y << " " << z << "\n";

        out.close();

        system("./b < in.txt > out1.txt");

        ifstream in("out1.txt");
        for (int i = 0; i < t; ++i) {
            string sol;
            in >> sol;
            if (sol == "YES") {
                string s;
                in >> s;
                cout << s << "\n";
                int n = x + y + z;
                if (s.size() != n) {
                    cout << "BAD n" << "\n";
                    return 0;
                }
                for (int j = 0; j + 1 < n; ++j) {
                    if (s[j] == s[j + 1]) {
                        cout << "BAD consecutive" << "\n";
                        return 0;
                    }
                }
                for (int j = 0; j + 2 < n; ++j) {
                    if (s[j + 1] == 'I' && s[j] != s[j + 2]) {
                        cout << "BAD MIT" << "\n";
                        return 0;
                    }
                }
                map<char, int> cnt;
                for (auto &j: s) {
                    ++cnt[j];
                }
                if (cnt['M'] != x || cnt['I'] != y || cnt['T'] != z) {
                    cout << "BAD count" << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "Good" << "\n";
}
