#include <bits/stdc++.h>
#include <ostream>

using namespace std;

struct cell {
    int richness;
    array<int, 6> adj;
};

struct tree {
    friend ostream &operator<<(ostream &os, const tree &tree);
    int ind, size;
    bool mine, dormant;
};
ostream &operator<<(ostream &os, const tree &tree) {
    os << "ind: " << tree.ind << " size: " << tree.size << " mine: " << tree.mine << " dormant: " << tree.dormant;
    return os;
}

vector<cell> cells;
bool action = false;
int day;             // the game lasts 24 days: 0-23
int nutrients;       // the base score you gain from the next COMPLETE action
int sun;             // your sun points
int score;           // your current score
int opp_sun;         // opponent's sun points
int opp_score;       // opponent's score
bool opp_is_waiting; // whether your opponent is asleep until the next day
int m;               // the current amount of trees
int cnt[4];
vector<tree> trees;

bool grow(tree cur) {
    cerr << "grow: " << cur.ind << "\n";
    if (cur.size == 3 || !cur.mine || cur.dormant) {
        return false;
    }
    cerr << "grow: " << cur.ind << "\n";
    int new_sun;
    if (cur.size == 2) {
        new_sun = sun - (7 + cnt[3]);
    } else if (cur.size == 1) {
        new_sun = sun - (3 + cnt[2]);
    }
    if (new_sun >= 0) {
        sun = new_sun;
        --cnt[cur.size];
        ++cnt[++cur.size];
        action = true;
        cout << "GROW " << cur.ind << endl;
        cerr << "GROW " << cur.ind << endl;
        return true;
    } else {
        return false;
    }
}

bool complete(tree cur) {
    if (cur.size < 3 || !cur.mine || cur.dormant || sun < 4) {
        return false;
    }
    action = true;
    cout << "COMPLETE " << cur.ind << endl;
    return true;
}

void wait() {
    if (!action) {
        cout << "WAIT" << endl;
    }
}

void next_action() {
    sort(trees.begin(), trees.end(), [](auto left, auto right) {
        return left.size > right.size;
    });
    for (auto &i : trees) {
        cerr << i << "\n";
        if (complete(i)) {
            return;
        }
    }
    for (auto &i : trees) {
        if (grow(i)) {
            return;
        }
    }
    wait();
}

int main() {
    int n; // 37
    cin >> n;
    cells.resize(n);
    for (int i = 0; i < n; i++) {
        int ind;
        cin >> ind;
        cin >> cells[i].richness;
        for (int j = 0; j < 6; ++j) {
            cin >> cells[i].adj[j];
        }
    }
    // game loop
    while (true) {
        cin >> day >> nutrients >> sun >> score >> opp_sun >> opp_score >> opp_is_waiting >> m;
        action = false;
        memset(cnt, 0, sizeof(cnt));
        trees.clear();
        trees.resize(m);
        for (int i = 0; i < m; i++) {
            cin >> trees[i].ind >> trees[i].size >> trees[i].mine >> trees[i].dormant;
            ++cnt[trees[i].size];
        }
        int _; // all legal actions
        cin >> _;
        cin.ignore();
        for (int i = 0; i < _; i++) {
            string __;
            getline(cin, __);
            cerr << __ << "\n";
        }
        next_action();
    }
}
