#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int N;
string img[20];

struct PCL {
    int i1, j1, i2, j2;
};
vector<PCL> V;
bool beenthere[20][20];

void visit(int i, int j, int c, int i1, int j1, int i2, int j2) {
    beenthere[i][j] = true;
    if (i > i1 && img[i - 1][j] - 'A' == c && !beenthere[i - 1][j])
        visit(i - 1, j, c, i1, j1, i2, j2);
    if (i < i2 && img[i + 1][j] - 'A' == c && !beenthere[i + 1][j])
        visit(i + 1, j, c, i1, j1, i2, j2);
    if (j > j1 && img[i][j - 1] - 'A' == c && !beenthere[i][j - 1])
        visit(i, j - 1, c, i1, j1, i2, j2);
    if (j < j2 && img[i][j + 1] - 'A' == c && !beenthere[i][j + 1])
        visit(i, j + 1, c, i1, j1, i2, j2);
}

bool is_PCL(int i1, int j1, int i2, int j2) {
    int num_colors = 0;
    int color_count[26] = {0};
    for (int i = i1; i <= i2; i++)
        for (int j = j1; j <= j2; j++)
            beenthere[i][j] = false;
    for (int i = i1; i <= i2; i++)
        for (int j = j1; j <= j2; j++)
            if (!beenthere[i][j]) {
                int c = img[i][j] - 'A';
                if (color_count[c] == 0) num_colors++;
                color_count[c]++;
                visit(i, j, c, i1, j1, i2, j2);
            }
    if (num_colors != 2) return false;
    bool found_one = false, found_many = false;
    for (int i = 0; i < 26; i++) {
        if (color_count[i] == 1) found_one = true;
        if (color_count[i] > 1) found_many = true;
    }
    return found_one && found_many;
}

// is x in y?
bool PCL_in_PCL(int x, int y) {
    return V[x].i1 >= V[y].i1
           && V[x].i2 <= V[y].i2
           && V[x].j1 >= V[y].j1
           && V[x].j2 <= V[y].j2;
}

bool PCL_maximal(int x) {
    for (int i = 0; i < V.size(); i++)
        if (i != x && PCL_in_PCL(x, i)) return false;
    return true;
}

int main(void) {
    ifstream fin("where.in");
    ofstream fout("where.out");
    fin >> N;
    for (int i = 0; i < N; i++)
        fin >> img[i];
    for (int i1 = 0; i1 < N; i1++) {
        for (int j1 = 0; j1 < N; j1++) {
            for (int i2 = i1; i2 < N; i2++) {
                for (int j2 = j1; j2 < N; j2++) {
                    if (is_PCL(i1, j1, i2, j2)) {
                        PCL p = {i1, j1, i2, j2};
                        V.push_back(p);
                        cout << p.i1 << " " << p.i2 << " " << p.j1 << " " << p.j2 << "\n";
                    }
                }
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < V.size(); i++)
        if (PCL_maximal(i)) answer++;
    fout << answer << "\n";
    return 0;
}