#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void demHangHoa(unordered_map<string, int>& kiem_ke, int n) {
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        kiem_ke[temp]++;
    }
}

vector<pair<string, int>> sapXepHangHoa(unordered_map<string, int>& kiem_ke) {
    vector<pair<string, int>> hang_hoa(kiem_ke.begin(), kiem_ke.end());

    sort(hang_hoa.begin(), hang_hoa.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        if (a.first.length() != b.first.length()) {
            return a.first.length() < b.first.length();
        }
        return a.first < b.first;
        });

    return hang_hoa;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    unordered_map<string, int> kiem_ke;
    demHangHoa(kiem_ke, n);

    vector<pair<string, int>> hang_hoa = sapXepHangHoa(kiem_ke);

    for (const auto& a : hang_hoa) {
        cout << a.first << " " << a.second << "\n";
    }

    return 0;
}