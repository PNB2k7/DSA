#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int f = 1e9;

int convert(const string &s, const vector<int> &res) {
    int num = 0;
    for (int idx : res) {
        num = num * 10 + (s[idx] - '0');
    }
    return num;
}

void cal(const vector<string> &v, vector<int> &pos, vector<int> &res) {
    // Điều kiện dừng: Đã chọn đủ K vị trí cột
    if (res.size() == pos.size()) {
        int mi = 1e9, ma = -1;
        for (const string &s : v) {
            int num = convert(s, res);
            mi = min(mi, num);
            ma = max(ma, num);
        }
        f = min(f, ma - mi);
        return;
    }

    // Quay lui sinh hoán vị
    for (int i = 0; i < pos.size(); i++) {
        if (pos[i] == 0) {
            pos[i] = 1;
            res.push_back(i);

            cal(v, pos, res);

            pos[i] = 0;
            res.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> pos(k, 0);
    vector<int> res;

    cal(v, pos, res);

    cout << f << "\n";
}