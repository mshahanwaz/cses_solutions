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
        // ll n, x;
        // cin >> n >> x;
        // vector<ll> a(n);
        // map<ll, ll> mp;
        // for (ll &y: a) {
        //     cin >> y;
        // }
        // for (ll i = 0; i < n; ++i) {
        //     if (mp.count(x - a[i])) {
        //         cout << mp[x - a[i]] << ' ' << i + 1 << endl;
        //         return 0;
        //     }
        //     mp[a[i]] = i + 1;
        // }
        // cout << "IMPOSSIBLE\n";
        ll n, x;
        cin >> n >> x;
        vector<pair<int, int>> a(n);
        int i = 0;
        for (auto &p: a) {
            cin >> p.first;
            p.second = ++i;
        }
        sort(a.begin(), a.end());
        int l = 0, r = n - 1;
        while (l < r) {
            if (a[l].first + a[r].first < x) ++l;
            else if (a[l].first + a[r].first > x) --r;
            else {
                cout << a[l].second << ' ' << a[r].second << endl;
                return 0;
            }
        }
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
