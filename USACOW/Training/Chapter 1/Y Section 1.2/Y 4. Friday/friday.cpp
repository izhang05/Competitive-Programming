/*
ID: izhang01
TASK: friday
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    int n;
    fin >> n;
    int day = 6; // day of week on the 13th
    map<int, int> frequency = {{0, 0},
                               {1, 0},
                               {2, 0},
                               {3, 0},
                               {4, 0},
                               {5, 0},
                               {6, 0}};
    for (int year = 1900; year < 1900 + n; ++year) {
        for (int month = 1; month < 13; ++month) {
            ++frequency[day];
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                day += 31;
                day %= 7;
            } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                day += 30;
                day %= 7;
            } else {
                if (year % 100 == 0) {
                    if (year % 400 == 0) {
                        day += 29;
                        day %= 7;
                    }
                } else if (year % 4 == 0) {
                    day += 29;
                    day %= 7;
                }
            }
        }
    }
    fout << frequency[6] << " ";
    for (int i = 0; i < 5; ++i) {
        fout << frequency[i] << " ";
    }
    fout << frequency[5] << "\n";
    return 0;
}