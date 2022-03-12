#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'
#define fastIO cin.tie(0)->sync_with_stdio(0)

int main() {
    fastIO;
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, int> freq;
        int i = 0, j = 0, max_len = 0, curr_len = 0;
        while (j < n) {
            if (freq[a[j]] == 0) {
                freq[a[j]] = 1;
                ++curr_len;
                max_len = max(max_len, curr_len);
                ++j;
            } else {
                --curr_len;
                --freq[a[i]];
                ++i;
            }
        }
        cout << max_len << endl;
    }
    return 0;
}
