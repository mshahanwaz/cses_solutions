#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(pair<int, int> x, pair<int, int> y) {
    return x.second < y.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> time(n);
    for (auto &x: time) {
        cin >> x.first >> x.second;
    }
    sort(time.begin(), time.end(), cmp);
    int prev = time[0].second, cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (prev <= time[i].first) {
            ++cnt;
            prev = time[i].second;
        }
    }
    cout << cnt << endl;
    return 0;
}
