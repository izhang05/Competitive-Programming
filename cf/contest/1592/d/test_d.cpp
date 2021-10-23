#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
const int maxn = 1e3 + 5;
int edge[maxn][maxn];

int main() {
    ifstream inf("in1.txt");
    memset(edge, -1, sizeof(edge));
    int n, sol = 0;
    inf >> n;
    cout << n << "\n";
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        inf >> a >> b >> c;
        cout << a << " " << b << endl;
        --a, --b;
        edge[a][b] = c, edge[b][a] = c;
        sol = max(sol, c);
    }
    cout.flush();
    ofstream out("log.txt");
    for (int i = 0;; ++i) {
        char type;
        cin >> type;
        if (type == '?') {
            out << type;
            int k;
            cin >> k;
            vector<int> a(k);
            out << " " << k;
            for (int j = 0; j < k; ++j) {
                cin >> a[j];
                out << " " << a[j];
                --a[j];
            }
            out << endl;
            int res = 0;
            for (int i = 0; i < k; ++i) {
                for (int j = i + 1; j < k; ++j) {
                    res = max(res, edge[a[i]][a[j]]);
                }
            }
            cout << res << endl;
            cout.flush();
        } else if (type == '!') {
            int a, b;
            cin >> a >> b;
            --a, --b;
            out << "! " << a + 1 << " " << b + 1 << "\n";
            if (sol == edge[a][b]) {
                out << "Guessed correctly in " << i << " guesses.\n";
                out.close();
                if (i <= 12) {
                    return 0;
                } else {
                    return 1;
                }
            } else {
                out << "Wrong Answer\n";
                out.close();
                return 1;
            }
        }
    }
}
