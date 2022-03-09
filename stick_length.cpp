#include <bits/stdc++.h>
#include <vector>
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
        vector<ll> a(n);
        for (ll &x: a) {
            cin >> x;
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        for (int x: a) {
            ans += abs(x - a[n / 2]);
        }
        cout << ans << endl;
    }
    return 0;
}
