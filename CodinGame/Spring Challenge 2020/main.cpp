#include <bits/stdc++.h>

using namespace std;

/**
 * Grab the pellets as fast as you can!
 **/

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, maxn = 40, opponent = 1e9, self = 5e8, maxpac = 5;

int grid[maxn][maxn];
int pellets[maxn][maxn];
int height;
int width;
bool activated[maxpac];
pair<int, int> dest[maxpac];
deque<pair<int, int>> last_pos[maxpac];


bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < height && y < width;
}


pair<int, pair<int, int>> best_move(int x, int y, int turns, bool init = true) {
    if (turns == 0) {
        return {0, {x, y}};
    }
    int best_value = -opponent;
    pair<int, int> move;
    for (int i = 0; i < 4; ++i) {
        int cur_x = x + dx[i], cur_y = y + dy[i];
        if (valid(cur_x, cur_y)) {
            int cur_value;
            if (init) {
                if (grid[cur_x][cur_y] == -self) {
                    cur_value = pellets[cur_x][cur_y];
                } else {
                    cur_value = grid[cur_x][cur_y];
                }
            } else {
                cur_value = grid[cur_x][cur_y];
            }
            //            int cur_value = grid[cur_x][cur_y];
            pair<int, pair<int, int>> next = best_move(cur_x, cur_y, turns - 1, false);
            if (next.first <= 0) {
                next = {0, {cur_x, cur_y}};
            }
            cur_value += next.first;
            if (cur_value > best_value) {
                best_value = cur_value;
                move = next.second;
            }
        }
    }
    return {best_value, move};
}


#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

struct pac {
    int id, x, y;
    string type;
    int speed, cooldown;
};

int main() {
    cin >> width >> height;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(0, max(width, height));
    cin.ignore();
    for (int i = 0; i < height; ++i) {
        string row;
        getline(cin, row); // one line of the grid: space " " is floor, pound "#" is wall
        for (int j = 0; j < width; ++j) {
            if (row[j] == '#') {
                grid[i][j] = -1;
            }
        }
    }

    // game loop
    while (true) {
        int myScore;
        int opponentScore;
        cin >> myScore >> opponentScore;
        cin.ignore();
        int visiblePacCount; // all your pacs and enemy pacs in sight
        cin >> visiblePacCount;
        cin.ignore();

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] != -1) {
                    grid[i][j] = 0;
                }
                pellets[i][j] = 0;
            }
        }
        vector<pac> pacmen;
        vector<pair<int, int>> opponents, selves;
        for (int i = 0; i < visiblePacCount; i++) {
            int pacId;           // pac number (unique within a team)
            bool mine;           // true if this pac is yours
            int x;               // position in the grid
            int y;               // position in the grid
            string typeId;       // unused in wood leagues
            int speedTurnsLeft;  // unused in wood leagues
            int abilityCooldown; // unused in wood leagues
            cin >> pacId >> mine >> x >> y >> typeId >> speedTurnsLeft >> abilityCooldown;
            cin.ignore();
            if (mine) {
                pacmen.push_back(pac{pacId, y, x, typeId, speedTurnsLeft, abilityCooldown});
                for (int j = 0; j < 4; ++j) {
                    if (valid(y + dy[j], x + dx[j])) {
                        selves.emplace_back(y + dy[j], x + dx[j]);
                    }
                }
                selves.emplace_back(y, x);
            } else {
                for (int j = 0; j < 4; ++j) {
                    if (valid(y + dy[j], x + dx[j])) {
                        opponents.emplace_back(y + dy[j], x + dx[j]);
                    }
                }
                opponents.emplace_back(y, x);
            }
        }

        int visiblePelletCount; // all pellets in sight
        cin >> visiblePelletCount;
        cin.ignore();
        for (int i = 0; i < visiblePelletCount; i++) {
            int x;
            int y;
            int value; // amount of points this pellet is worth
            cin >> x >> y >> value;
            cin.ignore();
            grid[y][x] = value;
            pellets[y][x] = value;
        }
        for (pair<int, int> i : selves) {
            if (grid[i.first][i.second] < -1) {
                grid[i.first][i.second] -= self;
            } else {
                grid[i.first][i.second] = -self;
            }
        }
        for (pair<int, int> i : opponents) {
            grid[i.first][i.second] = -opponent;
        }

        vector<pair<string, vector<int>>> commands;
        for (const pac &p : pacmen) {
            if (p.cooldown == 0) {
                commands.emplace_back("SPEED", vector<int>{p.id});
                last_pos[p.id].emplace_back(p.x, p.y);
                while (last_pos[p.id].size() > 2) {
                    last_pos[p.id].pop_front();
                }
                activated[p.id] = true;
                continue;
            }
            pair<int, pair<int, int>> next_move;
            if ((last_pos[p.id].front() == make_pair(p.x, p.y) || last_pos[p.id].back() == make_pair(p.x, p.y)) && !activated[p.id]) { // pacmen is in same place pos as last - collision occurred
                dest[p.id] = {distrib(gen), distrib(gen)};
                while (!(valid(dest[p.id].first, dest[p.id].second) && grid[dest[p.id].first][dest[p.id].second] >= 0)) {
                    dest[p.id] = {distrib(gen), distrib(gen)};
                }
                next_move.second = dest[p.id];
            } else {
                if (p.speed) {
                    next_move = best_move(p.x, p.y, 7);
                } else {
                    next_move = best_move(p.x, p.y, 7);
                }
                cerr << next_move.first << " " << next_move.second.first << " " << next_move.second.second << "\n";
                if (next_move.first <= 0) {
                    if ((last_pos[p.id].front() == make_pair(p.x, p.y) || last_pos[p.id].back() == make_pair(p.x, p.y)) && !activated[p.id]) {
                        dest[p.id] = {distrib(gen), distrib(gen)};
                    }
                    while (!(valid(dest[p.id].first, dest[p.id].second) && grid[dest[p.id].first][dest[p.id].second] >= 0)) {
                        dest[p.id] = {distrib(gen), distrib(gen)};
                    }
                    next_move.second = dest[p.id];
                }
            }

            commands.emplace_back("MOVE", vector<int>{p.id, next_move.second.second, next_move.second.first});
            last_pos[p.id].emplace_back(p.x, p.y);
            while (last_pos[p.id].size() > 2) {
                last_pos[p.id].pop_front();
            }
            activated[p.id] = false;
            //            cerr << next_move.second.second << " " << next_move.second.first << "\n";
            //            cerr << grid[next_move.second.first][next_move.second.second] << "\n";
        }
        for (int i = 0; i < commands.size(); ++i) {
            cout << commands[i].first << " ";
            for (int j : commands[i].second) {
                cout << j << " ";
            }
            if (commands[i].first == "MOVE") {
                if (make_pair(commands[i].second[2], commands[i].second[1]) == dest[commands[i].second[0]]) {
                    cout << "R ";
                }
                cout << commands[i].second[1] << " " << commands[i].second[2];
            }
            if (i != commands.size() - 1) {
                cout << " | ";
            } else {
                cout << endl;
            }
        }
    }
}

#pragma clang diagnostic pop