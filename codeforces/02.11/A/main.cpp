#include <bits/stdc++.h>

using  namespace std;

typedef long long ll;
typedef double ld;
typedef vector<ll> v_ll;
typedef vector<int> v_i;
typedef pair<ll, ll> p_ll;
typedef pair<int, int> p_ii;
typedef vector<pair<ll, ll>> vp_ll;
typedef vector<tuple<ll, ll, ll>> vt_ll;



#define forina(a,n) for (auto i = a; i != n; ++i)
#define forin(a,n) for (ll i = a; i < n; ++i)
#define forins(a,n,s) for (ll i = a; i < n; i+=s)
#define forjn(a,n) for (ll j = a; j < n; ++j)
#define forni(n,a) for (ll i = n; i >= a; --i)
#define speed ios::sync_with_stdio (0);cin.tie (0);cout.tie(0)
#define mp make_pair

const int INF = 1e9;
const ll minn = -1e18;
const ll maxx = 1e18;


ll bin_search (ll n)
{
    ll l = 0, r = 1e6;
    while (l < r) {
        ll middle = (l + r) / 2;
        if ((middle + 1)*middle / 2 < n) {
            l = middle + 1;
        } else r = middle;
    }
    return r;
}

bool check (vector<ll> &mas)
{
    ll ans = 0;
    forin (1, mas.size()) {
        if (mas[i] < mas[i - 1]) return false;
    }
    return true;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    string posl;
    cin >> posl;
    p_ll a (1, 1), b (m, 1), c (1, n), d (m, n);
    vp_ll mm{a, b, c, d};
    set<pair<p_ll, int>> mas;
    mas.insert (mp (a, 0));
    mas.insert (mp (b, 1));
    mas.insert (mp (c, 2));
    mas.insert (mp (d, 3));
    forin (0, posl.size()) {
        auto xx = mas.begin();
        if (posl[i] == 'L') {
            for (auto x : mas)
                x.first.first--;
        }
        if (posl[i] == 'R') {
            for (auto x : mas)
                x.first.first++;
        }
        if (posl[i] == 'U') {
            for (auto x : mas)
                x.first.second--;
        }
        if (posl[i] == 'D') {
            for (auto x : mas)
                x.first.second--;
        }
        for (auto x : mas) {
            if (x.first.first < 1 || x.first.first > m) {
                mas.erase (x);
                break;
            }
            if (x.first.second < 1 || x.first.second > n) {
                mas.erase (x);
                break;
            }
        }
        if (mas.empty()) {
            cout << mm[xx->second].first << " " << mm[xx->second].second << "\n";
            return;
        }

    }
    cout << mm[mas.begin()->second].first << " " << mm[mas.begin()->second].second  << "\n";

}

int main()
{
    //    speed;
    ll t;
    cin >> t;
    forin (0, t) {
        solve();
    }
    return 0;
}














