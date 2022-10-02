/*----------------------------*\
|      written by STILSIK      |
\*----------------------------*/
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

template<typename T>
T bin_pow (T a, int k)
{
    T ans (1);
    T st = a;
    if (k == 1) return ans;
    while (k != 0) {
        if (k % 2) ans = ans * st;
        st = st * st;
        k /= 2;
    }
    return ans;
}

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

template <class T, class X>
ll bin_search_upper (const vector<X> &mas, T n)
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

template <class T, class X>
ll bin_search_lower (const vector<X> &mas, T n)
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
template <class L, class V>
//V - вершина, L - расстояние
L Dijkstra (vector<vector<pair<V, L>>> &matrix, V start, V finish)
{
    int n = matrix.size();
    vector<L> lengths (n, INF),  p (n);
    lengths[start] = 0;
    set < pair<V, L> > mas;
    mas.insert (make_pair (lengths[start], start));
    while (!mas.empty()) {
        V v = mas.begin()->second;
        L len = mas.begin()->first;
        mas.erase (mas.begin());
        if (len > lengths[v]) continue;
        forin (0, matrix[v].size()) {
            V n_v = matrix[v][i].first;
            L n_len = len + matrix[v][n_v];
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

ll gcd (ll a, ll b)
{
    return b ? gcd (b, a % b) : a;
}

bool check (vector<int> &a, ll l, ll r, ll del)
{

    while (true) {
        bool fl = false;
        if (l >= r) break;
        if (a[l] == del) {
            ++l;
            fl = true;
        }
        if (a[r] == del) {
            --r;
            fl = true;
        }
        if (fl) continue;
        if (a[l++] != a[r--]) return false;
    }
    return true;
}

struct guest {
    int x;
    int y;
    int d;

    guest (int a, int b, int d): x (a), y (b), d (d) {};

};
bool men (const guest &b, const guest &a)
{
    if (b.x + b.y == a.x + a.y) return b.d > a.d;
    else {
        return b.x + b.y > a.x + a.y;
    }
}

bool cmp (pair<int, int> &a, pair<int, int> &b)
{
    return a.first + a.second > b.first;
}

bool check (set<guest> &mas)
{
}

void solve()
{
    ll count;
    cin >> count;
    vector<pair<int, int>> mass (count);
    set<int>xp;
    ll i = 0;
    ll ans = 0;
    forin (0, count) {
        cin >> mass[i].first >> mass[i].second;
    }
    forin (0, count) {
        vector<int> del;
        ll sum (mass[i].first + mass[i].second);
        xp.insert (i);
        bool fl = true;
        for (auto f : xp) {
            ll kk = distance (xp.begin(), xp.upper_bound (f));
            if (kk - 1 - del.size() > mass[f].second || (xp.size() - kk > mass[f].first)) {
                if (mass[f].first + mass[f].second < sum || mass[f].first < mass[i].first) {
                    del.push_back (f);
                } else {
                    xp.erase (i);
                    fl = false;
                    break;
                }
            }
        }
        if (fl) {
            forin (0, del.size()) xp.erase (del[i]);
        }
    }
    cout << xp.size() << "\n";
}



int main()
{
    speed;
    ll t = 1;
    cin >> t;
    while (t-- > 0) {
        solve();
        //        break;
    }
    return 0;
}
