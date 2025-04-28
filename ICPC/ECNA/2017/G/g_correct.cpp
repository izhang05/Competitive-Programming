#include <iostream>
#include <vector>

using namespace std;

int MAX_CALORIES;

// Max calories from position i to the end
// We've been eating for m hours straight
// Rest is whether we rested (instead of eating) last hour
int Solve(const vector<int> &calories, vector<vector<vector<int> > > &Memo, int i, int m, int rest) {
    if (i >= calories.size())
        return 0;
    if (Memo[i][m][rest] != -1)
        return Memo[i][m][rest];
    int calories_this_hour = MAX_CALORIES;
    for (int j = 0; j < m; j++)
        calories_this_hour = calories_this_hour * 2 / 3;
    int eat = min(calories[i], calories_this_hour);

    eat = eat + Solve(calories, Memo, i + 1, m + 1, 0);

    int new_m;
    if (rest == 0)
        new_m = max(m - 1, 0);
    else
        new_m = 0;
    int stop = Solve(calories, Memo, i + 1, new_m, 1);
    int best = max(eat, stop);
    Memo[i][m][rest] = best;
    return best;
}

int main() {
    int n;
    cin >> n;
    cin >> MAX_CALORIES;
    vector<int> calories(n);
    for (int i = 0; i < n; i++)
        cin >> calories[i];

    vector<vector<vector<int> > > Memo(n);
    for (int i = 0; i < Memo.size(); i++) {
        Memo[i].resize(n + 1);
        for (int j = 0; j <= n; j++)
            Memo[i][j].resize(2, -1);
    }

    int best = Solve(calories, Memo, 0, 0, 1);
    cout << best << endl;

    return 0;
}
