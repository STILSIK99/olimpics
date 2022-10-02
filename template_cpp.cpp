#include <bits/stdc++.h>

using  namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> v_ll;
typedef vector<int> v_i;
typedef pair<ll, ll> p_ll;
typedef pair<int, int> p_ii;
typedef vector<pair<ll, ll>> vp_ll;



#define forina(a,n) for (auto i = a; i != n; ++i)
#define forin(a,n) for (ll i = a; i < n; ++i)
#define forins(a,n,s) for (ll i = a; i < n; i+=s)
#define forjn(a,n) for (ll j = a; j < n; ++j)
#define forni(n,a) for (ll i = n; i >= a; --i)
#define speed ios::sync_with_stdio (0);cin.tie (0);cout.tie(0)

const int INF = 1e9;
const ll minn = -1e18;
const ll maxx = 1e18;

vector<ll> simple_numbers (ll n)
{
    vector<ll> ans;
    vector<bool> used (n, false);
    forjn (2, n) {
        if (used[j] == false) {
            ans.push_back (j);
            forins (j + j, n, j) {
                used[i] = true;
            }
        }
    }
    return ans;
}

template <class T>
ll bin_search_upper (const v_ll &mas, T n)
{
    ll left = 0;
    ll right = mas.size() - 1;
    while (left < right) {
        ll middle = (left + right) / 2;
        if (mas[middle] < n) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

template <class T>
ll bin_search_lower (const v_ll &mas, T n)
{
    ll left = 0;
    ll right = mas.size() - 1;
    while (left < right) {
        ll middle = (left + right) / 2. + 0.5;
        if (mas[middle] > n) {
            right = middle - 1;
        } else {
            left = middle;
        }
    }
    return left;
}

ll Dijkstra (vector<vector<pair<int, int>>> &matrix, ll start, ll finish)
{
    int n = matrix.size();
    vector<int> lengths (n, INF),  p (n);
    lengths[start] = 0;
    set < pair<int, int> > mas;
    mas.insert (make_pair (lengths[start], start));
    while (!mas.empty()) {
        int v = mas.begin()->second, len = mas.begin()->first;
        mas.erase (mas.begin());
        if (len > lengths[v]) continue;
        forin (0, matrix[v].size()) {
            int n_v = matrix[v][i].first, n_len = len;
            char llen = len % 7;
            if (llen > matrix[v][i].second) n_len += matrix[v][i].second + 7 - llen + 1;
            else n_len += matrix[v][i].second - llen + 1;
            if (lengths[n_v] > n_len) {
                mas.erase (make_pair (lengths[n_v], n_v));
                lengths[n_v] = n_len;
                mas.insert (make_pair (n_len, n_v));
            }
        }
    }
    return lengths[finish];
};

void change_line (string &str, ll left, ll right)
{
    forin (0, (left + right) / 2 + 1 - left) {
        swap (str[left + i], str[right - i]);
    }
}
 
void solve()
{
    ll n, x;
    cin >> n >> x;

}
 
int main()
{
    //speed;
    ll t;
    cin >> t;
    forin (0, t) {
    while (true)
        solve();
    }
    return 0;
}
