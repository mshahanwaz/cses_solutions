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
        int a = 1, b = 0;
        while (n) {
            for (int i = 2; i <= n; i += 2) {
                cout << a * i + b << ' ';
            }
            if (n & 1)
                cout << a + b << ' ', b += a;
            else b -= a;
            a <<= 1;
            n >>= 1;
        }
    }
    return 0;
}   
