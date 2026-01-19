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
//        cout << t << "\n";
        out << t << "\n";
        while (t--) {
            int n = rnd(1e6-10, 1e6), k = rnd(1, min(5, n));
            vector<int> perm(n);
            for (int i = 0; i < n; ++i) {
                perm[i] = i + 1;
            }
            shuffle(perm.begin(), perm.end(), rng);
//            cout << n << " " << k << "\n";
            out << n << " " << k << "\n";
            for (int i = 0; i < n; ++i) {
//                cout << perm[i] << " \n"[i == n - 1];
                out << perm[i] << " \n"[i == n - 1];
            }
        }

        out.close();
        system("./2025Day_1e < in.txt > out1.txt");
        system("./2025Day_1cyclic_buffer < in.txt > out2.txt");
        if (!equal("out1.txt", "out2.txt")) {
            cout << "difference found\n";
            return 0;
        }
    }
    cout << "Good" << "\n";
}
