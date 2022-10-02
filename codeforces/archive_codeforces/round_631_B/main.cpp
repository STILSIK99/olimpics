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

int check (v_i &mas, ll len)
{
    v_i mm1 (len, 0), mm2 (mas.size() - len, 0);
    forin (0, len) {
        if (mas[i] - 1 >= mm1.size()) return 0;
        mm1[mas[i] - 1]++;
    }
    forin (len, mas.size()) {
        if (mas[i] - 1 >= mm2.size()) return 0;
        mm2[mas[i] - 1]++;
    }
    forin (0, mm1.size()) {
        if (mm1[i] != 1) return 0;
    }
    forin (0, mm2.size()) {
        if (mm2[i] != 1) return 0;
    }
    return 1;
}

void solve()
{
    ll n;
    cin >> n;
    v_i mas (n);
    int mmax = -1;
    forin (0, n) {
        cin >> mas[i];
        mmax = max (mas[i], mmax);
    }
    if (mmax > n) {
        cout << 0 << "\n";
        return;
    } else  {
        ll ans = check (mas, mmax) * 2 + check (mas, mas.size() - mmax);
        if (mmax == (mas.size() - mmax)) ans = max (0ll, --ans);
        if (ans == 3) cout << "2\n" << mmax << " " << mas.size() - mmax  << "\n" << mas.size() - mmax  << " " << mmax  << "\n";
        if (ans == 2) cout << "1\n" << mmax << " " << mas.size() - mmax  << "\n";
        if (ans == 1) cout << "1\n" << mas.size() - mmax << " " << mmax  << "\n";
        if (ans == 0) cout << "0\n";
    }
}

int main()
{
    //speed;
    ll t;
    cin >> t;
    forin (0, t) {
        //        while (true)
        solve();
    }
    return 0;
}
