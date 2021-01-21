#include <vector>
#include <iostream>

int construct(std::vector<std::vector<int>> p);
void build(std::vector<std::vector<int>> b) {
    int n = b.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j) {
                std::cout << " ";
            }
            std::cout << b[i][j];
        }
        std::cout << "\n";
    }
};
