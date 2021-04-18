#include <bits/stdc++.h>

using namespace std;

#define PART_2

void read_input(vector<string>& input) {
    string line;
    while (getline(cin, line)) {
        input.push_back(line);
    }
}

vector<tuple<string, char, int, int>> parse_passwords(vector<string> &input) {
    vector<tuple<string, char, int, int>> ans;
    for (auto line : input) {
        int start_passwd_index = line.find(":") + 2;
        string password = line.substr(start_passwd_index, line.size() - start_passwd_index);

        int end_min_freq = line.find("-");
        int min_freq = stoi(line.substr(0, end_min_freq));

        int end_max_freq = line.find(" ");
        int max_freq = stoi(line.substr(end_min_freq + 1, end_max_freq - end_min_freq));

        char letter_verify = line[end_max_freq + 1];

        ans.push_back(make_tuple(password, letter_verify, min_freq, max_freq));
    }

    return ans;
}

void part_one(vector<tuple<string, char, int, int>>& data) {
    int valid_ones = 0;
    for (int i = 0; i < data.size(); i++) {
        if (count(get<0>(data[i]).begin(), get<0>(data[i]).end(), get<1>(data[i])) >= get<2>(data[i]) &&
            count(get<0>(data[i]).begin(), get<0>(data[i]).end(), get<1>(data[i]))<= get<3>(data[i])) {
            valid_ones++;
        }
    }

    cout << valid_ones << endl;
}

void part_two(vector<tuple<string, char, int, int>>& data) {
    int valid_ones = 0;
    for (int i = 0; i < data.size(); i++) {
        if (get<0>(data[i])[get<2>(data[i]) - 1] == get<1>(data[i]) &&
            get<0>(data[i])[get<3>(data[i]) - 1] != get<1>(data[i])) {
            valid_ones++;
        }
        if (get<0>(data[i])[get<2>(data[i]) - 1] != get<1>(data[i]) &&
            get<0>(data[i])[get<3>(data[i]) - 1] == get<1>(data[i])) {
            valid_ones++;
        }
    }

    cout << valid_ones << endl;
}

int main() {
    vector<string> input;
    read_input(input);

    vector<tuple<string, char, int, int>> data = parse_passwords(input);

#ifdef PART_1
    part_one(data);
#endif
#ifdef PART_2
    part_two(data);
#endif

    return 0;
}
