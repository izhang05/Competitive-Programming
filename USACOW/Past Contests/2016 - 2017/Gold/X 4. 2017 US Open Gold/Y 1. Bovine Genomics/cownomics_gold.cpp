/*
ID: izhang01
TASK: cownomics
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
}


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    string s;
    vector<vector<char> > spotted(n, vector<char>(m));
    vector<vector<char> > plain(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            spotted[i][j] = s[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            plain[i][j] = s[j];
        }
    }
    int low = 1, high = m, mid, sol = 314159265;
    while (low <= high) {
        bool pos = false;
        vector<string> spot_genes(n);
        mid = (low + high) / 2;
        for (int k = 0; k + mid < m; ++k) {
            bool same = false;
            unordered_set<string> spot;
            for (int i = 0; i < n; ++i) {
                if (k == 0) {
                    string gene;
                    mid = (low + high) / 2;
                    for (int j = k; j < k + mid; ++j) {
                        gene += spotted[i][j];
                    }
                    spot.insert(gene);
//                    cout << gene << "\n";
                    spot_genes[i] = gene;
                } else {
                    spot_genes[i].erase(0, 1);
                    spot_genes[i].push_back(spotted[i][k + mid - 1]);
//                    assert(spot_genes.size() == n - 1);
//                    assert(i < n - 1);
//                    assert(false);
                    spot.insert(spot_genes[i]);
//                    cout << spot_genes[i] << "\n";
                }
//                cout << gene << "\n";
            }
            for (int i = 0; i < n; ++i) {
                string gene;
                mid = (low + high) / 2;
                for (int j = k; j < k + mid; ++j) {
                    gene += plain[i][j];
                }
                if (spot.find(gene) != spot.end()) {
                    same = true;
                    break;
                }
            }
            if (!same) {
                pos = true;
                break;
                assert(false);
            }
        }
//        assert(!pos);
        if (!pos) {
//            assert(false);
            low = mid + 1;
        } else {
//            assert(false);
            high = mid - 1;
            sol = mid;
        }
    }
    cout << sol << "\n";
    return 0;
}
