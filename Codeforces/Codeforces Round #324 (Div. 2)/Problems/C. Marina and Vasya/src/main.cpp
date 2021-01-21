#include <iostream>

using namespace std;

char different_char(char a, char b) {
    if ('a' != a && 'a' != b) {
        return 'a';
    }
    if ('b' != a && 'b' != b) {
        return 'b';
    }
    return 'c';
}

int main() {
    int n, t;
    cin >> n >> t;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int same = 0, different = 0;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == s2[i]) {
            ++same;
        } else {
            ++different;
        }
    }
    if (t < different / 2 + different % 2) {
        cout << "-1" << "\n";
        return 0;
    }
//    for chars that ore the same is both strings: you can change no strings(0) or change both(1)
//    for chars that ore different: you can change one string(0.5) or change both strings(1)
    char solution[n];
    int different_changed_half, different_changed_full, same_changed, same_not_changed, previous_different = 1;
    different_changed_half = max(0, 2 * (different - t));
    different_changed_full = different - different_changed_half;
    same_changed = t - (different_changed_half / 2 + different_changed_full);
    same_not_changed = same - same_changed;
    for (int i = 0; i < n; ++i) {
        char s1char = s1[i];
        char s2char = s2[i];
        if (s1char == s2char) {
            if (same_changed > 0) {
                solution[i] = different_char(s1char, s2char);
                --same_changed;
            } else {
                solution[i] = s1char;
            }
        } else {
            if (different_changed_full > 0) {
                solution[i] = different_char(s1char, s2char);
                --different_changed_full;
            } else if (different_changed_half > 0) {
                if (previous_different == 1) {
                    solution[i] = s2char;
                    previous_different = 2;
                } else {
                    solution[i] = s1char;
                    previous_different = 1;
                }
                --different_changed_half;
            }
        }
    }
    string s;
    for (char i : solution) {
        s += i;
    }
    cout << s << "\n";
    return 0;
}