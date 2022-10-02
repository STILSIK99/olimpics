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


ld gip (p_ll a, p_ll &b)
{
    return max (ld (0.), abs (sqrt (ld (abs (a.first - b.first) * abs (a.first - b.first) + abs (a.second - b.second) * abs (a.second - b.second)))));
}

ld distance_to_finish (p_ll a, ll rad, p_ll finish)
{
    ll x = finish.first,
       y = finish.second,
       left = min (0ll, x),
       right = max (0ll, x),
       up = max (0ll, y),
       down = min (0ll, y);
    ld ans = 1e11;
    if (a.first >= left && a.first <= right && a.second >= down && a.second <= up) return 0.;
    ans = min (ans, gip (mp (right, up), a) - rad);
    ans = min (ans, gip (mp (right, down), a) - rad);
    ans = min (ans, gip (mp (left, up), a) - rad);
    ans = min (ans, gip (mp (left, down), a) - rad);
    if (a.first >= left && a.first <= right) {
        ans = min (ans, ld (abs (a.second - up)));
        ans = min (ans, ld (abs (a.second - down)));
    }
    if (a.second <= up && a.second >= down) {
        ans = min (ans, ld (abs (a.first - left)));
        ans = min (ans, ld (abs (a.first - right)));
    }
    return max (ans, ld (0));
}


ld Dijkstra (vector<vector<pair<ll, ld>>> &matr, ll start, ll finish)
{
    ll n = matr.size();
    vector <ld> lengths (n, INF);
    lengths[start] = ld (0.);
    set<pair<ld, ll>> mas;
    mas.insert (mp (lengths[start], start));
    while (!mas.empty()) {
        ll v = mas.begin()->second;
        ld len = mas.begin()->first;
        mas.erase (mas.begin());
        for (auto x : matr[v]) {
            ll n_v = x.first;
            ld n_len = len + x.second;
            if (lengths[n_v] > n_len) {
                mas.erase (mp (lengths[n_v], n_v));
                lengths[n_v] = n_len;
                mas.insert (mp (n_len, n_v));
            }
        }
    }
    return lengths[finish];
}



void solve()
{
    ll n_tree;
    p_ll start, finish;
    cin >> finish.first >> finish.second >> start.first >> start.second >> n_tree;
    vp_ll mas (n_tree + 2);
    vector<vector<pair<ll, ld>>> matrix (n_tree + 2, vector<pair<ll, ld>>());
    mas[0] = start;
    mas[1] = finish;
    v_i rad (n_tree + 2);
    rad[0] = 0;
    rad[1] = 0;
    forin (0, n_tree) {
        cin >> get<0> (mas[i + 2]) >> get<1> (mas[i + 2]) >> rad[i + 2];
    }
    forin (0, n_tree + 2) {
        if (i == 1) continue;
        forjn (0, n_tree + 2) {
            if (i == j) continue;
            ld dist = 0.;
            if (j == 1) dist = distance_to_finish (mas[i], rad[i], finish);
            else dist = max (ld (0.), gip (mas[i], mas[j]) - rad[i] - rad[j]);
            matrix[i].push_back (mp (j, dist));
        }
    }

    //    cout << "ans - ";
    cout << setprecision (10) << Dijkstra (matrix, 0, 1);
    cout << "\n";
}

int main()
{
    //speed;
    //    forin (0, 17) {
    while (true) {
        solve();
        break;
    }
    return 0;
}
