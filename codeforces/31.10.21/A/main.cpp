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

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> mas (n);
    forin (0, n) {
        cin >> mas[i];
    }
    ll ans = 0;
    forin (1, n) {
        if (mas[i] < mas[i - 1]) ++ans;
    }
    if (ans == 0) {
        cout << 0 << "\n";
        return;
    }
    ans = 0;
    forin (0, n - 1) {
        if (mas[i] > x) {
            swap (x, mas[i]);
            ++ans;
        } else if (mas[i] > mas[i + 1]) {
            cout << "-1\n";
            return;
        }
    }
    if (mas[n - 1] < mas[n - 2] && (x < mas[n - 2] || x > mas[n - 1])) {
        cout << "-1\n";
        return;
    }
    cout << ans << "\n";
}

int main()
{
    //speed;
    ll t;
    cin >> t;
    forin (0, t) {
        solve();
    }
    return 0;
}
