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
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1), pos(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        int ans = 1;
        for (int i = 1; i < n; ++i)
            ans += pos[i] > pos[i + 1];
        int l, r;
        while (m--) {
            cin >> l >> r;
            set<pair<int, int>> upd;
            if (a[l] + 1 <= n)
                upd.insert({a[l], a[l] + 1});
            if (a[l] - 1 >= 1)
                upd.insert({a[l] - 1, a[l]});
            if (a[r] + 1 <= n) 
                upd.insert({a[r], a[r] + 1});
            if (a[r] - 1 >= 1)
                upd.insert({a[r] - 1, a[r]});
            for (auto swapped: upd)
                ans -= pos[swapped.first] > pos[swapped.second];
            swap(a[l], a[r]);
            pos[a[l]] = l;
            pos[a[r]] = r;
            for (auto swapped: upd)
                ans += pos[swapped.first] > pos[swapped.second];
            cout << ans << endl;
        }
    }
    return 0;
}
