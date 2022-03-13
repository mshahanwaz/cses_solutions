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
        int x, n;
        cin >> x >> n;
        set<int> lights;
        multiset<int> dist;
        lights.insert(0);
        lights.insert(x);
        dist.insert(x);
        for (int i = 0; i < n; ++i) {
            int p;
            cin >> p;
            auto it1 = lights.upper_bound(p);
            auto it2 = it1;
            --it2;
            dist.erase(dist.find(*it1 - *it2));
            dist.insert(p - *it2);
            dist.insert(*it1 - p);
            lights.insert(p);
            auto ans = dist.end();
            --ans;
            cout << *ans << ' ';
        }
        cout << endl;
    }
    return 0;
}
