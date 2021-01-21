///*
//ID: izhang01
//TASK: cownomics
//LANG: C++11
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    freopen("cownomics.in", "r", stdin);
//    freopen("cownomics.out", "w", stdout);
//    int n, m;
//    cin >> n >> m;
//    vector<string> spot(n), plain(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> spot[i];
//    }
//    for (int i = 0; i < n; ++i) {
//        cin >> plain[i];
//    }
//    int sol = 0;
//    for (int i = 0; i < m; ++i) {
//        for (int j = i + 1; j < m; ++j) {
//            for (int k = j + 1; k < m; ++k) {
//                unordered_set<string> spotted_genes;
//                bool correct = true;
//                for (int l = 0; l < n; ++l) {
//                    string gene;
//                    gene += spot[l][i];
//                    gene += spot[l][j];
//                    gene += spot[l][k];
//                    spotted_genes.insert(gene);
//                }
//                for (int l = 0; l < n; ++l) {
//                    string gene;
//                    gene += plain[l][i];
//                    gene += plain[l][j];
//                    gene += plain[l][k];
//                    if (spotted_genes.count(gene)) {
//                        correct = false;
//                        break;
//                    }
//                }
//                if (correct) {
//                    ++sol;
//                }
//            }
//        }
//    }
//    cout << sol << "\n";
//    return 0;
//}
/*
ID: izhang01
TASK: cownomics
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<string> spot(n), plain(n);
    for (int i = 0; i < n; ++i) {
        cin >> spot[i];
        for (int j = 0; j < m; ++j) {
            if (spot[i][j] == 'A') {
                spot[i][j] = 0;
            }
            if (spot[i][j] == 'C') {
                spot[i][j] = 1;
            }
            if (spot[i][j] == 'T') {
                spot[i][j] = 2;
            }
            if (spot[i][j] == 'G') {
                spot[i][j] = 3;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> plain[i];
        for (int j = 0; j < m; ++j) {
            if (plain[i][j] == 'A') {
                plain[i][j] = 0;
            }
            if (plain[i][j] == 'C') {
                plain[i][j] = 1;
            }
            if (plain[i][j] == 'T') {
                plain[i][j] = 2;
            }
            if (plain[i][j] == 'G') {
                plain[i][j] = 3;
            }
        }
    }
    int sol = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            for (int k = j + 1; k < m; ++k) {
                unordered_set<int> spotted_genes;
                bool correct = true;
                for (int l = 0; l < n; ++l) {
                    int gene = 0;
                    gene += spot[l][i];
                    gene += spot[l][j] * 4;
                    gene += spot[l][k] * 16;
                    spotted_genes.insert(gene);
                }
                for (int l = 0; l < n; ++l) {
                    int gene = 0;
                    gene += plain[l][i];
                    gene += plain[l][j] * 4;
                    gene += plain[l][k] * 16;
                    if (spotted_genes.count(gene)) {
                        correct = false;
                        break;
                    }
                }
                if (correct) {
                    ++sol;
                }
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
