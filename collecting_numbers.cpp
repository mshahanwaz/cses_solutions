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
        for (int &x: a) {
            cin >> x;
            --x;
        }
        int cnt = 1;
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            b[a[i]] = i;
        }
        for (int i = 1; i < n; ++i) {
            cnt += b[i - 1] > b[i];
        }
        cout << cnt << endl;
    }
    return 0;
}
