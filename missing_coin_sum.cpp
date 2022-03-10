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
        }
        sort(a.begin(), a.end());
        ll curr = 0;
        for (int x: a) {
            if (curr + 1 < x) break;
            curr += x;
        }
        cout << curr + 1 << endl;
    }
    return 0;
}
