/*

To compile the generator, run the following line:
    g++ -O2 --std=c++17 -o generator generator.cpp

To generate a test case:
    ./generator SEED

To generate a test case and save it to a file:
    ./generator SEED > test.txt

The SEED should be a non-negative integer.

For example:
    ./generator 123 > test.txt

*/

#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <vector>
using namespace std;

void generate(int seed) {
    mt19937 gen(seed);
    uniform_real_distribution<double> dis01(0.0, 1.0);

    const int N = 1000;
    const int M = 75;
    const vector<int> all_L = {1024, 2048, 4096, 8192, 32768};
    int L = all_L[uniform_int_distribution<int>(0, all_L.size() - 1)(gen)];
    int D = 0, E = 0;


    vector<pair<int, int>> edge_pairs;
    for (int u = 1; u <= 100; ++u) {
        for (int v = u + 1; v <= 100; ++v) {
            edge_pairs.emplace_back(u, v);
        }
    }
    shuffle(edge_pairs.begin(), edge_pairs.end(), gen);

    vector<pair<int, int>> all_directed_edge;
    for (int u = 1; u <= 100; ++u) {
        for (int v = 1; v <= 100; ++v) {
            if (u != v) {
                all_directed_edge.emplace_back(u, v);
            }
        }
    }
    shuffle(all_directed_edge.begin(), all_directed_edge.end(), gen);

    vector<vector<int>> memories;
    for (int i = 0; i < N; ++i) {
        int factor = max(1, N / uniform_int_distribution<int>(2, 20)(gen));
        int l_i = max(1, uniform_int_distribution<int>(L / 2, L - 1)(gen) / factor);
        int r_i = uniform_int_distribution<int>(900, 1000)(gen);

        vector<int> mem = {l_i, r_i};
        vector<int> facts_contained;

        for (int fact = 1; fact <= 100; ++fact) {
            facts_contained.push_back(fact);
        }
        
        shuffle(facts_contained.begin(), facts_contained.end(), gen);

        while (facts_contained.size() > 10) {
            facts_contained.pop_back();
        }

        shuffle(facts_contained.begin(), facts_contained.end(), gen);

        mem.push_back(facts_contained.size());
        mem.insert(mem.end(), facts_contained.begin(), facts_contained.end());
        memories.push_back(mem);
    }

    vector<pair<int, int>> dependency;
    for (const auto& e : all_directed_edge) {
        if (dis01(gen) < 0.008) {
            dependency.push_back(e);
        }
    }
    while (dependency.size() > 100) {
        dependency.pop_back();
    }
    D = dependency.size();

    vector<pair<int, int>> mutex;
    set<pair<int, int>> dep_set(dependency.begin(), dependency.end());
    for (const auto& e : edge_pairs) {
        if (dis01(gen) < 0.016) {
            if (dep_set.find(e) == dep_set.end() && dep_set.find({e.second, e.first}) == dep_set.end()) {
                mutex.push_back(e);
            }
        }
    }
    while (mutex.size() > 100) {
        mutex.pop_back();
    }
    E = mutex.size();

    vector<vector<int>> queries;
    for (int i = 0; i < M; ++i) {
        vector<int> query;
        for (int fact = 1; fact <= 100; ++fact) {
            query.push_back(fact);
        }
        shuffle(query.begin(), query.end(), gen);
        while (query.size() > 10) {
            query.pop_back();
        }
        query.insert(query.begin(), query.size());
        queries.push_back(query);
    }

    cout << N << " " << M << " " << L << " " << D << " " << E << "\n";

    for (const auto& mem : memories) {
        for (size_t j = 0; j < mem.size(); ++j) {
            cout << mem[j];
            if (j < mem.size() - 1) cout << " ";
        }
        cout << "\n";
    }

    for (const auto& e : dependency) {
        cout << e.first << " " << e.second << "\n";
    }

    for (const auto& e : mutex) {
        cout << e.first << " " << e.second << "\n";
    }

    for (const auto& query : queries) {
        for (size_t j = 0; j < query.size(); ++j) {
            cout << query[j];
            if (j < query.size() - 1) cout << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: <program> seed" << endl;
        return 0;
    }
    string seed_str = argv[1];
    for(char c : seed_str){
        if (c < '0' || c > '9') {
            cout << "Seed should be an integer. Your seed contains the character " << c << ", which is not a digit." << endl;
            return 0;
        }
    }
    long long seed = 0;
    const long long mod = 1e9 + 7;
    for(char c : seed_str){
        seed = (seed * 10 + (c - '0')) % mod;
    }
    generate(seed);
    return 0;
}
