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
        vector<int> towers;
        for (int i = 0; i < n; ++i) {
            int z; cin >> z;
            int low = 0, high = (int)towers.size();
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (towers[mid] > z) high = mid;
                else low = mid + 1;
            }
            if (low == (int)towers.size()) towers.push_back(z);
            else towers[low] = z;
        }
        cout << (int)towers.size() << endl;
    }
    return 0;
}
