#include <iostream>
#include <unordered_map>

using namespace std;


unordered_map<char, int> histogram(string word) {
    unordered_map<char, int> solution;
    for (char i : word) {
        if (solution.count(i) == 0) {
            solution[i] = 1;
        } else {
            ++solution[i];
        }
    }
    return solution;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n;
    unordered_map<char, int> words[n];
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        words[i] = histogram(word);
    }
    cin >> q;
    unordered_map<char, int> questions[q];
    for (int i = 0; i < q; ++i) {
        string word;
        cin >> word;
        questions[i] = histogram(word);
    }

    for (unordered_map<char, int> i : questions) {
        int defaul = 1000000000;
        int solution = defaul;
        for (int j = 0; j < n; ++j) {
            unordered_map<char, int> frequency = words[j];
            bool found = true;
            for (pair<const char, int> k : i) {
                if (frequency.count(k.first) == 0) {
                    found = false;
                    break;
                }
                if (i[k.first] > frequency[k.first]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                solution = 1;
                break;
            }
            for (int k = 1; k < n - j; ++k) {
                for (pair<const char, int> m : words[j + k]) {
                    if (frequency.count(m.first) == 0) {
                        frequency[m.first] = 1;
                    } else {
                        ++frequency[m.first];
                    }
                }
                found = true;
                for (pair<const char, int> p : i) {
                    if (frequency.count(p.first) == 0) {
                        found = false;
                        break;
                    }
                    if (i[p.first] > frequency[p.first]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    solution = k + 1;
                    break;
                }
            }
        }
        if (solution == defaul) {
            cout << -1 << "\n";
        } else {
            cout << solution << "\n";
        }
    }
    return 0;
}
