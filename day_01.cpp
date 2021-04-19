#include <bits/stdc++.h>

using namespace std;

#define TARGET 2020
#define PART_2

void read_input(vector<int>& input) {
    string line;
    while (getline(cin, line)) {
        input.push_back(stoi(line));
    }
}

int main() {
    vector<int> input;
    read_input(input);

    sort(input.begin(), input.end());

#ifdef PART_1
    int start = 0;
    int end = input.size() - 1;
    while (start <= end) {
        int sum = input[start] + input[end];

        if (sum == TARGET) {
            cout << input[start] << " " << input[end] << " " << input[start] * input[end] << endl;
            return 0;
        } else if (sum < TARGET) {
            start++;
        } else if (sum > TARGET) {
            end--;
        }
    }
#endif

#ifdef PART_2
    for (int i = 0; i < input.size() - 2; i++) {
        if (i == 0 || (i > 0 && input[i] != input[i - 1])) {
            int low = i + 1, high = input.size() - 1;
            while (low < high) {
                int complement_sum = TARGET - input[i];

                if (input[low] + input[high] == complement_sum) {
                    cout << input[low] << " " << input[high] << " " << input[i] << " " << input[low] * input[high] * input[i] << endl;
                    return 0;
                } else if (input[low] + input[high] < complement_sum) {
                    low++;
                } else {
                    high--;
                }
            }
        }
    }
#endif


    return 0;
}
