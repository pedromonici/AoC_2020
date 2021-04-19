#include <bits/stdc++.h>

using namespace std;

#define PART_2

void read_input(vector<vector<char>>& input) {
    string line;
    while (getline(cin, line)) {
        vector<char> temp_line;
        for (char& c : line) {
            temp_line.push_back(c);
        }
        input.push_back(temp_line);
    }
}

int count_num_trees(vector<vector<char>>& map, int right, int down) {
    int num_trees = 0;
    int y = 0, x = 0;

    while (y < map.size()) {
        if (map[y][x] == '#') {
            num_trees++;
        }
        y += down;
        x += right;

        if (x >= map[y].size()) {
            x -= map[y].size();
        }
    }

    return num_trees;
}

int main() {
    vector<vector<char>> map;
    read_input(map);

#ifdef PART_1
    cout << count_num_trees(map, 3, 1) << endl;
#endif

#ifdef PART_2
    long long ans = 1;
    ans *= count_num_trees(map, 1, 1);
    ans *= count_num_trees(map, 3, 1);
    ans *= count_num_trees(map, 5, 1);
    ans *= count_num_trees(map, 7, 1);
    ans *= count_num_trees(map, 1, 2);

    cout << ans << endl;
#endif

    return 0;
}
