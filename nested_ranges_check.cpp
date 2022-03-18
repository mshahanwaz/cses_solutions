#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 4e5 + 5;
ll num1 = 0, num2 = 0;
ll bit1[N + 5];
ll  bit2[N + 5];
 
bool custom(pair<pair<ll, ll> , pair<ll, ll> > x , pair<pair<ll, ll> , pair<ll, ll> > y ) {
	if (x.first.first != y.first.first) {
		return x.first.first < y.first.first;
	}
	if (x.first.second != y.first.second) {
		return x.first.second < y.first.second;
	}
	return x.second.first > y.second.first;
}
 
void update(ll ind) {
	while (ind <= num1) {
		bit1[ind] ++;
		ind += (ind & (-ind));
	}
}
 
ll query(ll ind) {
	ll sum = 0;
	while (ind > 0) {
		sum += bit1[ind];
		ind -= (ind & (-ind));
	}
	return sum;
}
void update_2(ll ind) {
	while (ind <= num1) {
		bit2[ind] ++;
		ind += (ind & (-ind));
	}
}
 
ll query_2(ll ind) {
	ll sum = 0;
	while (ind > 0) {
		sum += bit2[ind];
		ind -= (ind & (-ind));
	}
	return sum;
}
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a;
	cin >> a;
	unordered_map<ll, ll> x;
	set<ll> y;
	vector<pair<ll, ll> > z;
	for (ll i = 0; i < a; i++) {
		ll p, q;
		cin >> p >> q;
		y.insert(p);
		y.insert(q);
		z.push_back({p, q});
	}
	ll prev1 = -1 , prev2 = -1;
	for (auto i : y) {
		if (prev1 != i) {
			num1++;
		};
		x[i] = num1;
		prev1 = i;
	}
	vector < pair<pair<ll, ll> , pair<ll, ll> > > u;
	for (ll i = 0; i < a; i++) {
		ll p = x[z[i].first], q = x[z[i].second];
		u.push_back({{p, 0}, {q, i}});
		u.push_back({{q, 1}, {p, i}});
	}
	sort(u.begin(), u.end(), custom);
	ll arr1[a] = {0}, arr2[a] = {0};
	for (auto i : u) {
		if (i.first.second == 0) {
			arr2[i.second.second] = query(num1) - query(i.second.first - 1);
			update(i.second.first);
		}
		else {
			arr1[i.second.second] = query_2(i.first.first) - query_2(i.second.first - 1);
			update_2(i.second.first);
		}
	}
	for (auto i : arr1) {
		cout << i << " ";
	}
	cout << "\n";
	for (auto i : arr2) {
		cout << i << " ";
	}
}
